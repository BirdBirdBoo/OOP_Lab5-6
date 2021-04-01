#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setUpValidators();

    /*assert(Fraction(3, 4) == Fraction(6, 8));

    assert(Fraction(3, 4) > Fraction(1, 2));
    assert(Fraction(3, 4) < Fraction(1, 1));*/

    double a = (Fraction(3, 4), Fraction(1, 2));
    qDebug() << a;
    qDebug() << (int)Fraction(3, 4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpValidators()
{
    auto numeratorValidator = new QIntValidator(INT32_MIN, INT32_MAX, this);
    ui->aFractionNumeratorEdit->setValidator(numeratorValidator);
    ui->bFractionNumeratorEdit->setValidator(numeratorValidator);

    auto denominatorValidator = new QIntValidator(1, INT32_MAX, this);
    ui->aFractionDenominatorEdit->setValidator(denominatorValidator);
    ui->bFractionDenominatorEdit->setValidator(denominatorValidator);
}

void MainWindow::displayResult(Fraction &irregularResult)
{
    int numerator = irregularResult.getNumerator();
    int denominator = irregularResult.getDenominator();
    if (ui->normalizeResultBox->isChecked()) {
        auto regularResult = irregularResult.normalized();
        numerator = regularResult.getNumerator();
        denominator = regularResult.getDenominator();
    }
    ui->resultFractionNumeratorEdit->setText(QString::number(numerator));
    ui->resultFractionDenominatorEdit->setText(QString::number(denominator));
}

bool MainWindow::hasValidInput(QLineEdit *inputEdit)
{
    return inputEdit->hasAcceptableInput();
}

bool MainWindow::checkInputFractionA()
{
    return hasValidInput(ui->aFractionNumeratorEdit) && hasValidInput(ui->aFractionDenominatorEdit);
}

bool MainWindow::checkInputFractionB()
{
    return hasValidInput(ui->bFractionNumeratorEdit) && hasValidInput(ui->bFractionDenominatorEdit);
}

bool MainWindow::checkInputFractions()
{
    return checkInputFractionA() && checkInputFractionB();
}

Fraction MainWindow::readFraction(QLineEdit *numeratorEdit, QLineEdit *denominatorEdit)
{
    return Fraction(numeratorEdit->text().toInt(), denominatorEdit->text().toInt());
}

Fraction MainWindow::readFractionA()
{
    return readFraction(ui->aFractionNumeratorEdit, ui->aFractionDenominatorEdit);
}

Fraction MainWindow::readFractionB()
{
    return readFraction(ui->bFractionNumeratorEdit, ui->bFractionDenominatorEdit);
}

void MainWindow::performCalculationAndDisplay(binaryFractionFunction calculation)
{
    if (!checkInputFractions())
        return;

    auto result = (readFractionA().*calculation)(readFractionB());
    this << result;
}
void MainWindow::on_plusButton_clicked()
{
    performCalculationAndDisplay(&Fraction::add);
}

void MainWindow::on_minusButton_clicked()
{
    performCalculationAndDisplay(&Fraction::minus);
}

void MainWindow::on_multiplyButton_clicked()
{
    performCalculationAndDisplay(&Fraction::multiply);
}

void MainWindow::on_divideButton_clicked()
{
    performCalculationAndDisplay(&Fraction::divide);
}

void operator<<(MainWindow *window, Fraction &fraction) {
    window->displayResult(fraction);
}

void operator>>(MainWindow *window, Fraction &fraction) {
    if(window->checkInputFractionA()) {
        fraction.setNumerator(window->ui->aFractionNumeratorEdit->text().toInt());
        fraction.setDenominator(window->ui->aFractionDenominatorEdit->text().toInt());
    }
}
