/**
 * Attempted to make a Factory desing in QT but the Q_OBJECT that creates the UI is not copyable so that wasn't ever going to be made possible
*/

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

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
    int c_i_; // confidence interval
};

#endif // FORECAST_H
