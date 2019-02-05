#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <iostream>

class Fraction
{
public:
    Fraction();
    Fraction(int num);
    Fraction(int num, int denom);
    Fraction& operator+=(const Fraction &b);
    Fraction& operator+=(int b);
    Fraction& operator-=(const Fraction &b);
    Fraction& operator-=(int b);
    Fraction& operator*=(const Fraction &b);
    Fraction& operator*=(int b);
    Fraction& operator/=(const Fraction &b);
    Fraction& operator/=(int b);
    Fraction& operator%=(const Fraction &b);
    Fraction& operator%=(int b);
    bool egal(Fraction const &b) const;
    bool inferieur(Fraction const &b) const;
    void afficher(std::ostream &flux) const;
    void reduire();

private:
    int m_numerateur;
    int m_denominateur;
};

std::ostream &operator<<(std::ostream &flux, const Fraction &fract);
Fraction operator+(const Fraction &a, const Fraction &b);
Fraction operator+(const Fraction &a, int b);
Fraction operator-(const Fraction &a, const Fraction &b);
Fraction operator-(const Fraction &a, int b);
Fraction operator*(const Fraction &a, const Fraction &b);
Fraction operator*(const Fraction &a, int b);
Fraction operator/(const Fraction &a, const Fraction &b);
Fraction operator/(const Fraction &a, int b);
Fraction operator%(const Fraction &a, const Fraction &b);
Fraction operator%(const Fraction &a, int b);

bool operator==(const Fraction &a, const Fraction &b);
bool operator!=(const Fraction &a, const Fraction &b);
bool operator<(const Fraction &a, const Fraction &b);
bool operator>(const Fraction &a, const Fraction &b);
bool operator<=(const Fraction &a, const Fraction &b);
bool operator>=(const Fraction &a, const Fraction &b);


int pgcd(int a, int b);

#endif // FRACTION_H_INCLUDED
