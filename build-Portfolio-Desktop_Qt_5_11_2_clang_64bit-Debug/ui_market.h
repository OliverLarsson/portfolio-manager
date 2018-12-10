/********************************************************************************
** Form generated from reading UI file 'market.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKET_H
#define UI_MARKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Market
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_9;

    void setupUi(QDialog *Market)
    {
        if (Market->objectName().isEmpty())
            Market->setObjectName(QStringLiteral("Market"));
        Market->resize(722, 459);
        label = new QLabel(Market);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 20, 161, 41));
        label_2 = new QLabel(Market);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 20, 81, 41));
        label_3 = new QLabel(Market);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 20, 391, 41));
        label_4 = new QLabel(Market);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 40, 551, 41));
        label_8 = new QLabel(Market);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 210, 60, 16));
        lineEdit = new QLineEdit(Market);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 210, 113, 24));
        pushButton = new QPushButton(Market);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 210, 71, 24));
        widget = new QWidget(Market);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(140, 90, 207, 106));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout->addWidget(label_10);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout->addWidget(label_9);


        retranslateUi(Market);

        QMetaObject::connectSlotsByName(Market);
    } // setupUi

    void retranslateUi(QDialog *Market)
    {
        Market->setWindowTitle(QApplication::translate("Market", "Dialog", nullptr));
        label->setText(QApplication::translate("Market", "Earlier you selected ", nullptr));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("Market", " as your preferred sector. Select options to view the financial", nullptr));
        label_4->setText(QApplication::translate("Market", " assets in this market. ", nullptr));
        label_8->setText(QApplication::translate("Market", "Choice: ", nullptr));
        pushButton->setText(QApplication::translate("Market", "Go", nullptr));
        label_5->setText(QApplication::translate("Market", "1. View entire market info", nullptr));
        label_7->setText(QApplication::translate("Market", "2. View market by asset name", nullptr));
        label_6->setText(QApplication::translate("Market", "3. View market by asset ticker ", nullptr));
        label_10->setText(QApplication::translate("Market", "4. View market by asset price", nullptr));
        label_9->setText(QApplication::translate("Market", "5. View market by asset variance ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Market: public Ui_Market {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKET_H
