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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_9;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QLabel *label_33;

    void setupUi(QDialog *Market)
    {
        if (Market->objectName().isEmpty())
            Market->setObjectName(QStringLiteral("Market"));
        Market->resize(1155, 718);
        Market->setStyleSheet(QLatin1String("color: white; \n"
"background-color: rgb(17, 17, 17);\n"
"font-size: 20pt; "));
        label = new QLabel(Market);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 110, 181, 41));
        label_2 = new QLabel(Market);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(330, 110, 101, 41));
        label_3 = new QLabel(Market);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(440, 110, 531, 41));
        label_4 = new QLabel(Market);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 150, 221, 41));
        label_8 = new QLabel(Market);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(550, 320, 91, 31));
        lineEdit = new QLineEdit(Market);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(660, 320, 113, 24));
        lineEdit->setStyleSheet(QStringLiteral("color: black; "));
        pushButton = new QPushButton(Market);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(780, 320, 71, 31));
        pushButton->setStyleSheet(QStringLiteral("background-color:rgb(66, 66, 66);"));
        layoutWidget = new QWidget(Market);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(230, 200, 290, 146));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout->addWidget(label_10);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout->addWidget(label_9);

        pushButton_2 = new QPushButton(Market);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(920, 660, 221, 51));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(186, 124, 0);"));
        tableView = new QTableView(Market);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(80, 360, 991, 281));
        tableView->setStyleSheet(QLatin1String("background-color: rgb(196, 196, 196); \n"
"color: black; "));
        label_33 = new QLabel(Market);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(180, 10, 421, 91));
        label_33->setStyleSheet(QLatin1String("font-size: 100pt; \n"
"font-weight: bold; \n"
"color: rgb(0, 148, 193);"));

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
        pushButton_2->setText(QApplication::translate("Market", "Move on to the portfolio", nullptr));
        label_33->setText(QApplication::translate("Market", "Market", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Market: public Ui_Market {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKET_H
