#include "forecast.h"
#include "ui_forecast.h"
#include <iostream>
#include <sqlite3.h> // header file for the SQLite database
#include <cmath>
#include <QtSql>
#include <QtDebug>
#include <QDebug>

using namespace std;

Forecast::Forecast(string name, int age, double wealth, double risk_t, double risk_r, string sector, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forecast)
{
    name_ = name;
    age_ = age;
    wealth_ = wealth;
    risk_tolerance_ = risk_t;
    risk_requirement_ = risk_r;
    sector_ = sector;

    ui->setupUi(this);
}

Forecast::~Forecast()
{
    delete ui;
}

void Forecast::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/Ollie/Desktop/portfolio-manager/Code/Investor.db");
    if(!db.open()) {
        qDebug() << db.lastError();
        qFatal("Failed to connect");
    }

    qDebug("Connected");

    QSqlQuery * query = new QSqlQuery(db);

    choice_ = ui->lineEdit->text().toInt();
    c_i_ = ui->lineEdit_2->text().toInt();

    ui->label->setText("Forecasting Method:");
    ui->label->repaint();
    ui->label_2->setText("Confidence Level:");
    ui->label_2->repaint();

    if(sector_ == "Technology") {
        // z-scores :
            // 99 = 2.576
            // 95 = 1.96
            // 90 = 1.645
        if(choice_ == 1) {
            query->exec("SELECT COUNT(*) FROM market");
            query->next();
            int count = query->value(0).toInt();
            double sqrt_ = sqrt(count);
            if(c_i_ == 99) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 95) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 90) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else {
                ui->label_2->setText("Try Again!");
                ui->label_2->repaint();
            }
        }
        else if(choice_ == 2) {
            query->exec("SELECT COUNT(*) FROM market WHERE sector = 't' OR sector = 'e'");
            query->next();
            int count = query->value(0).toInt();
            double sqrt_ = sqrt(count);
            if(c_i_ == 99) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 't' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 't' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 95) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 't' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 't' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 90) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 't' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 't' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else {
                ui->label_2->setText("Try Again!");
                ui->label_2->repaint();
            }
        }
        else if(choice_ == 3) {
            query->exec("SELECT COUNT(*) FROM portfolio");
            query->next();
            int count = query->value(0).toInt();
            double sqrt_ = sqrt(count);
            if(c_i_ == 99) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 95) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 90) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else {
                ui->label_2->setText("Try Again!");
                ui->label_2->repaint();
            }
        }
        else {
            ui->label->setText("Try Again!");
            ui->label->repaint();
        }
    }
    else {
        // z-scores :
            // 99 = 2.576
            // 95 = 1.96
            // 90 = 1.645
        if(choice_ == 1) {
            query->exec("SELECT COUNT(*) FROM market");
            query->next();
            int count = query->value(0).toInt();
            double sqrt_ = sqrt(count);
            if(c_i_ == 99) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 95) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 90) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else {
                ui->label_2->setText("Try Again!");
                ui->label_2->repaint();
            }
        }
        else if(choice_ == 2) {
            query->exec("SELECT COUNT(*) FROM market WHERE sector = 'i' OR sector = 'e'");
            query->next();
            int count = query->value(0).toInt();
            double sqrt_ = sqrt(count);
            if(c_i_ == 99) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 'i' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 'i' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 95) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 'i' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 'i' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 90) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 'i' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(market.change) AS a FROM market WHERE market.sector = 'i' or market.sector = 'e') AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else {
                ui->label_2->setText("Try Again!");
                ui->label_2->repaint();
            }
        }
        else if(choice_ == 3) {
            query->exec("SELECT COUNT(*) FROM portfolio");
            query->next();
            int count = query->value(0).toInt();
            double sqrt_ = sqrt(count);
            if(c_i_ == 99) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 95) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else if(c_i_ == 90) {
                // lower bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) - 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double lower = query->value(0).toDouble();
                QString low = QString::number(lower, 'f', 2);
                ui->label_30->setText(low);
                ui->label_30->repaint();
                // upper bound
                query->prepare("SELECT (SELECT (SELECT AVG(market.change) + 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, portfolio, (SELECT AVG(change) AS a FROM market, portfolio WHERE market.ticker = portfolio.ticker) AS sub) / ?) AS ConfidenceInterval");
                query->addBindValue(sqrt_);
                query->exec();
                query->next();
                double upper = query->value(0).toDouble();
                QString up = QString::number(upper, 'f', 2);
                ui->label_31->setText(up);
                ui->label_31->repaint();
            }
            else {
                ui->label_2->setText("Try Again!");
                ui->label_2->repaint();
            }
        }
        else {
            ui->label->setText("Try Again!");
            ui->label->repaint();
        }
    }
    db.close();
}


void Forecast::on_pushButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/Ollie/Desktop/portfolio-manager/Code/Investor.db");
    if(!db.open()) {
        qDebug() << db.lastError();
        qFatal("Failed to connect");
    }

    qDebug("Connected");

    QSqlQuery * query = new QSqlQuery(db);

    query->exec("DELETE FROM portfolio");
}
