#ifndef MARKET_H
#define MARKET_H

#include <QDialog>
#include <iostream>
#include "db_path.h"

using namespace std;

namespace Ui {
class Market;
}

class Market : public QDialog
{
    Q_OBJECT

public:
    explicit Market(string name, int age, double wealth, double risk_t, double risk_r, string sector, double risk_profile, QWidget *parent = nullptr);
    ~Market();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Market *ui;

    string name_;
    int age_;
    double wealth_;
    double risk_tolerance_;
    string sector_;
    double risk_requirement_;
    double risk_profile_;

    int choice_;
};

#endif // MARKET_H
