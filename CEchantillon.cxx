#include "CEchantillon.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

CEchantillon::CEchantillon()
{
    source = NULL;
}

CEchantillon::CEchantillon(string nF, int col)
{
	ifstream fich(nF.c_str());

	if (!fich.is_open())
        throw InvalidFileException("Le fichier specifie n'a pas pu s'ouvrir. Celui-ci n'existe peut-etre pas ...");

    CListeS<CData1D>* listeTemp = new CListeS<CData1D>;
    CListeTriee<float> lTriee;

    int iType, iEffTotal;
    string ligne;

    getline(fich, ligne);
    string nom = ligne;
    getline(fich, ligne);
    string sujet = lectureColonne(ligne, col); // récupération du sujet en fonction de la colonne
    getline(fich, ligne);
    iType = lectureType(ligne, col);

    if (iType == CDataSource::CONTINUE)
    {
        iEffTotal = calculEffTotal1DContinue(fich, col, lTriee);
        source = new CDataSourceSerieContinue(nom, sujet, iEffTotal, *listeTemp, lTriee);
    }
    if (iType == CDataSource::DISCRETE)
    {
        iEffTotal = calculEffTotal1DDiscrete(fich, col, listeTemp);
        source = new CDataSourceSerieDiscrete(nom, sujet, iEffTotal, *listeTemp);
    }
}

CEchantillon::CEchantillon(string nF, int col1, int col2)
{
    ifstream fich(nF.c_str());

	if (!fich.is_open())
        throw InvalidFileException("Le fichier specifie n'a pas pu s'ouvrir. Celui-ci n'existe peut-etre pas ...");

    CListeS<CData2D>* listeTemp = new CListeS<CData2D>;

    int iType[2], iEffTotal;
    string ligne;

    getline(fich, ligne);
    string nom = ligne;
    getline(fich, ligne);
    string sujet1 = lectureColonne(ligne, col1);
    string sujet2 = lectureColonne(ligne, col2);

    getline(fich, ligne);
    iType[0] = lectureType(ligne, col1);
    iType[1] = lectureType(ligne, col2);

    iEffTotal = calculEffTotal2D(fich, col1, col2, listeTemp);

    source = new CDataSource2D(nom, sujet1, sujet2, iEffTotal, iType[0], iType[1], *listeTemp);
}

CEchantillon::~CEchantillon()
{
    if (source)
        delete source;
}

/********* Méthodes privées *********/

int CEchantillon::calculEffTotal1DContinue(ifstream& f, int col, CListeTriee<float>& lTriee)
{
    string ligne, sVal;
	int iEffTotal = 0, iLigne = 1;
	float Xi;

	while(getline(f, ligne))
	{
        sVal = lectureColonne(ligne, col);
        Xi = atof((char*)sVal.c_str());
        lTriee.ajout(Xi);
        iEffTotal++;
        iLigne++;
	}
	lTriee.setTaille(iEffTotal);

	return iEffTotal;
}

int CEchantillon::calculEffTotal1DDiscrete(ifstream& f, int col, CListeS<CData1D>* lTemp)
{
    string ligne, sVal;
	int iCompteur = 1, iEffTotal = 0, iLigne = 1;
	float Xi;
	int i = 1;

	CListeTriee<float> lTriee;

	while(getline(f, ligne))
	{
        sVal = lectureColonne(ligne, col);
        Xi = atof((char*)sVal.c_str());
        lTriee.ajout(Xi);
        iEffTotal++;
        iLigne++;
        i++;
	}

	fMin = *lTriee.getElement(0);
	fMax = *lTriee.getElement(lTriee.getTaille() - 1);

	for (int i = 0; i < lTriee.getTaille() - 1; i++)
    {
        if (*(lTriee.getElement(i)) == *(lTriee.getElement(i + 1)))
            iCompteur++;
        else
        {
            CData1D *data = new CData1D;
            data->setValeur(*(lTriee.getElement(i)));
            data->setEffectif(iCompteur);
            cout << "(" << data->getValeur() << "; " << data->getEffectif() << ")" << endl;
            lTemp->ajout(*data);
            iCompteur = 1;
            delete data;
        }
    }

    if (fMax != *(lTriee.getElement(lTriee.getTaille() - 2)))
    {
        CData1D *data = new CData1D;
        data->setValeur(fMax);
        data->setEffectif(1);
        cout << "(" << data->getValeur() << "; " << data->getEffectif() << ")" << endl;
        lTemp->ajout(*data);
        delete data;
    }

	return iEffTotal;
}

int CEchantillon::calculEffTotal2D(std::ifstream& f, int col1, int col2, CListeS<CData2D>* lTemp)
{
    int iEffTotal = 0;
    float Xi, Yi;
    string ligne, sVal;

    while (getline(f, ligne))
    {
        sVal = lectureColonne(ligne, col1);
        Xi = atof((char*)sVal.c_str());
        sVal = lectureColonne(ligne, col2);
        Yi = atof((char*)sVal.c_str());

        CData2D *data = new CData2D;

        data->setValeur1(Xi);
        data->setValeur2(Yi);
        lTemp->ajout(*data);
        iEffTotal++;
        delete data;
    }

    return iEffTotal;
}

int CEchantillon::lectureType(string l, int col)
{
    string sType, ligne;
    int iType;

    sType = lectureColonne(l, col);

    if (sType == "C")
        iType = CDataSource::CONTINUE;
    else if (sType == "D")
        iType = CDataSource::DISCRETE;
    else
        iType = CDataSource::INCONNUE;

    if (iType == CDataSource::INCONNUE)
    {
        char cException[256];
        sprintf(cException, "Le type de la colonne %d est inconnu ...", col);
        throw InvalidDataException(cException);
    }

    return iType;
}

string CEchantillon::lectureColonne(string ligne, int col)
{
	string sTemp = ligne;
	char* sVal;
	char buffer[256];

	strcpy(buffer, (char*)sTemp.c_str());

	sVal = strtok(buffer, ":");
	for(int i = 1; i < col; i++)
	{
		sVal = strtok(NULL, ":");

		if(sVal == NULL)
		{
		    char cException[256];
			sprintf(cException, "Il n'y a aucune donnee a la colonne %d, il n'y a que %d colonne", col, i);
			throw InvalidDataException(cException);
		}
	}

	string stVal(sVal);

	return stVal;
}

/********* Getters *********/

CDataSource* CEchantillon::getSource() const
{
    return source;
}

int CEchantillon::getEffectifTotal() const
{
    return source->getEffectifTotal();
}

/********* Setters *********/

/********* Surcharges d'operateurs *********/

/*******************************************/

void CEchantillon::Affiche()
{
    CDataSource2D *pData2D = dynamic_cast<CDataSource2D*>(source);
    string sType;
	cout << "Nom: " << source->getNom() << endl;
	cout << "Sujet: " << source->getSujet() << endl;
	if(pData2D)
		cout << "Sujet 2: " << pData2D->getSujet2() << endl;

	cout << "Effectif total: " << source->getEffectifTotal() << endl;

	if (source->getType() == CDataSource::CONTINUE)
        sType = "Continu";
    else
        sType = "Discret";

	cout << "Type: " << sType << endl;
	if(pData2D)
    {
        if (((CDataSource2D*)source)->getType2() == CDataSource::CONTINUE)
            sType = "Continu";
        else
            sType = "Discret";

        cout << "Type 2: " << sType << endl;
    }


	cout << "*************** Affichage des donnees ***************" << endl << endl;
	if (source->getType() == CDataSource::CONTINUE)
        ((CDataSourceSerieContinue*)source)->afficheDonnees();
    else
        ((CDataSourceSerieDiscrete*)source)->afficheDonnees();
}
