#include "Fraction.h"

using namespace std;

ostream &operator<<(ostream &flux, const Fraction &fract)
{
    fract.afficher(flux);
    return flux;
}

Fraction operator+(const Fraction &a, const Fraction &b)
{
    Fraction copie(a);
    copie+=b;
    return copie;
}
Fraction operator+(const Fraction &a, int b)
{
    Fraction copie(a);
    copie+=b;
    return copie;
}

Fraction operator-(const Fraction &a, const Fraction &b)
{
    Fraction copie(a);
    copie-=b;
    return copie;
}
Fraction operator-(const Fraction &a, int b)
{
    Fraction copie(a);
    copie-=b;
    return copie;
}

Fraction operator*(const Fraction &a, const Fraction &b)
{
    Fraction copie(a);
    copie*=b;
    return copie;
}
Fraction operator*(const Fraction &a, int b)
{
    Fraction copie(a);
    copie/=b;
    return copie;
}

Fraction operator/(const Fraction &a, const Fraction &b)
{
    Fraction copie(a);
    copie/=b;
    return copie;
}
Fraction operator/(const Fraction &a, int b)
{
    Fraction copie(a);
    copie/=b;
    return copie;
}

Fraction operator%(const Fraction &a, const Fraction &b)
{
    Fraction copie(a);
    copie%=b;
    return copie;
}
Fraction operator%(const Fraction &a, int b)
{
    Fraction copie(a);
    copie%=b;
    return copie;
}

bool operator==(Fraction const &a, const Fraction &b)
{
    return (a.egal(b));
}

bool operator!=(Fraction const &a, const Fraction &b)
{
    return !(a.egal(b));
}

bool operator<(Fraction const &a, const Fraction &b)
{
    return (a.inferieur(b));
}

bool operator>(Fraction const &a, const Fraction &b)
{
    return !(a.inferieur(b));
}

bool operator<=(Fraction const &a, const Fraction &b)
{
    return (a.inferieur(b) || a.egal(b));
}

bool operator>=(Fraction const &a, const Fraction &b)
{
    return (!a.inferieur(b) || a.egal(b));
}

//------------------------------------------------------

Fraction::Fraction() : m_numerateur(0), m_denominateur(1)
{

}

Fraction::Fraction(int num) : m_numerateur(num), m_denominateur(1)
{

}

Fraction::Fraction(int num, int denom) : m_numerateur(num), m_denominateur(denom)
{
    reduire();
}

Fraction& Fraction::operator+=(const Fraction &b)
{
    Fraction copie(b);
    if (m_denominateur != copie.m_denominateur)
    {
        int tmp = m_denominateur;
        m_numerateur *= copie.m_denominateur;
        m_denominateur *= copie.m_denominateur;
        copie.m_numerateur *= tmp;
    }
    m_numerateur += copie.m_numerateur;

    reduire();

    return *this;
}
Fraction& Fraction::operator+=(int b)
{
    b*=m_denominateur;

    m_numerateur+=b;

    return *this;
}

Fraction& Fraction::operator-=(const Fraction &b)
{
    Fraction copie(b);
    copie*=-1;
    *this+=copie;
    reduire();

    return *this;
}
Fraction& Fraction::operator-=(int b)
{
    b*=m_denominateur;
    m_numerateur-=b;

    reduire();

    return *this;
}

Fraction& Fraction::operator*=(const Fraction &b)
{
    m_numerateur *= b.m_numerateur;
    m_denominateur *= b.m_denominateur;

    reduire();

    return *this;
}
Fraction& Fraction::operator*=(int b)
{
    m_numerateur *= b;

    reduire();

    return *this;
}

Fraction& Fraction::operator/=(const Fraction &b)
{
    if (b.m_numerateur < 0)
    {
        m_numerateur *= -b.m_denominateur;
        m_denominateur *= -b.m_numerateur;
    }
    else if (b.m_numerateur > 0)
    {
        m_numerateur *= b.m_denominateur;
        m_denominateur *= b.m_numerateur;
    }

    reduire();

    return *this;
}
Fraction& Fraction::operator/=(int b)
{
    if (b < 0)
    {
        m_numerateur *= -1;
        m_denominateur *= b;
    }
    else if (b > 0)
    {
        m_denominateur *= b;
    }

    reduire();

    return *this;
}

Fraction& Fraction::operator%=(const Fraction &b)
{
    Fraction copie(b);
    int tmp = m_numerateur;
    m_numerateur *= copie.m_denominateur;
    m_denominateur *= copie.m_denominateur;
    copie.m_numerateur *= tmp;

    m_numerateur %= copie.m_numerateur;

    reduire();

    return *this;
}
Fraction& Fraction::operator%=(int b)
{
    m_numerateur %= b;

    reduire();

    return *this;
}

bool Fraction::egal(Fraction const &b) const
{
    return (m_numerateur == b.m_numerateur && m_denominateur == b.m_denominateur);
}

bool Fraction::inferieur(Fraction const &b) const
{
    return (m_numerateur*b.m_denominateur<b.m_numerateur*m_denominateur);
}

void Fraction::afficher(ostream &flux) const
{
    if (m_denominateur == 1)
        flux << m_numerateur;
    else if (m_numerateur == m_denominateur)
        flux << 1;
    else
        flux << m_numerateur << "/" << m_denominateur;
}

void Fraction::reduire()
{
    int nombre = pgcd(m_numerateur, m_denominateur);
    m_numerateur/=nombre;
    m_denominateur/=nombre;
}

int pgcd(int a, int b)
{
    if (a<0)
        a*=-1;
    if (b<0)
        b*=-1;
    int tmp;
    if (a%b!=0)


    while(a%b!=0)
    {
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}
