#include "CData1D.h"

#include <iostream>

using namespace std;

CData1D::CData1D()
{
    setValeur(0.0);
    setEffectif(0);
}

CData1D::CData1D(float v, int e)
{
    setValeur(v);
    setEffectif(e);
}

CData1D::~CData1D()
{

}

/********* Getters *********/

float CData1D::getValeur() const
{
    return fValeur;
}

int CData1D::getEffectif() const
{
    return iEffectif;
}

/********* Setters *********/

void CData1D::setValeur(const float v)
{
    fValeur = v;
}

void CData1D::setEffectif(const int e)
{
    iEffectif = e;
}

/********* Surcharges d'operateurs *********/

bool CData1D::operator<(const CData1D& d)
{
    if (getValeur() < d.getValeur())
        return true;
    else
        return false;
}

bool CData1D::operator>(const CData1D& d)
{
    if (getValeur() > d.getValeur())
        return true;
    else
        return false;
}

bool CData1D::operator<=(const CData1D& d)
{
    if (getValeur() <= d.getValeur())
        return true;
    else
        return false;
}

bool CData1D::operator>=(const CData1D& d)
{
    if (getValeur() >= d.getValeur())
        return true;
    else
        return false;
}

bool CData1D::operator==(const CData1D& d)
{
    if (getValeur() == d.getValeur())
        return true;
    else
        return false;
}

CData1D& CData1D::operator=(const CData1D& d)
{
    setValeur(d.getValeur());
    setEffectif(d.getEffectif());

    return *this;
}

ostream& operator<<(ostream& o, const CData1D& d)
{
    o << "(" << d.getValeur() << "; " << d.getEffectif() << ")" << endl;

    return o;
}

/*******************************************/

void CData1D::affiche()
{
    cout << "(" << getValeur() << "; " << getEffectif() << ")" << endl;
}
