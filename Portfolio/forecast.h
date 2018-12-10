#ifndef FORECAST_H
#define FORECAST_H

#include <QDialog>
#include <iostream>

using namespace std;


namespace Ui {
class Forecast;
}

class Forecast : public QDialog
{
    Q_OBJECT

public:
    explicit Forecast(string name, int age, double wealth, double risk_t, double risk_r, string sector, QWidget *parent = nullptr);
    ~Forecast();

private:
    Ui::Forecast *ui;

    string name_;
    int age_;
    double wealth_;
    double risk_tolerance_;
    string sector_;
    double risk_requirement_;
    double risk_profile_;

    int choice_;
};

#endif // FORECAST_H
