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
    explicit Portfolio(string name, int age, double wealth, double risk_t, double risk_r, string sector, QWidget *parent = nullptr);
    ~Portfolio();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Portfolio *ui;

    string name_;
    int age_;
    double wealth_;
    double risk_tolerance_;
    string sector_;
    double risk_requirement_;
    double risk_profile_;

    int choice_;
};

#endif // PORTFOLIO_H
