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

    /**
     * Attempt at Singleton implementation in QT -- works on console app but couldn't implement it correctly here
     *
    static Portfolio& GetPortfolio() {
        static Portfolio portfolio;
        return portfolio;
    }

    Portfolio(Portfolio const&) = delete;
    void operator = (Portfolio const&) = delete;
    */

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    // Attempt cont. with a private constructor
    // Portfolio(string name, int age, double wealth, double risk_t, double risk_r, string sector, double risk_profile, QWidget *parent = nullptr);

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
