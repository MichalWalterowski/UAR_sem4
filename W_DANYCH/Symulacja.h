#ifndef SYMULACJA_H
#define SYMULACJA_H

#include <QObject>
#include <QTimer>
#include <QJsonObject>
#include <QJsonArray>
#include <vector>
#include <QDateTime>
#include "GeneratorWartosciZadanej.h"
#include "ProstyUAR.h"

enum class TrybSymulacji { Lokalny, SiecRegulator, SiecObiekt };

class Symulacja : public QObject
{
    Q_OBJECT

private:
    GeneratorWartosciZadanej m_generator;
    ProstyUAR m_prostyUAR;
    QTimer *m_timer;

    bool m_czyDziala;
    double m_czas;

    // Bufory chwilowe
    double m_wartoscZadana;
    double m_wartoscWyjscie;
    double m_sterowanie;
    double m_uchyb;

    TrybSymulacji m_tryb = TrybSymulacji::Lokalny;
    bool m_czyPrzyszlaOdpowiedz = true;
    double m_ostatnieOdebraneY = 0.0;

    qint64 m_czasWyslania = 0;

    double m_odbW = 0.0, m_odbE = 0.0, m_odbP = 0.0, m_odbI = 0.0, m_odbD = 0.0;

public:
    explicit Symulacja(QObject *parent = nullptr);

    QJsonObject toJson() const;
    void fromJson(const QJsonObject& json);

    void konfigurujModel(const std::vector<double>& A, const std::vector<double>& B, int opoznienie, double szum = 0.0);
    void ustawOgraniczenia(double u_min, double u_max, double y_min, double y_max);
    void konfigurujRegulator(double k, double ti, double td);
    void konfigurujMetodePID(int indeksMetody);
    void konfigurujGenerator(double ampl, double okres, int interwal,
                             GeneratorWartosciZadanej::TypSygnalu typ,
                             double skladowa, double wypelnienie);

    void uruchom();
    void zatrzymaj();
    void setInterwal(int ms);
    void resetuj();
    void wykonajKrok();
    void resetUAR();

    void setOgraniczeniaWlaczone(bool wlacz);

    std::vector<double> getModelA() const;
    std::vector<double> getModelB() const;
    int getModelOpoznienie() const;
    double getModelSzum() const;
    double getModelUMIN() const;
    double getModelUMAX() const;
    double getModelYMIN() const;
    double getModelYMAX() const;
    double getWartoscZadana() const;
    double getWartoscWyjscie() const;
    double getSterowanie() const;
    double getUchyb() const;
    double getCzas() const;
    bool czyDziala() const;
    int getInterwalMs() const;

    GeneratorWartosciZadanej pobierzGenerator() const;
    ModelARX pobierzModel() const;
    RegulatorPID pobierzRegulator() const;

    void ustawTryb(TrybSymulacji tryb);
    //void odbierzZSieci(double wartosc);
    void odbierzZSieciOdRegulatora(double u, double w, double e, double p, double i, double d);
    void odbierzZSieciOdObiektu(double y);

    double getPidP() const;
    double getPidI() const;
    double getPidD() const;
signals:
    void krokWykonany();

    //void wyslijDoSieci(double wartosc);
    void wyslijZRegulatoraDoSieci(double u, double w, double e, double p, double i, double d);
    void wyslijZObiektuDoSieci(double y);
    void statusCzasuRzeczywistego(bool wyrabiaSie);

    void pingZaktualizowany(int pingMs);

private slots:
    void onTimerTimeout();
};

#endif // SYMULACJA_H
