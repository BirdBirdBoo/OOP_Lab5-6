#include "fraction.h"

int Fraction::instanceCount = 0;

Fraction::Fraction()
{
    ++instanceCount;
}

Fraction::Fraction(int _numerator, int _demominator): Fraction()
{
    this->numerator = _numerator;
    this->denominator = _demominator;
}

Fraction::Fraction(const Fraction &other) : Fraction(other.numerator, other.denominator)
{
}

Fraction::~Fraction()
{
    --instanceCount;
}

int Fraction::getNumerator() const
{
    return numerator;
}

void Fraction::setNumerator(int newNumerator)
{
    this->numerator = newNumerator;
}

int Fraction::getDenominator() const
{
    return denominator;
}

void Fraction::setDenominator(int newDenominator)
{
    this->denominator = newDenominator;
}

Fraction Fraction::add(const Fraction &a) const
{
    return Fraction(numerator * a.denominator + a.numerator * denominator, denominator * a.denominator);
}

Fraction Fraction::operator+(const Fraction &a) const
{
    return add(a);
}

Fraction Fraction::minus(const Fraction &a) const
{
    return Fraction(numerator * a.denominator - a.numerator * denominator, denominator * a.denominator);
}

Fraction Fraction::operator-(const Fraction &a) const
{
    return minus(a);
}

Fraction Fraction::multiply(const Fraction &a) const
{
    return Fraction(numerator * a.numerator, denominator * a.denominator);
}

Fraction Fraction::operator*(const Fraction &a) const
{
    return multiply(a);
}

Fraction Fraction::divide(const Fraction &a) const
{
    return Fraction(numerator * a.denominator, denominator * a.numerator);
}

Fraction Fraction::operator/(const Fraction &a) const
{
    return divide(a);
}

Fraction Fraction::operator,(const Fraction &a) const
{
    return add(a);
}

Fraction Fraction::normalized() const
{
    int gcd = greatestCommonDivisor(numerator, denominator);
    return Fraction(numerator / gcd, denominator / gcd);
}

Fraction Fraction::invert() const
{
    return Fraction(denominator, numerator);
}

Fraction Fraction::operator!() const
{
    return invert();
}

Fraction::operator double() const
{
    return this->numerator / (double) this->denominator;
}

Fraction::operator int() const
{
    return this->numerator;
}

bool Fraction::operator>(const Fraction &other) const
{
    return this->numerator * other.denominator > this->denominator * other.numerator;
}

int Fraction::getInstanceCount()
{
    return instanceCount;
}

int greatestCommonDivisor(int a, int b)
{
    while (a != 0) {
        int copyOfA = a;
        a = b % a;
        b = copyOfA;
    }
    return b;
}

/*bool operator>(const Fraction &a, const Fraction &b) {
    return a.numerator * b.denominator / (double) (a.denominator * b.numerator) > 1;
}*/

bool operator<(const Fraction &a, const Fraction &b) {
    return a.numerator * b.denominator / (double) (a.denominator * b.numerator) < 1;
}

bool operator==(const Fraction &a, const Fraction &b) {
    return a.numerator * b.denominator == a.denominator * b.numerator;
}
