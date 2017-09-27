#include "CDataSource.h"

#include <iostream>

using namespace std;

CDataSource::CDataSource()
{
    setNom("Default");
    setSujet("Default");
    setEffectifTotal(0);
    setType(0);
}

CDataSource::CDataSource(std::string n, std::string s, int eff, int t)
{
    setNom(n);
    setSujet(s);
    setEffectifTotal(eff);
    setType(t);
}

CDataSource::~CDataSource()
{

}

/********* Getters *********/

string CDataSource::getNom() const
{
    return nom;
}

string CDataSource::getSujet() const
{
    return sujet;
}

int CDataSource::getEffectifTotal() const
{
    return effTotal;
}

int CDataSource::getType() const
{
    return type;
}

/********* Setters *********/

void CDataSource::setNom(const string n)
{
    nom = n;
}

void CDataSource::setSujet(const string s)
{
    sujet = s;
}

void CDataSource::setEffectifTotal(const int eff)
{
    effTotal = eff;
}

void CDataSource::setType(const int t)
{
    type = t;
}

/********* Surcharges d'opérateurs *********/

/***************************/

int CDataSource::CONTINUE = 1;
int CDataSource::DISCRETE = 2;
int CDataSource::INCONNUE = 0;
