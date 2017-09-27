#include "CData2D.h"

#include <iostream>

using namespace std;

CData2D::CData2D()
{
    setValeur1(0.0);
    setValeur2(0.0);
}

CData2D::CData2D(float v1, float v2)
{
    setValeur1(v1);
    setValeur2(v2);
}

CData2D::~CData2D()
{

}

/********* Getters *********/

float CData2D::getValeur1() const
{
    return fValeur1;
}

float CData2D::getValeur2() const
{
    return fValeur2;
}

/********* Setters *********/

void CData2D::setValeur1(const float v)
{
    fValeur1 = v;
}

void CData2D::setValeur2(const float v)
{
    fValeur2 = v;
}

/********* Surcharges d'operateurs *********/

bool CData2D::operator<(const CData2D& d)
{
    if (getValeur1() < d.getValeur1() && getValeur2() < d.getValeur2())
        return true;
    else
        return false;
}

bool CData2D::operator>(const CData2D& d)
{
    if (getValeur1() > d.getValeur1() && getValeur2() > d.getValeur2())
        return true;
    else
        return false;
}

bool CData2D::operator<=(const CData2D& d)
{
    if (getValeur1() <= d.getValeur1() && getValeur2() <= d.getValeur2())
        return true;
    else
        return false;
}

bool CData2D::operator>=(const CData2D& d)
{
    if (getValeur1() < d.getValeur1() && getValeur2() < d.getValeur2())
        return true;
    else
        return false;
}

bool CData2D::operator==(const CData2D& d)
{
    if (getValeur1() == d.getValeur1() && getValeur2() == d.getValeur2())
        return true;
    else
        return false;
}

CData2D& CData2D::operator=(const CData2D& d)
{
    setValeur1(d.getValeur1());
    setValeur2(d.getValeur2());

    return *this;
}

ostream& operator<<(ostream& o, const CData2D& d)
{
    o << "(" << d.getValeur1() << "; " << d.getValeur2() << ")" << endl;

    return o;
}

/*******************************************/

void CData2D::affiche()
{
    cout << "(" << getValeur1() << "; " << getValeur2() << ")" << endl;
}
