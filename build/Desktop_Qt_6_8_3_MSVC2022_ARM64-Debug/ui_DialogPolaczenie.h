/********************************************************************************
** Form generated from reading UI file 'DialogPolaczenie.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPOLACZENIE_H
#define UI_DIALOGPOLACZENIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogPolaczenie
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEditPort;
    QComboBox *comboBoxRola;
    QLabel *lblAdres_2;
    QLabel *lblRola;
    QLabel *lblAdres;
    QLineEdit *lineEditIP;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonAnuluj;

    void setupUi(QDialog *DialogPolaczenie)
    {
        if (DialogPolaczenie->objectName().isEmpty())
            DialogPolaczenie->setObjectName("DialogPolaczenie");
        DialogPolaczenie->resize(264, 231);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogPolaczenie->sizePolicy().hasHeightForWidth());
        DialogPolaczenie->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(DialogPolaczenie);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        lineEditPort = new QLineEdit(DialogPolaczenie);
        lineEditPort->setObjectName("lineEditPort");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditPort->sizePolicy().hasHeightForWidth());
        lineEditPort->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEditPort, 2, 1, 1, 1);

        comboBoxRola = new QComboBox(DialogPolaczenie);
        comboBoxRola->addItem(QString());
        comboBoxRola->addItem(QString());
        comboBoxRola->setObjectName("comboBoxRola");
        sizePolicy1.setHeightForWidth(comboBoxRola->sizePolicy().hasHeightForWidth());
        comboBoxRola->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBoxRola, 0, 1, 1, 1);

        lblAdres_2 = new QLabel(DialogPolaczenie);
        lblAdres_2->setObjectName("lblAdres_2");

        gridLayout->addWidget(lblAdres_2, 2, 0, 1, 1);

        lblRola = new QLabel(DialogPolaczenie);
        lblRola->setObjectName("lblRola");

        gridLayout->addWidget(lblRola, 0, 0, 1, 1);

        lblAdres = new QLabel(DialogPolaczenie);
        lblAdres->setObjectName("lblAdres");

        gridLayout->addWidget(lblAdres, 1, 0, 1, 1);

        lineEditIP = new QLineEdit(DialogPolaczenie);
        lineEditIP->setObjectName("lineEditIP");
        sizePolicy1.setHeightForWidth(lineEditIP->sizePolicy().hasHeightForWidth());
        lineEditIP->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEditIP, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonOk = new QPushButton(DialogPolaczenie);
        pushButtonOk->setObjectName("pushButtonOk");

        horizontalLayout->addWidget(pushButtonOk);

        pushButtonAnuluj = new QPushButton(DialogPolaczenie);
        pushButtonAnuluj->setObjectName("pushButtonAnuluj");

        horizontalLayout->addWidget(pushButtonAnuluj);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(DialogPolaczenie);

        QMetaObject::connectSlotsByName(DialogPolaczenie);
    } // setupUi

    void retranslateUi(QDialog *DialogPolaczenie)
    {
        DialogPolaczenie->setWindowTitle(QCoreApplication::translate("DialogPolaczenie", "Ustawienia sieci", nullptr));
        comboBoxRola->setItemText(0, QCoreApplication::translate("DialogPolaczenie", "Regulator (serwer)", nullptr));
        comboBoxRola->setItemText(1, QCoreApplication::translate("DialogPolaczenie", "Obiekt (klient)", nullptr));

        lblAdres_2->setText(QCoreApplication::translate("DialogPolaczenie", "Port:", nullptr));
        lblRola->setText(QCoreApplication::translate("DialogPolaczenie", "Rola:", nullptr));
        lblAdres->setText(QCoreApplication::translate("DialogPolaczenie", "Adres IP:", nullptr));
        pushButtonOk->setText(QCoreApplication::translate("DialogPolaczenie", "Po\305\202\304\205cz", nullptr));
        pushButtonAnuluj->setText(QCoreApplication::translate("DialogPolaczenie", "Anuluj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPolaczenie: public Ui_DialogPolaczenie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPOLACZENIE_H
