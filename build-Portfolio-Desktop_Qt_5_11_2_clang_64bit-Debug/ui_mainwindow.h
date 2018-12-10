/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *marketGo;
    QLabel *label_33;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_9;
    QFrame *frame;
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
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QPushButton *allDone;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menuPortfolio_Manager;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1205, 661);
        MainWindow->setStyleSheet(QLatin1String("color: white; \n"
"background-color: rgb(17, 17, 17)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        marketGo = new QPushButton(centralWidget);
        marketGo->setObjectName(QStringLiteral("marketGo"));
        marketGo->setGeometry(QRect(750, 550, 151, 61));
        marketGo->setStyleSheet(QLatin1String("background-color: rgb(186, 124, 0);\n"
"font-size: 20pt; "));
        label_33 = new QLabel(centralWidget);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(110, 0, 571, 131));
        label_33->setStyleSheet(QLatin1String("font-size: 100pt; \n"
"font-weight: bold; \n"
"color: rgb(0, 148, 193);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 550, 441, 51));
        label->setStyleSheet(QStringLiteral("font-size: 30pt; "));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(150, 140, 651, 51));
        label_8->setStyleSheet(QStringLiteral("font-size: 18pt; "));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(150, 190, 581, 41));
        label_9->setStyleSheet(QStringLiteral("font-size: 18pt; "));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(820, 40, 301, 471));
        frame->setStyleSheet(QLatin1String("background-color:   rgb(12, 12, 12); \n"
"border-styler: solid;\n"
"border-width: 10px;\n"
"border-color: white;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 10, 161, 21));
        label_10->setStyleSheet(QStringLiteral("font-weight: bold; "));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 60, 161, 21));
        label_11->setStyleSheet(QStringLiteral("font-weight: bold; "));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 120, 161, 21));
        label_12->setStyleSheet(QStringLiteral("font-weight: bold; "));
        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 220, 161, 21));
        label_13->setStyleSheet(QStringLiteral("font-weight: bold; "));
        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 300, 161, 21));
        label_14->setStyleSheet(QStringLiteral("font-weight: bold; "));
        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 380, 161, 21));
        label_15->setStyleSheet(QStringLiteral("font-weight: bold; "));
        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(40, 30, 231, 21));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(40, 90, 221, 21));
        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(40, 150, 221, 21));
        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(40, 170, 221, 21));
        label_20 = new QLabel(frame);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 190, 221, 21));
        label_21 = new QLabel(frame);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(40, 250, 221, 21));
        label_22 = new QLabel(frame);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(40, 270, 221, 21));
        label_23 = new QLabel(frame);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(40, 330, 221, 21));
        label_24 = new QLabel(frame);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(40, 350, 221, 21));
        label_25 = new QLabel(frame);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(30, 410, 251, 21));
        label_26 = new QLabel(frame);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(30, 430, 251, 21));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(349, 281, 195, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("font-size: 20pt; "));

        horizontalLayout->addWidget(label_3);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QStringLiteral("color: black; "));

        horizontalLayout->addWidget(lineEdit);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(349, 313, 178, 26));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("font-size: 20pt; "));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setStyleSheet(QStringLiteral("color: black; "));

        horizontalLayout_2->addWidget(lineEdit_2);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(349, 441, 289, 26));
        horizontalLayout_6 = new QHBoxLayout(widget2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QStringLiteral("font-size: 20pt; "));

        horizontalLayout_6->addWidget(label_7);

        lineEdit_6 = new QLineEdit(widget2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setStyleSheet(QStringLiteral("color: black; "));

        horizontalLayout_6->addWidget(lineEdit_6);

        allDone = new QPushButton(centralWidget);
        allDone->setObjectName(QStringLiteral("allDone"));
        allDone->setGeometry(QRect(420, 480, 141, 41));
        allDone->setStyleSheet(QLatin1String("font-size: 20pt; \n"
"background-color:rgb(66, 66, 66);"));
        widget3 = new QWidget(centralWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(349, 377, 259, 26));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("font-size: 20pt; "));

        horizontalLayout_4->addWidget(label_5);

        lineEdit_4 = new QLineEdit(widget3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setStyleSheet(QStringLiteral("color: black; "));

        horizontalLayout_4->addWidget(lineEdit_4);

        widget4 = new QWidget(centralWidget);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(349, 345, 199, 26));
        horizontalLayout_3 = new QHBoxLayout(widget4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("font-size: 20pt; "));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_3 = new QLineEdit(widget4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setStyleSheet(QStringLiteral("color: black; "));

        horizontalLayout_3->addWidget(lineEdit_3);

        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(506, 410, 125, 24));
        lineEdit_5->setStyleSheet(QStringLiteral("color: black; "));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 410, 150, 24));
        label_6->setStyleSheet(QStringLiteral("font-size: 20pt; "));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1205, 22));
        menuPortfolio_Manager = new QMenu(menuBar);
        menuPortfolio_Manager->setObjectName(QStringLiteral("menuPortfolio_Manager"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPortfolio_Manager->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        marketGo->setText(QApplication::translate("MainWindow", "Move on", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "Welcome! ", nullptr));
        label->setText(QApplication::translate("MainWindow", "Does your information look good? ", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Before we get started, tell us a little about yourself. Refer to the ", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "table to the right to view input criteria and terminology information. ", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Name", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Age", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Wealth", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Risk tolerance", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Risk requirement", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Sector", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "We like to be on a first name basis :)", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "To the nearest year", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "To properly diversify, please invest", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "at least $11,000. Enter a number ", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "without characters. ", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "How willing are you to take risk? ", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "Enter a whole number from 1-10.", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "How big of a return do you need? ", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "Enter a whole number from 1-100.", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "Do you want to invest in the Technology", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "or Industrial sector? Enter t or i. ", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Name: ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Age: ", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Sector preference:", nullptr));
        allDone->setText(QApplication::translate("MainWindow", "Set profile", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Risk tolerance:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Wealth:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Risk requirement:", nullptr));
        menuPortfolio_Manager->setTitle(QApplication::translate("MainWindow", "Portfolio Manager ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
