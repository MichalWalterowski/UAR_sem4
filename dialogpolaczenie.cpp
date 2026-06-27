#include "DialogPolaczenie.h"
#include "ui_DialogPolaczenie.h"

DialogPolaczenie::DialogPolaczenie(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPolaczenie)
{
    ui->setupUi(this);

    ui->lineEditIP->setEnabled(ui->comboBoxRola->currentIndex() != 0);
}

DialogPolaczenie::~DialogPolaczenie()
{
    delete ui;
}

bool DialogPolaczenie::czySerwer() const
{
    return ui->comboBoxRola->currentIndex() == 0;
}

QString DialogPolaczenie::getIP() const
{
    return ui->lineEditIP->text();
}

int DialogPolaczenie::getPort() const
{
    return ui->lineEditPort->text().toInt();
}

void DialogPolaczenie::on_comboBoxRola_currentIndexChanged(int index)
{
    ui->lineEditIP->setEnabled(index != 0);
}

void DialogPolaczenie::on_pushButtonOk_clicked()
{
    this->accept();
}

void DialogPolaczenie::on_pushButtonAnuluj_clicked()
{
    this->reject();
}
