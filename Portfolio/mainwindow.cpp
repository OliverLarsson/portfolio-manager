#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "investor.h"
#include "market.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_allDone_clicked
 *
 * sets all the user input values to private variables
 * sends data on to next class
 */
void MainWindow::on_allDone_clicked()
{
    name = ui->lineEdit->text().toStdString();
    age = ui->lineEdit_2->text().toInt();
    wealth = ui->lineEdit_3->text().toDouble();
    risk_tolerance = ui->lineEdit_4->text().toDouble();
    risk_requirement = ui->lineEdit_5->text().toDouble();
    sector = ui->lineEdit_6->text().toStdString();

    ui->allDone->setText("Set!");
}

/**
 * @brief MainWindow::on_marketGo_clicked
 *
 * creates new object for the Invester class
 */
void MainWindow::on_marketGo_clicked()
{
    Investor investor(name, age, wealth, risk_tolerance, risk_requirement, sector);
    investor.setModal(true);
    investor.exec();
}
