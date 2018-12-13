#include "portfolio.h"
#include "ui_portfolio.h"
#include <iostream>
#include "forecast.h"
#include <QtSql>
#include <QtDebug>
#include <QDebug>

using namespace std;

/**
 * @brief Portfolio::Portfolio
 * @param name
 * @param age
 * @param wealth
 * @param risk_t
 * @param risk_r
 * @param sector
 * @param risk_profile
 * @param parent
 *
 * another hefty constructor for the same purpose as the Investor class
 * parameters all come from the Market class
 * sets dialogue based on past user input and some calculations
 */
Portfolio::Portfolio(string name, int age, double wealth, double risk_t, double risk_r, string sector, double risk_profile, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Portfolio)
{
    name_ = name;
    age_ = age;
    wealth_ = wealth;
    risk_tolerance_ = risk_t;
    risk_requirement_ = risk_r;
    sector_ = sector;
    risk_profile_ = risk_profile;

    ui->setupUi(this);
    risk_path();
    add_contents();
    set_units();

    risk_capacity_ = (wealth_*(risk_tolerance_/100)) + (wealth_*(risk_requirement_/100));
    ui->label_3->setText(QString::fromStdString(name_));
    ui->label_6->setText(QString::number(risk_profile_));
    ui->label_8->setText(QString::number(100 - risk_profile_ - 5));
    ui->label_11->setText(QString::number(risk_tolerance_));
    ui->label_13->setText(QString::number(risk_capacity_));
    ui->label_16->setText(QString::number(path_));

    qDebug() << wealth_;
    qDebug() << risk_capacity_;

}

Portfolio::~Portfolio()
{
    delete ui;
}

/**
 * @brief Portfolio::on_pushButton_clicked
 *
 * creates Forecast class
 */
void Portfolio::on_pushButton_clicked()
{
    Forecast forecast(name_, age_, wealth_, risk_tolerance_, risk_requirement_, sector_);
    forecast.setModal(true);
    forecast.exec();
}

/**
 * @brief Portfolio::risk_path
 *
 * creates risk path for the portfolio
 * based on risk tolerance, risk capacity, and wealth
 * the risk path is used to decide which financial assets are loaded into the portfolio
 */
void Portfolio::risk_path() {
    if(risk_tolerance_ >= 0 && risk_tolerance_ <= 3) {
        if((risk_capacity_/wealth_) >= 0 && (risk_capacity_/wealth_) <= .33) {
            path_ = 1;
        }
        else if((risk_capacity_/wealth_) >= .33 && (risk_capacity_/wealth_) <= .66) {
            path_ = 4;
        }
        else {
            path_ = 7;
        }
    }
    else if(risk_tolerance_ > 3 && risk_tolerance_ <= 6) {
        if((risk_capacity_/wealth_) > 0 && (risk_capacity_/wealth_) <= .33) {
            path_ = 2;
        }
        else if((risk_capacity_/wealth_) >= .33 && (risk_capacity_/wealth_) <= .66) {
            path_ = 5;
        }
        else {
            path_ = 8;
        }
    }
    else if(risk_tolerance_ > 6 && risk_tolerance_ <= 10) {
        if((risk_capacity_/wealth_) > 0 && (risk_capacity_/wealth_) <= .33) {
            path_ = 3;
        }
        else if((risk_capacity_/wealth_) >= .33 && (risk_capacity_/wealth_) <= .66) {
            path_ = 6;
        }
        else {
            path_ = 9;
        }
    }
}

/**
 * @brief Portfolio::add_contents
 * @var t_stocks
 * @var t_etf
 * @var i_stocks
 * @var i_etf
 *
 * loads the portfolio with the assets meeting the risk path criteria
 * all variables above are created and binded to correctly load the portfolio
 *      with the percentages claimed earlier in the process
 */
void Portfolio::add_contents() {
    int t_stocks = static_cast<int>((risk_profile_/100)*18);
    int t_etf = 18 - t_stocks;
    int i_stocks = static_cast<int>((risk_profile_/100)*14);
    int i_etf = 14 - i_stocks;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/Ollie/Desktop/portfolio-manager/Code/Investor.db");
    if(!db.open()) {
        qDebug() << db.lastError();
        qFatal("Failed to connect");
    }

    qDebug("Connected");

    QSqlQuery * query = new QSqlQuery(db);

    query->exec("DELETE FROM portfolio");

    if(sector_ == "Technology") {
        if(path_ == 1) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' ORDER BY volume, change ASC LIMIT ? OFFSET 0");
            query->addBindValue(t_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 0");
            query->addBindValue(t_etf);
            query->exec();
        }
        else if(path_ == 2) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' ORDER BY volume, change ASC LIMIT ? OFFSET 11");
            query->addBindValue(t_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 6");
            query->addBindValue(t_etf);
            query->exec();
        }
        else if(path_ == 3) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' ORDER BY volume, change ASC LIMIT ? OFFSET 22");
            query->addBindValue(t_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 12");
            query->addBindValue(t_etf);
            query->exec();
        }
        else if(path_ == 4) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' ORDER BY volume, change ASC LIMIT ? OFFSET 33");
            query->addBindValue(t_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 18");
            query->addBindValue(t_etf);
            query->exec();
        }
        else if(path_ == 5) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' ORDER BY volume, change ASC LIMIT ? OFFSET 44");
            query->addBindValue(t_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 24");
            query->addBindValue(t_etf);
            query->exec();
        }
        else if(path_ == 6) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' ORDER BY volume, change ASC LIMIT ? OFFSET 55");
            query->addBindValue(t_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 30");
            query->addBindValue(t_etf);
            query->exec();
        }
        else if(path_ == 7) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' ORDER BY volume, change ASC LIMIT ? OFFSET 66");
            query->addBindValue(t_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 36");
            query->addBindValue(t_etf);
            query->exec();
        }
        else if(path_ == 8) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' ORDER BY volume, change ASC LIMIT ? OFFSET 77");
            query->addBindValue(t_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 42");
            query->addBindValue(t_etf);
            query->exec();
        }
        else {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' ORDER BY volume, change ASC LIMIT ? OFFSET 88");
            query->addBindValue(t_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 48");
            query->addBindValue(t_etf);
            query->exec();
        }
    }
    else {
        if(path_ == 1) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' ORDER BY volume, change ASC LIMIT ? OFFSET 0");
            query->addBindValue(i_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 0");
            query->addBindValue(i_etf);
            query->exec();
        }
        else if(path_ == 2) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' ORDER BY volume, change ASC LIMIT ? OFFSET 6");
            query->addBindValue(i_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 6");
            query->addBindValue(i_etf);
            query->exec();
        }
        else if(path_ == 3) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' ORDER BY volume, change ASC LIMIT ? OFFSET 12");
            query->addBindValue(i_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 12");
            query->addBindValue(i_etf);
            query->exec();
        }
        else if(path_ == 4) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' ORDER BY volume, change ASC LIMIT ? OFFSET 18");
            query->addBindValue(i_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 18");
            query->addBindValue(i_etf);
            query->exec();
        }
        else if(path_ == 5) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' ORDER BY volume, change ASC LIMIT ? OFFSET 24");
            query->addBindValue(i_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 24");
            query->addBindValue(i_etf);
            query->exec();
        }
        else if(path_ == 6) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' ORDER BY volume, change ASC LIMIT ? OFFSET 30");
            query->addBindValue(i_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 30");
            query->addBindValue(i_etf);
            query->exec();
        }
        else if(path_ == 7) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' ORDER BY volume, change ASC LIMIT ? OFFSET 36");
            query->addBindValue(i_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 36");
            query->addBindValue(i_etf);
            query->exec();
        }
        else if(path_ == 8) {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' ORDER BY volume, change ASC LIMIT ? OFFSET 42");
            query->addBindValue(i_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 42");
            query->addBindValue(i_etf);
            query->exec();
        }
        else {
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' ORDER BY volume, change ASC LIMIT ? OFFSET 48");
            query->addBindValue(i_stocks);
            query->exec();
            query->prepare("INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'e' ORDER BY volume, change ASC LIMIT ? OFFSET 48");
            query->addBindValue(i_etf);
            query->exec();
        }
    }
    db.close();

}

/**
 * @brief Portfolio::set_units
 *
 * equally distributes units based on the value of the portfolio at 1 unit per stock and the wealth of the investor
 * casted as an int to ensure value of portfolio never goes over value of investor
 */
void Portfolio::set_units() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/Ollie/Desktop/portfolio-manager/Code/Investor.db");
    if(!db.open()) {
        qDebug() << db.lastError();
        qFatal("Failed to connect");
    }

    qDebug("Connected");

    QSqlQuery * query = new QSqlQuery(db);

    query->prepare("UPDATE PORTFOLIO SET units = CAST( ? / (SELECT SUM(p.units * m.price) AS Value FROM portfolio p, market m WHERE p.ticker = m.ticker) AS int)");
    query->addBindValue(wealth_);
    query->exec();
    db.close();
}

/**
 * @brief Portfolio::on_pushButton_2_clicked
 *
 * controller for user selections on viewing the portfolio
 * works same as the market with setting choice_ variable equal to user input
 */
void Portfolio::on_pushButton_2_clicked()
{
    ui->label->setText("Choice:");
    ui->label->repaint();

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
        query->prepare("SELECT m.name, p.ticker, m.price, p.units FROM portfolio p, market m WHERE p.ticker = m.ticker");
        query->exec();
        modal->setQuery(*query);
        ui->tableView->setModel(modal);
        ui->tableView->repaint();
    }
    else if(choice_ == 2) {
        query->prepare("SELECT m.name, p.ticker FROM portfolio p, market m WHERE p.ticker = m.ticker ORDER BY p.ticker ASC");
        query->exec();
        modal->setQuery(*query);
        ui->tableView->setModel(modal);
        ui->tableView->repaint();
    }
    else if(choice_ == 3) {
        query->prepare("SELECT m.name, p.ticker, p.units FROM portfolio p, market m WHERE p.ticker = m.ticker ORDER BY p.units DESC");
        query->exec();
        modal->setQuery(*query);
        ui->tableView->setModel(modal);
        ui->tableView->repaint();
    }
    else if(choice_ == 4) {
        query->prepare("SELECT m.name, p.ticker, m.price FROM portfolio p, market m WHERE p.ticker = m.ticker ORDER BY m.price DESC");
        query->exec();
        modal->setQuery(*query);
        ui->tableView->setModel(modal);
        ui->tableView->repaint();
    }
    else if(choice_ == 5) {
        query->prepare("SELECT SUM(p.units * m.price) AS Value FROM portfolio p, market m WHERE p.ticker = m.ticker");
        query->exec();
        modal->setQuery(*query);
        ui->tableView->setModel(modal);
        ui->tableView->repaint();
    }
    else if(choice_ == 6) {
        query->prepare("SELECT AVG(m.price) AS AvgPrice FROM market m, portfolio p WHERE p.ticker = m.ticker");
        query->exec();
        modal->setQuery(*query);
        ui->tableView->setModel(modal);
        ui->tableView->repaint();
    }
    else if(choice_ == 7) {
        query->prepare("SELECT AVG(m.change) AS AvgChange FROM market m, portfolio p WHERE p.ticker = m.ticker");
        query->exec();
        modal->setQuery(*query);
        ui->tableView->setModel(modal);
        ui->tableView->repaint();
    }
    else if(choice_ == 8) {
        query->prepare("SELECT AVG(units) AS AvgUnits FROM portfolio");
        query->exec();
        modal->setQuery(*query);
        ui->tableView->setModel(modal);
        ui->tableView->repaint();
    }
    else {
        ui->label->setText("Try again!");
        ui->label->repaint();
    }
    db.close();

}


















