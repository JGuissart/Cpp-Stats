#include "CDataSource2D.h"

#include <iostream>

using namespace std;

CDataSource2D::CDataSource2D() : CDataSource()
{
    L = NULL;
    setSujet2("Default");
    setType2(0);
}

CDataSource2D::CDataSource2D(string n, string s1, string s2, int eff, int t1, int t2, CListeS<CData2D>& lTemp) : CDataSource(n, s1, eff, t1)
{
    setSujet2(s2);
    setType2(t2);
    L = &lTemp;
}

CDataSource2D::~CDataSource2D()
{
    if (L)
        delete L;
}

/********* Getters *********/

string CDataSource2D::getSujet2() const
{
    return sujet2;
}

int CDataSource2D::getType2() const
{
    return type2;
}

float CDataSource2D::getXi(int i)
{
    CData2D *CDTemp = new CData2D;
	CListeS<CData2D> *CDynCast;
	CDynCast = (CListeS<CData2D>*)(L);

	CDTemp = CDynCast->getElement(i);

    return CDTemp->getValeur1();
}

float CDataSource2D::getYi(int i)
{
    CData2D *CDTemp = new CData2D;
	CListeS<CData2D> *CDynCast;
	CDynCast = (CListeS<CData2D>*)(L);

	CDTemp = CDynCast->getElement(i);

    return CDTemp->getValeur2();
}

CListeS<CData>* CDataSource2D::getL()
{
    return (CListeS<CData>*)L;
}

/********* Setters *********/

void CDataSource2D::setSujet2(const string s)
{
    sujet2 = s;
}

void CDataSource2D::setType2(const int t)
{
    type2 = t;
}

/********* Surcharges d'opérateurs *********/

/***************************/

void CDataSource2D::afficheDonnees()
{
    CData2D *CDTemp = new CData2D;
	CListeS<CData2D> *CDynCast;
	CDynCast = (CListeS<CData2D>*)(L);

	for (int i = 0; i < L->getTaille(); i++)
    {
        CDTemp = (CData2D*)CDynCast->getElement(i);
        cout << "\t" << CDTemp->getValeur1() << "  -  " << CDTemp->getValeur2() << endl;
    }
    delete CDTemp;
}
