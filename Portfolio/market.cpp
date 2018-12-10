#include "market.h"
#include "ui_market.h"
#include <iostream>
#include "portfolio.h"
#include <QtSql>
#include <QtDebug>
#include <QDebug>

using namespace std;

Market::Market(string name, int age, double wealth, double risk_t, double risk_r, string sector, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Market)
{
    name_ = name;
    age_ = age;
    wealth_ = wealth;
    risk_tolerance_ = risk_t;
    risk_requirement_ = risk_r;
    sector_ = sector;

    ui->setupUi(this);

    ui->label_2->setText(QString::fromStdString(sector));
}

Market::~Market()
{
    delete ui;
}

void Market::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/Ollie/Desktop/portfolio-manager/Code/Investor.db");
    if(!db.open()) {
        qDebug() << db.lastError();
        qFatal("Failed to connect");
    }

    qDebug("Connected");

    QSqlQuery query;

    choice_ = ui->lineEdit->text().toInt();
    if(choice_ == 1) {
        if(sector_ == "t"){
            query.exec("SELECT ticker, price FROM market WHERE sector = 't'");
        }
        else {
            query.exec("SELECT ticker, price FROM market WHERE sector = 'i'");
        }
    }
    else if(choice_ == 2) {
        query.exec("SELECT * FROM market WHERE sector = 't' ORDER BY name ASC");
    }
    else if(choice_ == 3) {
        query.exec("SELECT * FROM market WHERE sector = 't' ORDER BY ticker ASC");
    }
    else if(choice_ == 4) {
        query.exec("SELECT * FROM market WHERE sector = 't' ORDER BY price DESC");
    }
    else if(choice_ == 5) {
        query.exec("SELECT * FROM market WHERE sector = 't' ORDER BY change DESC");
    }
    else {
        ui->label_8->setText("Try again!");
    }
    ui->label_8->repaint();
    while (query.next()) {
            QString ticker = query.value(0).toString();
            int price = query.value(1).toInt();
            qDebug() << ticker << price;
    }
}

void Market::on_pushButton_2_clicked()
{
    Portfolio portfolio(name_, age_, wealth_, risk_tolerance_, risk_requirement_, sector_);
    portfolio.setModal(true);
    portfolio.exec();
}
