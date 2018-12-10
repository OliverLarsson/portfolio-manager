#ifndef INVESTOR_H
#define INVESTOR_H

#include <QDialog>
#include <iostream>

using namespace std;

namespace Ui {
class Investor;
}

class Investor : public QDialog
{
    Q_OBJECT

public:
    explicit Investor(string name, int age, double wealth, double risk_t, double risk_r, string sector, QWidget *parent = nullptr);
    ~Investor();

    double risk_profile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Investor *ui;

    string name_;
    int age_;
    double wealth_;
    double risk_tolerance_;
    string sector_;
    double risk_requirement_;
    double risk_profile_;
};

#endif // INVESTOR_H
