#include "CSerieStatistique1D.h"

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

CSerieStatistique1D::CSerieStatistique1D()
{
    data = NULL;
    moyenne = 0.0;
    mediane = 0.0;
    ecartType = 0.0;
    etendue = 0.0;
    coeffVariation = 0.0;
    fMin = 0.0;
    fMax = 0.0;
}

CSerieStatistique1D::CSerieStatistique1D(CEchantillon* E)
{
	data = E->getSource();

    moyenne = calculMoyenne();
    calculMode();
    afficheMode();
    mediane = calculMediane();
    ecartType = calculEcartType();
    fMin = ((CDataSourceSerieContinue*)data)->getXi(0);
    if (data->getType() == CDataSource::CONTINUE)
        fMin -= ((CDataSourceSerieContinue*)data)->getIntervalle() / 2;
    fMax = ((CDataSourceSerieContinue*)data)->getXi(((CDataSourceSerieContinue*)data)->getL()->getTaille() - 1);
    if (data->getType() == CDataSource::CONTINUE)
        fMax -= ((CDataSourceSerieContinue*)data)->getIntervalle() / 2;
    etendue = calculEtendue();
    coeffVariation = calculCoeffVariation();
}

CSerieStatistique1D::~CSerieStatistique1D()
{
    if (data)
        delete data;
}

/********* Getters *********/

float CSerieStatistique1D::getMoyenne() const
{
    return moyenne;
}

void CSerieStatistique1D::afficheMode()
{
    mode.affiche();
}

float CSerieStatistique1D::getMediane() const
{
    return mediane;
}

float CSerieStatistique1D::getEcartType() const
{
    return ecartType;
}

float CSerieStatistique1D::getEtendue() const
{
    return etendue;
}

float CSerieStatistique1D::getCV() const
{
    return coeffVariation;
}

float CSerieStatistique1D::getMin() const
{
	return fMin;
}

float CSerieStatistique1D::getMax() const
{
	return fMax;
}

/********* Setters *********/

/********* Surcharges d'operateurs *********/

/*******************************************/

void CSerieStatistique1D::AfficheRapport()
{
    string sType;
	cout << "Nom: " << data->getNom() << endl;
	cout << "Sujet de l'etude: " << data->getSujet() << endl;
	if (data->getType() == CDataSource::CONTINUE)
        sType = "Continu";
    else
        sType = "Discret";
	cout << "Type: " << sType << endl << endl;

	cout << "Effectif total: " << data->getEffectifTotal() << endl;

	cout << "Donnee: " << endl;
	cout << "------" << endl;

	if (data->getType() == CDataSource::CONTINUE)
        ((CDataSourceSerieContinue*)data)->afficheDonnees();
    else
        ((CDataSourceSerieDiscrete*)data)->afficheDonnees();

	cout << endl << endl;

	cout << "Effectif total: " << data->getEffectifTotal() << endl;
	cout << "\tMoyenne: " << getMoyenne() << endl;
	cout << "\tMediane: " << getMediane() << endl;
	cout << "\tMode: ";
	mode.affiche();
	cout << endl;
	cout << "\tEcart type: " << getEcartType() << endl;
	cout << "\tCoefficient de variation: " << getCV() << "%" << endl << endl;

	cout << "Controle de qualite: " << endl;
	cout << "\tValeur min: " << getMin() << endl;
	cout << "\tValeur max: " << getMax() << endl;
	cout << "\tEtendue : " << getEtendue() << endl;
}

/********* Méthodes de calculs *********/

float CSerieStatistique1D::calculMoyenne()
{
    float fMoyenne = 0;
	CListeS<CData1D>* lTemp;
	lTemp = (CListeS<CData1D>*)(((CDataSourceSerieDiscrete*)data)->getL());

	for(int i = 0; i < lTemp->getTaille(); i++)
        fMoyenne += ((CDataSourceSerieDiscrete*)data)->getXi(i) * ((CDataSourceSerieDiscrete*)data)->getYi(i);

	return fMoyenne / data->getEffectifTotal();
}

void CSerieStatistique1D::calculMode()
{
    float effTemp = ((CDataSourceSerieContinue*)data)->getYi(0);
    int i;

    for (i = 1; i < ((CDataSourceSerieContinue*)data)->getL()->getTaille(); i++)
    {
        if (effTemp < ((CDataSourceSerieContinue*)data)->getYi(i))
            effTemp = ((CDataSourceSerieContinue*)data)->getYi(i);
    }

    for (i = 0; i < ((CDataSourceSerieContinue*)data)->getL()->getTaille(); i++)
    {
        if (effTemp == ((CDataSourceSerieContinue*)data)->getYi(i))
            mode.ajout(((CDataSourceSerieContinue*)data)->getXi(i));
    }
}

float CSerieStatistique1D::calculMediane()
{
    int iTemp;
    float fMediane;

    if (data->getType() == CDataSource::DISCRETE)
    {
        CListeTriee<float> lTrieeTemp;

        for (int i = 0; i < data->getL()->getTaille(); i++)
        {
            int j = 0;
            while (j < ((CDataSourceSerieContinue*)data)->getYi(i))
            {
                lTrieeTemp.ajout(((CDataSourceSerieContinue*)data)->getXi(i));
                j++;
            }
        }

        if (data->getEffectifTotal() % 2 == 0)
        {
            iTemp = data->getEffectifTotal() / 2;
            fMediane = *(lTrieeTemp.getElement(iTemp));
            iTemp++;
            fMediane += *(lTrieeTemp.getElement(iTemp));
            fMediane = fMediane / 2;
        }
        else
        {
            iTemp = (data->getEffectifTotal() - 1) / 2;
            iTemp++;
            fMediane = *(lTrieeTemp.getElement(iTemp));
        }
    }
    else
    {
        float fEffectifCumTemp = 0, fEffectifCumPrec, fDebutTemp, fIntervalleTemp, fDebutClasseTemp;

        fDebutTemp = ((CDataSourceSerieContinue*)data)->getDebut();
        fIntervalleTemp = ((CDataSourceSerieContinue*)data)->getIntervalle();
        iTemp = data->getEffectifTotal() / 2;

        fDebutClasseTemp = fDebutTemp;

        for (int i = 0; fEffectifCumTemp < iTemp; i++)
        {
            fDebutClasseTemp += fIntervalleTemp;
            fEffectifCumPrec = fEffectifCumTemp;
            fEffectifCumTemp += ((CDataSourceSerieContinue*)data)->getYi(i);
        }

        fMediane = fDebutClasseTemp + (fIntervalleTemp * (iTemp - fEffectifCumPrec)) / (fEffectifCumTemp - fEffectifCumPrec);
    }
    return fMediane;
}

float CSerieStatistique1D::calculEcartType()
{
    float fET1 = 0, fET2 = 0;

    for (int i = 0; i < ((CDataSourceSerieContinue*)data)->getL()->getTaille() - 1; i++)
    {
        fET1 += ((CDataSourceSerieContinue*)data)->getYi(i) * ((CDataSourceSerieContinue*)data)->getXi(i) * ((CDataSourceSerieContinue*)data)->getXi(i);
        fET2 += (((CDataSourceSerieContinue*)data)->getXi(i) * ((CDataSourceSerieContinue*)data)->getXi((i))) / data->getEffectifTotal();
    }

    return sqrt((fET1 - fET2) / data->getEffectifTotal());
}

float CSerieStatistique1D::calculCoeffVariation()
{
	return (getEcartType() / getMoyenne()) * 100;
}

float CSerieStatistique1D::calculEtendue()
{
	return getMax() - getMin();
}
