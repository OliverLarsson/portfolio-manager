/**
 * I tried to implement the Singleton design pattern but I couldn't make it work.
 *  Instead of keeping the code that I tried I'll try to explain what happened.
 *
 * The implementation that I used in the console app (portfolio-manager/Code/) wasn't suited
 *  for this because I don't generally use to portfolio object in this QT version.
 *  Instead I use the basic widgets and slots to draw and show information to the user.
 *  Additionally, with how the application is set up in this UI, the user cannot create
 *  multiple portfolio objects. This isn't an effect of a design pattern, but rather just the
 *  structure of the GUI.
 *
 * Furthermore, the explicit constructor declaration ensures that no other QWidget objects
 *  are implicitly converted to a Portfolio object. From what I understand in reading on QT is that
 *  this replicates the Singleton design of not allowing objects to be reassigned.
 */


#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <QDialog>
#include <iostream>

using namespace std;

namespace Ui {
class Portfolio;
}

class Portfolio : public QDialog
{
    Q_OBJECT

public:
    explicit Portfolio(string name, int age, double wealth, double risk_t, double risk_r, string sector, double risk_profile, QWidget *parent = nullptr);
    ~Portfolio();

    void risk_path();
    void add_contents();
    void set_units();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Portfolio *ui;

    string name_;
    int age_;
    double wealth_;
    double risk_tolerance_;
    string sector_;
    double risk_requirement_;
    double risk_profile_;

    double risk_capacity_;
    int path_;

    int choice_;
};

#endif // PORTFOLIO_H
