#include "portfolio.h"
#include "ui_portfolio.h"
#include <iostream>
#include "forecast.h"

using namespace std;

Portfolio::Portfolio(string name, int age, double wealth, double risk_t, double risk_r, string sector, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Portfolio)
{
    name_ = name;
    age_ = age;
    wealth_ = wealth;
    risk_tolerance_ = risk_t;
    risk_requirement_ = risk_r;
    sector_ = sector;

    ui->setupUi(this);
}

Portfolio::~Portfolio()
{
    delete ui;
}

void Portfolio::on_pushButton_clicked()
{
    Forecast forecast(name_, age_, wealth_, risk_tolerance_, risk_requirement_, sector_);
    forecast.setModal(true);
    forecast.exec();
}
