#include "market.h"
#include "ui_market.h"
#include <iostream>

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
    choice_ = ui->lineEdit->text().toInt();
}
