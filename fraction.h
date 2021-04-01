#ifndef FRACTION_H
#define FRACTION_H


class Fraction
{

private:
    int numerator = 1;
    int denominator = 1;

    static int instanceCount;

public:
    Fraction();
    Fraction(int _numerator, int _demominator);
    Fraction(const Fraction &other);

    ~Fraction();

    int getNumerator() const;
    void setNumerator(int newNumerator);

    int getDenominator() const;
    void setDenominator(int newDenominator);

    Fraction add(const Fraction &a) const;
    Fraction operator+(const Fraction &a) const;

    Fraction minus(const Fraction &a) const;
    Fraction operator-(const Fraction &a) const;

    Fraction multiply(const Fraction &a) const;
    Fraction operator*(const Fraction &a) const;

    Fraction divide(const Fraction &a) const;
    Fraction operator/(const Fraction &a) const;

    Fraction operator,(const Fraction &a) const;

    Fraction normalized() const;

    Fraction invert() const;
    Fraction operator!() const;

    operator int() const;
    operator double() const;

    bool operator>(const Fraction &other) const;

    //friend bool operator>(const Fraction &a, const Fraction &b);
    friend bool operator<(const Fraction &a, const Fraction &b);
    friend bool operator==(const Fraction &a, const Fraction &b);

    static int getInstanceCount();
};

int greatestCommonDivisor(int a, int b);

#endif // FRACTION_H
