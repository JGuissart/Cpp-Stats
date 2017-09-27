#include "CSerieStatistique2D.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

CSerieStatistique2D::CSerieStatistique2D()
{
    data = NULL;
    moyenneVal1 = 0.0;
    moyenneVal2 = 0.0;
    A = 0.0;
    B = 0.0;
    correlation = 0.0;
}

CSerieStatistique2D::CSerieStatistique2D(CEchantillon *E)
{
    data = E->getSource();

    moyenneVal1 = calculMoyenneVal1();
    moyenneVal2 = calculMoyenneVal2();
    A = calculA();
    B = calculB();
    correlation = calculCorrelation();
}

CSerieStatistique2D::~CSerieStatistique2D()
{
    if (data)
        delete data;
}

/********* Getters *********/

float CSerieStatistique2D::getMoyenneVal1() const
{
    return moyenneVal1;
}

float CSerieStatistique2D::getMoyenneVal2() const
{
    return moyenneVal2;
}

float CSerieStatistique2D::getA() const
{
    return A;
}

float CSerieStatistique2D::getB() const
{
    return B;
}

float CSerieStatistique2D::getCorrelation() const
{
    return correlation;
}
/********* Setters *********/

/********* Surcharges d'operateurs *********/



/*******************************************/

void CSerieStatistique2D::Affiche()
{
    cout << "Etude statistique : " << endl;
    cout << "--------------------" << endl << endl;
    cout << "Titre: \t" << data->getNom() << endl;
	cout << "Sujet de l'etude: " << data->getSujet() << " -- " << ((CDataSource2D*)data)->getSujet2() << endl;
	cout << "Effectif Total: " << data->getEffectifTotal() << endl;
	char cType1, cType2;
	if (data->getType() == CDataSource::CONTINUE)
        cType1 = 'C';
    else
        cType1 = 'D';

    if (((CDataSource2D*)data)->getType2() == CDataSource::CONTINUE)
        cType2 = 'C';
    else
        cType2 = 'D';
	cout << "Type: \t" << cType1 << "    " << cType2 << endl;

	cout << "Valeurs: " << endl;
	((CDataSource2D*)data)->afficheDonnees();
	cout << endl << endl;

	cout << "Moyenne Val1: " << getMoyenneVal1() << endl;
	cout << "Moyenne Val2: " << getMoyenneVal2() << endl << endl;
}

void CSerieStatistique2D::Prevision()
{
    char cChoix = '0';
    float x, y;
    while(cChoix != '3')
    {
        cout << "Correlation: " << getCorrelation() << endl;
        cout << "\tCoefficient a: " << getA() << endl;
        cout << "\tCoefficient b: " << getB() << endl << endl;
        cout << "\t\t1: Prevision pour: " << data->getSujet() << endl;
        cout << "\t\t2: Prevision pour: " << ((CDataSource2D*)data)->getSujet2() << endl;
        cout << "\t\t3: Sortie:         " << endl;
        cout << "Votre choix: ";
        cin >> cChoix;
        switch(cChoix)
        {
            case '1':
                cout << "Entrer la valeur pour " << data->getSujet() << ": ";
                cin >> x;
                cout << "Valeur prevue: " << calculPrevisionXi(x) << endl;
            break;
            case '2':
                cout << "Entrer la valeur pour " << ((CDataSource2D*)data)->getSujet2() << ": ";
                cin >> y;
                cout << "Valeur prevue: " << calculPrevisionYi(y) << endl;
            break;
            case '3':
                exit(0);
            break;
            default:
                cout << "Le choix numero " << cChoix << " est impossible" << endl;
                cout << "Reesayez" << endl;
            break;
        }
    }
}

/********* Méthodes de calculs *********/

float CSerieStatistique2D::calculMoyenneVal1()
{
    float fMoyenne = 0;
	CListeS<CData2D>* lTemp;
	lTemp = (CListeS<CData2D>*)(((CDataSource2D*)data)->getL());

	for(int i = 0; i < lTemp->getTaille(); i++)
        fMoyenne += ((CDataSource2D*)data)->getXi(i);

	return fMoyenne / data->getEffectifTotal();
}

float CSerieStatistique2D::calculMoyenneVal2()
{
    float fMoyenne = 0;
	CListeS<CData2D>* lTemp;
	lTemp = (CListeS<CData2D>*)(((CDataSource2D*)data)->getL());

	for(int i = 0; i < lTemp->getTaille(); i++)
        fMoyenne += ((CDataSource2D*)data)->getYi(i);

	return fMoyenne / data->getEffectifTotal();
}

float CSerieStatistique2D::calculA()
{
    float iSommeXi = 0.0, iSommeYi = 0.0, iSommeXiYi = 0.0, iSommeXiCarre = 0.0;

    for (int i = 0; i < data->getL()->getTaille(); i++)
    {
        float Xi = ((CDataSource2D*)data)->getXi(i);
        float Yi = ((CDataSource2D*)data)->getYi(i);

        iSommeXi += Xi;
        iSommeYi += Yi;
        iSommeXiYi += Xi * Yi;
        iSommeXiCarre += pow(Xi, 2);
    }

    return ((iSommeXiYi - (iSommeXi * iSommeYi) / data->getEffectifTotal()) / (iSommeXiCarre - pow(iSommeXi, 2) / data->getEffectifTotal()));
}

float CSerieStatistique2D::calculB()
{
    return getMoyenneVal2() - getA() * getMoyenneVal1();
}

float CSerieStatistique2D::calculCorrelation()
{
    float iSommeXi = 0.0, iSommeYi = 0.0, iSommeXiYi = 0.0, iSommeXiCarre = 0.0, iSommeYiCarre = 0.0;

	for(int i = 0; i < data->getL()->getTaille(); i++)
	{
		float Xi = ((CDataSource2D*)data)->getXi(i);
		float Yi = ((CDataSource2D*)data)->getYi(i);
		iSommeXi += Xi;
		iSommeYi += Yi;
		iSommeXiYi += Xi * Yi;
		iSommeXiCarre += pow(Xi, 2);
		iSommeYiCarre += pow(Yi, 2);
	}
	float fNum = iSommeXiYi - (iSommeXi * iSommeYi) / data->getEffectifTotal();
	float fDenom1 =  iSommeXiCarre - pow(iSommeXi, 2) / data->getEffectifTotal();
	float fDenom2 =  iSommeYiCarre - pow(iSommeYi, 2) / data->getEffectifTotal();

	return fNum / sqrt(fDenom1 * fDenom2);
}

float CSerieStatistique2D::calculPrevisionXi(float x)
{
    return getA() * x + getB();
}

float CSerieStatistique2D::calculPrevisionYi(float y)
{
    return (y - getB()) / getA();
}
