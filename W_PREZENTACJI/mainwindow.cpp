#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ParametryARX.h"
#include "DialogPolaczenie.h"
#include <QSignalBlocker>
#include <QFileDialog>
#include <QLineEdit>
#include <QDebug>
#include <QJsonDocument>
#include <QFile>

static constexpr double DOMYSLNE_OKNO_CZASOWE = 10.0;
static constexpr double MARGINES_Y = 0.1;


MainWindow::MainWindow(QWidget *parent, KlasaUslugowa *usluga)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_usluga(usluga)
    , m_oknoCzasowe(DOMYSLNE_OKNO_CZASOWE)
    , m_serwer(nullptr)
    , m_klient(nullptr)
{
    ui->setupUi(this);

    m_ledStatus = new QLabel();
    m_ledStatus->setFixedSize(16, 16);
    m_ledStatus->setStyleSheet("background-color: gray; border-radius: 8px; margin-right: 10px;");
    ui->statusbar->addPermanentWidget(new QLabel(" Czas Rzeczywisty (RT): "));
    ui->statusbar->addPermanentWidget(m_ledStatus);

    m_labelPing = new QLabel(" Ping: --- ms ");
    ui->statusbar->addPermanentWidget(m_labelPing);

    connect(m_usluga, &KlasaUslugowa::nowyPing, this, &MainWindow::aktualizujPing);

    connect(m_usluga, &KlasaUslugowa::statusWyrabiania, this, &MainWindow::aktualizujStatusRT);
    connect(m_usluga, &KlasaUslugowa::nadajZRegulatora, this, &MainWindow::naNadajZRegulatora);
    connect(m_usluga, &KlasaUslugowa::nadajZObiektu, this, &MainWindow::naNadajZObiektu);

    // --- PID  ---
    ui->spinPidKp->setRange(0.0, 100.0); ui->spinPidKp->setSingleStep(0.1);
    ui->spinPidTi->setRange(0.0, 100.0); ui->spinPidTi->setSingleStep(1.0);
    ui->spinPidTd->setRange(0.0, 100.0); ui->spinPidTd->setSingleStep(0.1);

    // --- GENERATOR  ---
    ui->spinAmplituda->setRange(0.0, 100.0);   ui->spinAmplituda->setSingleStep(1.0);
    ui->spinOkres->setRange(0.0, 100.0);       ui->spinOkres->setSingleStep(1.0);
    ui->spinWypelnienie->setRange(0.0, 1.0);   ui->spinWypelnienie->setSingleStep(0.1);
    ui->spinSkladowaStala->setRange(-100.0, 100.0); ui->spinSkladowaStala->setSingleStep(1.0);

    // --- PARAMETRY SYMULACJI  ---
    ui->spinInterwal->setRange(10, 500);         ui->spinInterwal->setSingleStep(10);
    ui->spinOknoObserwacji->setRange(5, 50);     ui->spinOknoObserwacji->setSingleStep(5);

    if (!m_usluga) {
        m_usluga = new KlasaUslugowa(this);
    }

    ui->labelTryb->setText("");
    ui->labelCzyPolaczono->setText("");

    QVBoxLayout* layoutMain = new QVBoxLayout(ui->widgetWykresy);
    layoutMain->setContentsMargins(0, 0, 0, 0);

    auto paraGlowna = stworzWykres("Wartość zadana i regulowana", "Odpowiedź układu");
    m_chartOutput = paraGlowna.first;
    layoutMain->addWidget(paraGlowna.second, 1);

    if (!m_chartOutput->axes(Qt::Horizontal).isEmpty()) {
        auto axisX = static_cast<QValueAxis*>(m_chartOutput->axes(Qt::Horizontal).first());
        axisX->setTickCount(11);
    }

    m_seriesZadana = dodajSerie(m_chartOutput, "Wartość zadana (w)", Qt::red);
    m_seriesWyjscie = dodajSerie(m_chartOutput, "Wartość regulowana (y)", QColor(0, 150, 255));

    QHBoxLayout* layoutDolny = new QHBoxLayout();
    layoutMain->addLayout(layoutDolny, 1);

    auto paraUchyb = stworzWykres("Uchyb regulacji", "Uchyb");
    m_chartError = paraUchyb.first;
    layoutDolny->addWidget(paraUchyb.second);
    m_seriesUchyb = dodajSerie(m_chartError, "Uchyb", Qt::green);

    auto paraSter = stworzWykres("Sygnał sterujący", "Sterowanie");
    m_chartControl = paraSter.first;
    layoutDolny->addWidget(paraSter.second);
    m_seriesSterowanie = dodajSerie(m_chartControl, "Sterowanie", Qt::magenta);

    auto paraPID = stworzWykres("Składowe sterowania", "Wartość PID");
    m_chartPID = paraPID.first;
    layoutDolny->addWidget(paraPID.second);
    m_seriesP = dodajSerie(m_chartPID, "P", Qt::cyan);
    m_seriesI = dodajSerie(m_chartPID, "I", Qt::yellow);
    m_seriesD = dodajSerie(m_chartPID, "D", QColor(255, 100, 255));

    connect(m_usluga, &KlasaUslugowa::noweDane, this, &MainWindow::aktualizujWykresy);

    ui->spinOknoObserwacji->setValue(m_oknoCzasowe);
    odswiezGUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::pair<QChart*, QChartView*> MainWindow::stworzWykres(QString tytul, QString osY) {
    QChart* chart = new QChart();
    chart->setTitle(tytul);

    chart->setBackgroundBrush(QBrush(QColor(30, 30, 30)));
    chart->setTitleBrush(Qt::white);
    chart->legend()->setAlignment(Qt::AlignTop);
    chart->legend()->setLabelBrush(Qt::white);

    QPen axisPen(Qt::white);
    axisPen.setWidth(1);

    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Czas [s]");
    axisX->setLabelsBrush(Qt::white);
    axisX->setTitleBrush(Qt::white);
    axisX->setGridLineColor(QColor(80, 80, 80));
    axisX->setLinePen(axisPen);
    axisX->setRange(0, m_oknoCzasowe);
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText(osY);
    axisY->setLabelsBrush(Qt::white);
    axisY->setTitleBrush(Qt::white);
    axisY->setGridLineColor(QColor(80, 80, 80));
    axisY->setLinePen(axisPen);
    axisY->setRange(-0.1, 0.1);
    chart->addAxis(axisY, Qt::AlignLeft);

    QChartView* view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);

    return {chart, view};
}

QLineSeries* MainWindow::dodajSerie(QChart* chart, QString nazwa, QColor kolor) {
    QLineSeries* s = new QLineSeries();
    s->setName(nazwa);
    s->setPen(QPen(kolor, 2));

    if (chart == m_chartOutput) {
        s->setPointsVisible(true);
        s->setMarkerSize(3);
    } else {
        s->setPointsVisible(false);
    }
    s->setPointLabelsVisible(false);

    chart->addSeries(s);

    if (!chart->axes(Qt::Horizontal).isEmpty())
        s->attachAxis(chart->axes(Qt::Horizontal).first());

    if (!chart->axes(Qt::Vertical).isEmpty())
        s->attachAxis(chart->axes(Qt::Vertical).first());

    return s;
}

void MainWindow::zarzadzajWykresem(QChart* chart, double t)
{
    if (!chart) return;
    if (chart->axes().isEmpty()) return;

    auto axisX = static_cast<QValueAxis*>(chart->axes(Qt::Horizontal).first());
    double minX = axisX->min();
    double maxX = axisX->max();
    double currentWidth = maxX - minX;

    if (currentWidth <= 0.0) {
        minX = 0.0;
        maxX = m_oknoCzasowe;
        currentWidth = m_oknoCzasowe;
    }

    if (std::abs(currentWidth - m_oknoCzasowe) > 0.000001) {
        maxX = minX + m_oknoCzasowe;
    }

    if (t > maxX) {
        minX = t - m_oknoCzasowe;
        maxX = t;
    }

    axisX->setRange(minX, maxX);

    double yMin = 100000;
    double yMax = -100000;
    bool saDane = false;

    for (auto series : chart->series()) {
        auto linia = static_cast<QLineSeries*>(series);

        while (linia->count() > 0 && linia->at(0).x() < minX) {
            linia->remove(0);
        }

        for (auto p : linia->points()) {
            if (p.x() >= minX && p.x() <= maxX) {
                yMin = std::min(yMin, p.y());
                yMax = std::max(yMax, p.y());
                saDane = true;
            }
        }
    }

    if (saDane) {
        double roznica = yMax - yMin;
        if (roznica < 0.1) roznica = 1.0;
        double margines = roznica * 0.1;

        auto axisY = static_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
        axisY->setRange(yMin - margines, yMax + margines);
    }
}


void MainWindow::aktualizujWykresy(double czas, double zadana, double wyjscie, double sterowanie, double uchyb) {

    double valP = m_usluga->getPidLastP();
    double valI = m_usluga->getPidLastI();
    double valD = m_usluga->getPidLastD();

    m_seriesZadana->append(czas, zadana);
    m_seriesWyjscie->append(czas, wyjscie);
    m_seriesUchyb->append(czas, uchyb);
    m_seriesSterowanie->append(czas, sterowanie);

    m_seriesP->append(czas, valP);
    m_seriesI->append(czas, valI);
    m_seriesD->append(czas, valD);

    m_seriesZadana->setName(QString("Zadana: %1").arg(zadana, 0, 'f', 2));
    m_seriesWyjscie->setName(QString("Wyjście: %1").arg(wyjscie, 0, 'f', 2));
    m_seriesUchyb->setName(QString("Uchyb: %1").arg(uchyb, 0, 'f', 4));
    m_seriesSterowanie->setName(QString("Ster: %1").arg(sterowanie, 0, 'f', 2));

    zarzadzajWykresem(m_chartOutput, czas);
    zarzadzajWykresem(m_chartError, czas);
    zarzadzajWykresem(m_chartControl, czas);
    zarzadzajWykresem(m_chartPID, czas);
}

void MainWindow::aktualizujParametryGeneratora() {
    auto typ = static_cast<int>(ui->comboTypSygnalu->currentIndex());
    bool isConstant = (typ == 0);

    ui->spinOkres->setEnabled(!isConstant);
    ui->spinAmplituda->setEnabled(!isConstant);

    ui->spinWypelnienie->setEnabled(typ == 1);

    m_usluga->ustawGenerator(
        ui->spinAmplituda->value(),
        ui->spinOkres->value(),
        ui->spinInterwal->value(),
        typ,
        ui->spinSkladowaStala->value(),
        ui->spinWypelnienie->value()
        );

    // --- WYSYŁANIE PRZEZ SIEĆ ---
    if (m_obecnyTryb == TrybPracy::SieciowyRegulator && m_serwer) {
        m_serwer->wyslijKonfigGen(ui->spinAmplituda->value(), ui->spinOkres->value(), ui->spinInterwal->value(), typ, ui->spinSkladowaStala->value(), ui->spinWypelnienie->value());
    }
    else if (m_obecnyTryb == TrybPracy::SieciowyObiekt && m_klient && m_klient->isConnected()) {
        m_klient->wyslijKonfigGen(ui->spinAmplituda->value(), ui->spinOkres->value(), ui->spinInterwal->value(), typ, ui->spinSkladowaStala->value(), ui->spinWypelnienie->value());
    }
}

void MainWindow::aktualizujParametryPID() {
    m_usluga->ustawPID(
        ui->spinPidKp->value(),
        ui->spinPidTi->value(),
        ui->spinPidTd->value(),
        ui->comboMetCalk->currentIndex()
        );

    // --- WYSYŁANIE PRZEZ SIEĆ ---
    if (m_obecnyTryb == TrybPracy::SieciowyRegulator && m_serwer) {
        m_serwer->wyslijKonfigPID(ui->spinPidKp->value(), ui->spinPidTi->value(), ui->spinPidTd->value(), ui->comboMetCalk->currentIndex());
    }
    else if (m_obecnyTryb == TrybPracy::SieciowyObiekt && m_klient && m_klient->isConnected()) {
        m_klient->wyslijKonfigPID(ui->spinPidKp->value(), ui->spinPidTi->value(), ui->spinPidTd->value(), ui->comboMetCalk->currentIndex());
    }
}

void MainWindow::on_pushStart_clicked() {
    m_usluga->start();
    // Rozgłoszenie startu przez sieć
    if (m_obecnyTryb == TrybPracy::SieciowyRegulator && m_serwer) {
        m_serwer->wyslijAkcjeSymulacji(Akcja::Start);
    } else if (m_obecnyTryb == TrybPracy::SieciowyObiekt && m_klient) {
        m_klient->wyslijAkcjeSymulacji(Akcja::Start);
    }
}
void MainWindow::on_pushStop_clicked() {
    m_usluga->stop();
    // Rozgłoszenie stopu przez sieć
    if (m_obecnyTryb == TrybPracy::SieciowyRegulator && m_serwer) {
        m_serwer->wyslijAkcjeSymulacji(Akcja::Stop);
    } else if (m_obecnyTryb == TrybPracy::SieciowyObiekt && m_klient) {
        m_klient->wyslijAkcjeSymulacji(Akcja::Stop);
    }
}

void MainWindow::on_pushResetSym_clicked() {
    m_usluga->reset();
    resetSymulacji();

    // Rozgłoszenie resetu przez sieć
    if (m_obecnyTryb == TrybPracy::SieciowyRegulator && m_serwer) {
        m_serwer->wyslijAkcjeSymulacji(Akcja::Reset);
    } else if (m_obecnyTryb == TrybPracy::SieciowyObiekt && m_klient) {
        m_klient->wyslijAkcjeSymulacji(Akcja::Reset);
    }
}

void MainWindow::resetSymulacji() {
    auto wyczyscWykres = [](QChart* c, double okno) {
        for(auto s : c->series()) static_cast<QLineSeries*>(s)->clear();
        if(!c->axes(Qt::Horizontal).isEmpty())
            c->axes(Qt::Horizontal).first()->setRange(0, okno);
    };

    wyczyscWykres(m_chartOutput, m_oknoCzasowe);
    wyczyscWykres(m_chartError, m_oknoCzasowe);
    wyczyscWykres(m_chartControl, m_oknoCzasowe);
    wyczyscWykres(m_chartPID, m_oknoCzasowe);
}

void MainWindow::on_pushResetPID_clicked() {
    m_usluga->resetPID();
}

void MainWindow::on_pushConfigARX_clicked() {
    ParametryARX okno(this);
    std::vector<double> A, B;
    int opoznienie;
    double szum, umin, umax, ymin, ymax;
    bool ograniczenia;

    m_usluga->pobierzModel(A, B, opoznienie, szum, umin, umax, ymin, ymax, ograniczenia);
    okno.ustawDane(A, B, opoznienie, szum, umin, umax, ymin, ymax, ograniczenia);
    connect(&okno, &ParametryARX::zglosNoweParametry, this, &MainWindow::odbierzParametryARX);
    okno.exec();
}

void MainWindow::odbierzParametryARX(std::vector<double> a, std::vector<double> b, int k, double szum, double umin, double umax, double ymin, double ymax, bool ograniczenia) {
    m_usluga->ustawModel(a, b, k, szum, umin, umax, ymin, ymax, ograniczenia);

    // WYSYŁANIE PRZEZ SIEĆ (Tylko obiekt może edytować)
    if (m_obecnyTryb == TrybPracy::SieciowyObiekt && m_klient && m_klient->isConnected()) {
        m_klient->wyslijKonfigARX(a, b, k, szum, umin, umax, ymin, ymax, ograniczenia);
    }
}

void MainWindow::on_pushSaveConfig_clicked() {
    QString f = QFileDialog::getSaveFileName(this, "Zapisz konfigurację", "", "JSON (*.json)");
    if(!f.isEmpty()) {

        QFile file(f);
        if (!file.open(QIODevice::WriteOnly)) return;

        QJsonDocument doc(m_usluga->toJson());
        file.write(doc.toJson());
        file.close();
    }
}

void MainWindow::on_pushLoadConfig_clicked() {
    QString f = QFileDialog::getOpenFileName(this, "Wczytaj konfigurację", "", "JSON (*.json)");
    if(!f.isEmpty()) {

        QFile file(f);
        if (!file.open(QIODevice::ReadOnly)) return;

        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        if (!doc.isObject()) return;

        m_usluga->fromJson(doc.object());
        resetSymulacji();
    }
}



void MainWindow::odswiezGUI() {
    const QList<QWidget*> widgets = {
        ui->spinAmplituda, ui->spinOkres, ui->spinInterwal, ui->spinSkladowaStala,
        ui->spinWypelnienie, ui->spinPidKp, ui->spinPidTi, ui->spinPidTd,
        ui->comboTypSygnalu, ui->comboMetCalk
    };

    for(auto w : widgets) w->blockSignals(true);

    ui->comboTypSygnalu->setCurrentIndex(m_usluga->getGenTyp());
    ui->spinAmplituda->setValue(m_usluga->getGenAmplituda());
    ui->spinOkres->setValue(m_usluga->getGenOkres());
    ui->spinInterwal->setValue(m_usluga->getGenInterwal());
    ui->spinSkladowaStala->setValue(m_usluga->getGenSkladowa());
    ui->spinWypelnienie->setValue(m_usluga->getGenWypelnienie());

    ui->spinPidKp->setValue(m_usluga->getPidKp());
    ui->spinPidTi->setValue(m_usluga->getPidTi());
    ui->spinPidTd->setValue(m_usluga->getPidTd());
    ui->comboMetCalk->setCurrentIndex(m_usluga->getPidMetodaCalkowania());

    int typ = ui->comboTypSygnalu->currentIndex();
    bool isConstant = (typ == 0);
    ui->spinOkres->setEnabled(!isConstant);
    ui->spinAmplituda->setEnabled(!isConstant);
    ui->spinWypelnienie->setEnabled(typ == 1);

    for(auto w : widgets) w->blockSignals(false);
}

void MainWindow::on_spinAmplituda_editingFinished() { aktualizujParametryGeneratora(); }
void MainWindow::on_spinOkres_editingFinished() { aktualizujParametryGeneratora(); }
void MainWindow::on_spinSkladowaStala_editingFinished() { aktualizujParametryGeneratora(); }
void MainWindow::on_spinWypelnienie_editingFinished() { aktualizujParametryGeneratora(); }
void MainWindow::on_spinInterwal_editingFinished() {
    m_usluga->setInterwal(ui->spinInterwal->value());
    aktualizujParametryGeneratora();

    // Wysyłanie zmiany interwału
    if (m_obecnyTryb == TrybPracy::SieciowyRegulator && m_serwer) {
        m_serwer->wyslijAkcjeSymulacji(Akcja::ZmienInterwal, ui->spinInterwal->value());
    } else if (m_obecnyTryb == TrybPracy::SieciowyObiekt && m_klient) {
        m_klient->wyslijAkcjeSymulacji(Akcja::ZmienInterwal, ui->spinInterwal->value());
    }
}
void MainWindow::on_comboTypSygnalu_currentIndexChanged(int index) { aktualizujParametryGeneratora(); }

void MainWindow::on_spinPidKp_editingFinished() { aktualizujParametryPID(); }
void MainWindow::on_spinPidTi_editingFinished() { aktualizujParametryPID(); }
void MainWindow::on_spinPidTd_editingFinished() { aktualizujParametryPID(); }
void MainWindow::on_comboMetCalk_currentIndexChanged(int index) { aktualizujParametryPID(); }

void MainWindow::on_spinOknoObserwacji_editingFinished()
{
    double noweOkno = ui->spinOknoObserwacji->value();
    if (noweOkno < 1.0) noweOkno = 1.0;
    m_oknoCzasowe = noweOkno;

    double t = m_usluga->getCzas();
    zarzadzajWykresem(m_chartOutput, t);
    zarzadzajWykresem(m_chartError, t);
    zarzadzajWykresem(m_chartControl, t);
    zarzadzajWykresem(m_chartPID, t);
}

// Funkcja po kliknięciu przycisku Połącz w głównym oknie
void MainWindow::on_pushPolaczSiec_clicked()
{
    // --- ROZŁĄCZANIE ---
    if (m_obecnyTryb != TrybPracy::Stacjonarny) {
<<<<<<< Updated upstream
        // Zatrzymujemy Serwer
=======
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Rozłącz", "Czy na pewno rozłączyć?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::No) {
            return;
        }
>>>>>>> Stashed changes
        if (m_serwer) {
            disconnect(m_serwer, nullptr, nullptr, nullptr);
            m_serwer->stopListening();
            m_serwer->deleteLater();
            m_serwer = nullptr;
        }
        if (m_klient) {
            disconnect(m_klient, nullptr, nullptr, nullptr);
            m_klient->disconnectFrom();
            m_klient->deleteLater();
            m_klient = nullptr;
        }

        ustawTrybGUI(TrybPracy::Stacjonarny);
        ui->labelCzyPolaczono->setText("Rozłączono ręcznie.");
        m_labelPing->setText(" Ping: --- ms ");
        return;
    }

    DialogPolaczenie dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        if (dialog.czySerwer()) {
            ustawTrybGUI(TrybPracy::SieciowyRegulator);

            if(m_serwer) { m_serwer->deleteLater(); }
            m_serwer = new MyTCPServer(this);

            connect(m_serwer, &MyTCPServer::odebranoKonfigPID, this, &MainWindow::naOdebranoKonfigPID);
            connect(m_serwer, &MyTCPServer::odebranoKonfigGen, this, &MainWindow::naOdebranoKonfigGen);
            connect(m_serwer, &MyTCPServer::odebranoKonfigARX, this, &MainWindow::naOdebranoKonfigARX);
            connect(m_serwer, &MyTCPServer::odebranoAkcjeSymulacji, this, &MainWindow::naOdebranoAkcjeSymulacji);
            connect(m_serwer, &MyTCPServer::odebranoProbkeOdObiektu, m_usluga, &KlasaUslugowa::odbierzZSieciOdObiektu);

            connect(m_serwer, &MyTCPServer::newClientConnected, this, [this](QString adr) {
                QString msg = "Połączono z klientem. IP: " + adr;
                ui->labelCzyPolaczono->setText(msg);
            });

            connect(m_serwer, &MyTCPServer::clientDisconnected, this, [this](int id) {
                QMessageBox::warning(this, "Połączenie przerwane",
                                     "Klient rozłączył się. Powrót do trybu stacjonarnego.");
                ustawTrybGUI(TrybPracy::Stacjonarny);
            });

            m_serwer->startListening(dialog.getPort());
        } else {
            ustawTrybGUI(TrybPracy::SieciowyObiekt);

            if(m_klient) { m_klient->deleteLater(); }
            m_klient = new MyTCPClient(this);

            connect(m_klient, &MyTCPClient::odebranoKonfigPID, this, &MainWindow::naOdebranoKonfigPID);
            connect(m_klient, &MyTCPClient::odebranoKonfigGen, this, &MainWindow::naOdebranoKonfigGen);
            connect(m_klient, &MyTCPClient::odebranoKonfigARX, this, &MainWindow::naOdebranoKonfigARX);
            connect(m_klient, &MyTCPClient::odebranoAkcjeSymulacji, this, &MainWindow::naOdebranoAkcjeSymulacji);
            connect(m_klient, &MyTCPClient::odebranoProbkeOdRegulatora, m_usluga, &KlasaUslugowa::odbierzZSieciOdRegulatora);

            connect(m_klient, &MyTCPClient::connected, this, [this](QString adr, int port) {
                QString msg = QString("Połączono z serwerem. Adres: %1:%2").arg(adr).arg(port);
                ui->labelCzyPolaczono->setText(msg);
            });

            connect(m_klient, &MyTCPClient::disconnected, this, [this]() {
                QMessageBox::warning(this, "Błąd sieci",
                                     "Utracono połączenie z Serwerem. Powrót do trybu stacjonarnego.");
                ustawTrybGUI(TrybPracy::Stacjonarny);
            });

            m_klient->connectTo(dialog.getIP(), dialog.getPort());
        }
    }
}

void MainWindow::ustawTrybGUI(TrybPracy tryb)
{
    m_usluga->ustawTrybSymulacji(static_cast<int>(tryb));
    m_obecnyTryb = tryb;

    switch (tryb) {
    case TrybPracy::Stacjonarny:
        ui->groupBox_Sim->setEnabled(true);
        ui->groupBox_Gen->setEnabled(true);
        ui->groupBox_PID->setEnabled(true);
        ui->groupBox_ARX->setEnabled(true);
        ui->labelTryb->setText("");
        ui->labelCzyPolaczono->setText("");
        ui->pushPolaczSiec->setText("Połącz");
        break;

    case TrybPracy::SieciowyRegulator:
        ui->groupBox_Sim->setEnabled(true);
        ui->groupBox_Gen->setEnabled(true);
        ui->groupBox_PID->setEnabled(true);
        ui->groupBox_ARX->setEnabled(false);
        ui->labelTryb->setText("Tryb:   Regulator");
        ui->labelCzyPolaczono->setText("Oczekuję na połączenie...");
        ui->pushPolaczSiec->setText("Rozłącz");
        break;

    case TrybPracy::SieciowyObiekt:
<<<<<<< Updated upstream
        // Obiekt: tylko ARX aktywny. Reszta sterowana z zewnątrz.
        ui->groupBox_Sim->setEnabled(false);
=======
        ui->groupBox_Sim->setEnabled(true);
        ui->pushStart->setEnabled(false);
        ui->pushStop->setEnabled(false);
        ui->pushResetSym->setEnabled(false);
        ui->spinInterwal->setEnabled(false);

>>>>>>> Stashed changes
        ui->groupBox_Gen->setEnabled(false);
        ui->groupBox_PID->setEnabled(false);
        ui->groupBox_ARX->setEnabled(true);
        ui->labelTryb->setText("Tryb:   Obiekt");
        ui->labelCzyPolaczono->setText("Oczekuję na połączenie...");
        ui->pushPolaczSiec->setText("Rozłącz");
        break;
    }
}

void MainWindow::naOdebranoKonfigPID(double kp, double ti, double td, int metoda) {
    m_usluga->ustawPID(kp, ti, td, metoda);
    odswiezGUI();
}

void MainWindow::naOdebranoKonfigGen(double amplituda, double okres, int interwal, int typ, double skladowa, double wypelnienie) {
    m_usluga->ustawGenerator(amplituda, okres, interwal, typ, skladowa, wypelnienie);
    odswiezGUI();
}

void MainWindow::naOdebranoKonfigARX(std::vector<double> A, std::vector<double> B, int opoznienie, double szum,
                                     double umin, double umax, double ymin, double ymax, bool ograniczenia) {

    m_usluga->ustawModel(A, B, opoznienie, szum, umin, umax, ymin, ymax, ograniczenia);
}

void MainWindow::naOdebranoAkcjeSymulacji(Akcja akcja, int parametr) {
    switch(akcja) {
    case Akcja::Start: m_usluga->start(); break;
    case Akcja::Stop: m_usluga->stop(); break;
    case Akcja::Reset:
        m_usluga->reset();
        resetSymulacji();
        break;
    case Akcja::ZmienInterwal:
        m_usluga->setInterwal(parametr);

        ui->spinInterwal->blockSignals(true);
        ui->spinInterwal->setValue(parametr);
        ui->spinInterwal->blockSignals(false);
        break;
    }
}

void MainWindow::aktualizujStatusRT(bool ok) {
    if (m_obecnyTryb == TrybPracy::Stacjonarny) {
        m_ledStatus->setStyleSheet("background-color: gray; border-radius: 8px; margin-right: 10px;");
    } else if (ok) {
        m_ledStatus->setStyleSheet("background-color: #00FF00; border-radius: 8px; margin-right: 10px;"); // ZIELONY
    } else {
        m_ledStatus->setStyleSheet("background-color: #FF0000; border-radius: 8px; margin-right: 10px;"); // CZERWONY
    }
}


void MainWindow::naNadajZRegulatora(double u, double w, double e, double p, double i, double d) {
    if (m_obecnyTryb == TrybPracy::SieciowyRegulator && m_serwer) {
        m_serwer->wyslijProbkeRegulatora(u, w, e, p, i, d);
    }
}
void MainWindow::naNadajZObiektu(double y) {
    if (m_obecnyTryb == TrybPracy::SieciowyObiekt && m_klient) {
        m_klient->wyslijProbkeObiektu(y);
    }
}

void MainWindow::aktualizujPing(int pingMs) {
    if (m_obecnyTryb == TrybPracy::SieciowyRegulator) {
        m_labelPing->setText(QString(" Ping: %1 ms ").arg(pingMs));
    }
}
