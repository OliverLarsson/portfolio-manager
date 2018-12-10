/********************************************************************************
** Form generated from reading UI file 'investor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVESTOR_H
#define UI_INVESTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Investor
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;

    void setupUi(QDialog *Investor)
    {
        if (Investor->objectName().isEmpty())
            Investor->setObjectName(QStringLiteral("Investor"));
        Investor->resize(767, 454);
        label_2 = new QLabel(Investor);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 140, 131, 41));
        label_3 = new QLabel(Investor);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 10, 121, 41));
        label_4 = new QLabel(Investor);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 40, 341, 41));
        label_5 = new QLabel(Investor);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 80, 121, 41));
        label_6 = new QLabel(Investor);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 80, 121, 41));
        label_7 = new QLabel(Investor);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(180, 110, 121, 41));
        label_8 = new QLabel(Investor);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(240, 110, 121, 41));
        label_9 = new QLabel(Investor);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(310, 140, 121, 41));
        label_10 = new QLabel(Investor);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(130, 180, 281, 41));
        label_11 = new QLabel(Investor);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(180, 220, 121, 41));
        label_12 = new QLabel(Investor);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(180, 250, 121, 41));
        label_13 = new QLabel(Investor);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(280, 220, 121, 41));
        label_14 = new QLabel(Investor);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(300, 250, 121, 41));
        label_15 = new QLabel(Investor);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(130, 290, 251, 41));
        label_16 = new QLabel(Investor);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(180, 330, 51, 41));
        label_17 = new QLabel(Investor);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(230, 330, 31, 41));
        label_18 = new QLabel(Investor);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(180, 360, 51, 41));
        label_19 = new QLabel(Investor);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(220, 360, 51, 41));
        label_20 = new QLabel(Investor);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(180, 390, 51, 41));
        label_21 = new QLabel(Investor);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(220, 390, 51, 41));
        label = new QLabel(Investor);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 10, 41, 41));
        pushButton = new QPushButton(Investor);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(490, 340, 141, 81));
        label_22 = new QLabel(Investor);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(260, 330, 31, 41));
        label_23 = new QLabel(Investor);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(250, 360, 31, 41));
        label_24 = new QLabel(Investor);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(250, 390, 31, 41));

        retranslateUi(Investor);

        QMetaObject::connectSlotsByName(Investor);
    } // setupUi

    void retranslateUi(QDialog *Investor)
    {
        Investor->setWindowTitle(QApplication::translate("Investor", "Dialog", nullptr));
        label_2->setText(QApplication::translate("Investor", "Sector Preference: ", nullptr));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("Investor", "From what you provided, these are your attributes: ", nullptr));
        label_5->setText(QApplication::translate("Investor", "Age:", nullptr));
        label_6->setText(QString());
        label_7->setText(QApplication::translate("Investor", "Wealth: ", nullptr));
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QApplication::translate("Investor", "Based on your answers on risk: ", nullptr));
        label_11->setText(QApplication::translate("Investor", "Risk tolerance: ", nullptr));
        label_12->setText(QApplication::translate("Investor", "Risk requirement: ", nullptr));
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QApplication::translate("Investor", "We think you should have a profile with:", nullptr));
        label_16->setText(QApplication::translate("Investor", "Stocks: ", nullptr));
        label_17->setText(QString());
        label_18->setText(QApplication::translate("Investor", "ETFs:", nullptr));
        label_19->setText(QString());
        label_20->setText(QApplication::translate("Investor", "Cash:", nullptr));
        label_21->setText(QString());
        label->setText(QApplication::translate("Investor", "Hello, ", nullptr));
        pushButton->setText(QApplication::translate("Investor", "View the market", nullptr));
        label_22->setText(QApplication::translate("Investor", "%", nullptr));
        label_23->setText(QApplication::translate("Investor", "%", nullptr));
        label_24->setText(QApplication::translate("Investor", "%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Investor: public Ui_Investor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVESTOR_H
