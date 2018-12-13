/**
 * Same as the Portfolio Singleton implementation, I ran into problems with implementing
 *  the Factory design pattern in this class.
 *
 * I tried creating the three forecasting method classes inherited from the Forecast.
 *  The issue I ran into is the Q_OBJECT macro in the beginning of the Forecast class
 *  isn't copyable since it's there to tell the compiler that there are GUI elements
 *  in the class. What I think I understand from reading QT docs is that this cannot
 *  be created multiple times since it's used in the compiling process.
 *
 * Another issue I ran into was with the QWidget *parent. As I explained in the
 *  Portfolio class header file, the explicit declaration of the constructor is
 *  designed (to the best of my understanding) not allow reassigning to the class
 *  object. This design goes directly against the Factory design pattern since it
 *  would require that the whole GUI create a new class object inherited from the
 *  parent class.
 *
 * I thought about implementing some pseudo-Factory method where it runs certain
 *  functions based on the forecast that should be run, but that just involves re-writing
 *  methods with maybe a few variables that are different.
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
    int c_i_;
};

#endif // FORECAST_H
