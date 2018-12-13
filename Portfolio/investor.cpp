#include "investor.h"
#include "ui_investor.h"
#include <iostream>
#include "market.h"

using namespace std;

/**
 * @brief Investor::Investor
 * @param name
 * @param age
 * @param wealth
 * @param risk_t
 * @param risk_r
 * @param sector
 * @param parent
 *
 * All parameters are from the mainwindow class
 * Pretty hefty constructor but necessary since the information is being shown to the investor immediately as the window opens
 */
Investor::Investor(string name, int age, double wealth, double risk_t, double risk_r, string sector, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Investor)
{
    name_ = name;
    age_ = age;
    wealth_ = wealth;
    risk_tolerance_ = risk_t;
    risk_requirement_ = risk_r;
    if(sector == "t") {
        sector_ = "Technology";
    }
    else {
        sector_ = "Industrial";
    }


    ui->setupUi(this);

    risk_profile_ = risk_profile();

    ui->label_17->setText(QString::number(risk_profile_));
    ui->label_19->setText(QString::number(100 - risk_profile_ - 5));
    ui->label_21->setText(QString::number(5));
    ui->label_3->setText(QString::fromStdString(name_));
    ui->label_6->setText(QString::number(age_));
    ui->label_8->setText(QString::number(wealth_));
    ui->label_13->setText(QString::number(risk_tolerance_));
    ui->label_14->setText(QString::number(risk_requirement_));
    ui->label_9->setText(QString::fromStdString(sector_));
}

Investor::~Investor()
{
    delete ui;
}

/**
 * @brief Investor::on_pushButton_clicked
 *
 * Creates the market class
 */
void Investor::on_pushButton_clicked()
{
    Market market(name_, age_, wealth_, risk_tolerance_, risk_requirement_, sector_, risk_profile_);
    market.setModal(true);
    market.exec();
}

/**
 * @brief Investor::risk_profile
 * @return
 *
 * sets a risk profile dependent on the input of the investor
 * returns a double to set equal to private variable risk_profile_
 */
double Investor::risk_profile() {
    if(age_ > 17 && age_ < 40) {
        if(risk_tolerance_ >=1 && risk_tolerance_ < 3) {
            return 70.0;
        }
        else if(risk_tolerance_ >=3 && risk_tolerance_ < 7) {
            return 80.0;
        }
        else if(risk_tolerance_ >= 7 && risk_tolerance_ < 10) {
            return 90.0;
        }
        else {
            return 95.0;
        }
    }
    else if(age_ >= 40 && age_ < 60) {
        if(risk_tolerance_ >=1 && risk_tolerance_ < 3) {
            return 50.0;
        }
        else if(risk_tolerance_ >=3 && risk_tolerance_ < 7) {
            return 60.0;
        }
        else if(risk_tolerance_ >= 7 && risk_tolerance_ < 10) {
            return 70.0;
        }
        else {
            return 80.0;
        }
    }
    else if(age_ >= 60 && age_ < 70) {
        if(risk_tolerance_ >=1 && risk_tolerance_ < 3) {
            return 30.0;
        }
        else if(risk_tolerance_ >=3 && risk_tolerance_ < 7) {
            return 40.0;
        }
        else if(risk_tolerance_ >= 7 && risk_tolerance_ < 10) {
            return 50.0;
        }
        else {
            return 60.0;
        }
    }
    else if(age_ >= 70) {
        if(risk_tolerance_ >=1 && risk_tolerance_ < 3) {
            return 10.0;
        }
        else if(risk_tolerance_ >=3 && risk_tolerance_ < 7) {
            return 20.0;
        }
        else if(risk_tolerance_ >= 7 && risk_tolerance_ < 10) {
            return 30.0;
        }
        else {
            return 40.0;
        }
    }
    return 0;
}
