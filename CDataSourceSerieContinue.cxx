#include "CDataSourceSerieContinue.h"

#include <iostream>

using namespace std;

CDataSourceSerieContinue::CDataSourceSerieContinue() : CDataSource()
{
    L = NULL;
    fDebut = 0.0;
    fIntervalle = 0.0;
}

CDataSourceSerieContinue::CDataSourceSerieContinue(string n, string s, int eff, CListeS<CData1D>& liste, CListeTriee<float>& lTriee) : CDataSource(n, s, eff, 1)
{
    this->L = new CListeS<CData1D>;

    float fMin, fMax;
    int iBaton = 1, iCompteur = 0;

    fMin = *lTriee.getElement(0);
    fMax = *lTriee.getElement(lTriee.getTaille() - 1);
    fDebut = 0.0;

    cout << "Entrez le debut de la serie continue." << endl;


    float fTemp = (fMax - fMin) * 0.02;

    fMin -= fTemp;
    fMax += fTemp;

    do
    {
        if (iBaton)
            cout << "Le nombre de batons doit etre au moins de 1 ..." << endl;

        cout << "Entrez le nombre de batonnets que vous souhaitez: ";
        cin >> iBaton;
    }
    while (iBaton <= 0);

    fIntervalle = (fMax - fMin) / iBaton;
    fTemp = fMin;

    int i = 0;

    for (int j = 0; i < iBaton; j++)
    {
        if (j < lTriee.getTaille())
        {
            if (fTemp <= *lTriee.getElement(j) && *lTriee.getElement(j) < fTemp + fIntervalle)
                iCompteur++;
            else
            {
                j--;
                CData1D *data = new CData1D;
                data->setValeur((fTemp + fTemp + fIntervalle) / 2);
                data->setEffectif(iCompteur);
                L->ajout(*data);
                iCompteur = 0;
                fTemp += fIntervalle;
                delete data;
                i++;
            }
        }
        else
        {
            CData1D *data = new CData1D;
            data->setValeur((fTemp + fTemp + fIntervalle) / 2);
            data->setEffectif(iCompteur);
            L->ajout(*data);
            iCompteur = 0;
            fTemp += fIntervalle;
            delete data;
            i++;
        }
    }
}

CDataSourceSerieContinue::~CDataSourceSerieContinue()
{
    if (L)
        delete L;
}

/********* Getters *********/

float CDataSourceSerieContinue::getXi(int i)
{
    CData1D *CDTemp = new CData1D;
	CListeS<CData1D> *CDynCast;
	CDynCast = (CListeS<CData1D>*)(L);

	CDTemp = CDynCast->getElement(i);

    return CDTemp->getValeur();
}

float CDataSourceSerieContinue::getYi(int i)
{
    CData1D *CDTemp = new CData1D;
	CListeS<CData1D> *CDynCast;
	CDynCast = (CListeS<CData1D>*)(L);

	CDTemp = CDynCast->getElement(i);

    return CDTemp->getEffectif();
}

CListeS<CData>* CDataSourceSerieContinue::getL()
{
    return (CListeS<CData> *)L;
}

float CDataSourceSerieContinue::getDebut() const
{
    return fDebut;
}

float CDataSourceSerieContinue::getIntervalle() const
{
    return fIntervalle;
}

/********* Setters *********/

/********* Surcharges d'opérateurs *********/

/***************************/

void CDataSourceSerieContinue::afficheDonnees()
{
    CData1D *CDTemp = new CData1D;
	CListeS<CData1D> *CDynCast;
	CDynCast = (CListeS<CData1D>*)(L);

	for (int i = 0; i < L->getTaille(); i++)
    {
        CDTemp = (CData1D*)CDynCast->getElement(i);
        cout << "\t[" << (CDTemp->getValeur() * 2 - fIntervalle) / 2 << "; ";
		cout << CDTemp->getValeur() + (fIntervalle / 2) << "[";
		cout << "\t\t" << CDTemp->getEffectif() << endl;
    }
}
