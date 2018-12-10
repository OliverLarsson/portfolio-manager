#include "market.h"
#include "ui_market.h"
#include <iostream>
#include "portfolio.h"
#include <QtSql>
#include <QtDebug>
#include <QDebug>

using namespace std;

Market::Market(string name, int age, double wealth, double risk_t, double risk_r, string sector, double risk_profile, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Market)
{
    name_ = name;
    age_ = age;
    wealth_ = wealth;
    risk_tolerance_ = risk_t;
    risk_requirement_ = risk_r;
    sector_ = sector;
    risk_profile_ = risk_profile;

    ui->setupUi(this);

    ui->label_2->setText(QString::fromStdString(sector));
}

Market::~Market()
{
    delete ui;
}

void Market::on_pushButton_clicked()
{
    ui->label_8->setText("Choice:");
    ui->label_8->repaint();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/Ollie/Desktop/portfolio-manager/Code/Investor.db");
    if(!db.open()) {
        qDebug() << db.lastError();
        qFatal("Failed to connect");
    }

    qDebug("Connected");

    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery * query = new QSqlQuery(db);

    choice_ = ui->lineEdit->text().toInt();

    if(choice_ == 1) {
        if(sector_ == "Technology"){
            query->prepare("SELECT * FROM market WHERE sector = 't' OR sector = 'e'");
            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);
            ui->tableView->repaint();
        }
        else {
            query->prepare("SELECT * FROM market WHERE ticker = 'i' OR sector = 'e'");
            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);
            ui->tableView->repaint();
        }
    }
    else if(choice_ == 2) {
        if(sector_ == "Technology"){
            query->prepare("SELECT * FROM market WHERE sector = 't' OR sector = 'e' ORDER BY name ASC");
            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);
            ui->tableView->repaint();
        }
        else {
            query->prepare("SELECT * FROM market WHERE sector = 'i' OR sector = 'e' ORDER BY name ASC");
            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);
            ui->tableView->repaint();
        }
    }
    else if(choice_ == 3) {
        if(sector_ == "Technology"){
            query->prepare("SELECT * FROM market WHERE sector = 't' OR sector = 'e' ORDER BY ticker ASC");
            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);
            ui->tableView->repaint();
        }
        else {
            query->prepare("SELECT * FROM market WHERE sector = 'i' OR sector = 'e' ORDER BY ticker ASC");
            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);
            ui->tableView->repaint();
        }
    }
    else if(choice_ == 4) {
        if(sector_ == "Technology"){
            query->prepare("SELECT * FROM market WHERE sector = 't' OR sector = 'e' ORDER BY price DESC");
            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);
            ui->tableView->repaint();
        }
        else {
            query->prepare("SELECT * FROM market WHERE sector = 'i' OR sector = 'e' ORDER BY price DESC");
            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);
            ui->tableView->repaint();
        }
    }
    else if(choice_ == 5) {
        if(sector_ == "Technology"){
            query->prepare("SELECT * FROM market WHERE sector = 't' OR sector = 'e' ORDER BY change DESC");
            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);
            ui->tableView->repaint();
        }
        else {
            query->prepare("SELECT * FROM market WHERE sector = 'i' OR sector = 'e' ORDER BY change DESC");
            query->exec();
            modal->setQuery(*query);
            ui->tableView->setModel(modal);
            ui->tableView->repaint();
        }
    }
    else {
        ui->label_8->setText("Try again!");
        ui->label_8->repaint();
    }

    qDebug() << (modal->rowCount());
    db.close();
}

void Market::on_pushButton_2_clicked()
{
    Portfolio portfolio(name_, age_, wealth_, risk_tolerance_, risk_requirement_, sector_, risk_profile_);
    portfolio.setModal(true);
    portfolio.exec();
}
