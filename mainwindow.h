#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

#include <Fraction.h>
#include <QIntValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    typedef Fraction (Fraction::*binaryFractionFunction)(const Fraction &) const;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_multiplyButton_clicked();

    void on_divideButton_clicked();

    friend void operator<<(MainWindow *window, Fraction &fraction);
    friend void operator>>(MainWindow *window, Fraction &fraction);

private:
    Ui::MainWindow *ui;

    void setUpValidators();

    void performCalculationAndDisplay(binaryFractionFunction calculation);
    void displayResult(Fraction &irregularResult);

    bool hasValidInput(QLineEdit *inputEdit);
    bool checkInputFractionA();
    bool checkInputFractionB();
    bool checkInputFractions();

    Fraction readFraction(QLineEdit *numeratorEdit, QLineEdit *denominatorEdit);
    Fraction readFractionA();
    Fraction readFractionB();
};
#endif // MAINWINDOW_H
