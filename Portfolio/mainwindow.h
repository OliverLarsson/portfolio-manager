#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_marketGo_clicked();

    void on_allDone_clicked();

private:
    Ui::MainWindow *ui;

    string name;
    int age;
    double wealth;
    double risk_tolerance;
    string sector;
    double risk_requirement;
};

#endif // MAINWINDOW_H
