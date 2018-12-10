#include "forecast.h"
#include "ui_forecast.h"
#include <iostream>

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
