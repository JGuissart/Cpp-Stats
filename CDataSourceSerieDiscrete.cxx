#include "CDataSourceSerieDiscrete.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

CDataSourceSerieDiscrete::CDataSourceSerieDiscrete() : CDataSource()
{
    L = NULL;
}

CDataSourceSerieDiscrete::CDataSourceSerieDiscrete(string n, string s, int eff, CListeS<CData1D>& liste) : CDataSource(n, s, eff, 2)
{
    L = &liste;
}

CDataSourceSerieDiscrete::~CDataSourceSerieDiscrete()
{
    if (L)
        delete L;
}

/********* Getters *********/

float CDataSourceSerieDiscrete::getXi(int i)
{
    if (i < 0)
        throw InvalidDataException("L'indice passe en parametre de la methode getXi est invalide.");

    CData1D *CDTemp = new CData1D;
	CListeS<CData1D> *CDynCast;
	CDynCast = (CListeS<CData1D>*)(L);

	CDTemp = (CData1D*)CDynCast->getElement(i);

    return CDTemp->getValeur();
}

float CDataSourceSerieDiscrete::getYi(int i)
{
    if (i < 0)
        throw InvalidDataException("L'indice passe en parametre de la methode getYi est invalide.");

    CData1D *CDTemp = new CData1D;
	CListeS<CData1D> *CDynCast;
	CDynCast = (CListeS<CData1D>*)(L);

	CDTemp = (CData1D*)CDynCast->getElement(i);

    return CDTemp->getEffectif();
}

CListeS<CData>* CDataSourceSerieDiscrete::getL()
{
    return (CListeS<CData>*)L;
}

/********* Setters *********/

/********* Surcharges d'opérateurs *********/

/***************************/

void CDataSourceSerieDiscrete::afficheDonnees()
{
    CData1D *data = new CData1D;

	for (int i = 0; i < L->getTaille(); i++)
    {
        data = L->getElement(i);
        cout << "\t(" << data->getValeur() << "; " << data->getEffectif() << ")" << endl;
    }
}
