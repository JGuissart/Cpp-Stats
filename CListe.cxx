#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "CListe.h"

using namespace std;

template <class T> CListe<T>::CListe()
{
    pTete = NULL;
    iTaille = 0;
}

template <class T> CListe<T>::~CListe()
{
    if (pTete)
    {
        Cellule<T> *pTemp, *pPrec;

        pTemp = pTete;

        while (pTemp != NULL)
        {
            pPrec = pTemp;
            pTemp = pTemp->pNext;
            delete pPrec->val;
            delete pPrec;
            iTaille--;
        }
    }
}

/********* Getters *********/

template <class T> int CListe<T>::getTaille() const
{
    return iTaille;
}

template <class T> T* CListe<T>::getElement(int n)
{
    //cout << "Valeur de n: " << n << endl;
    if (n < 0 || n > getTaille())
        throw InvalidDataException("L'indice passe en parametre de la methode getElement() est invalide.");

    Cellule<T> *pTemp = pTete;

    for (int i = 0; i != n; i++)
        pTemp = pTemp->pNext;

    return pTemp->val;
}

/********* Setters *********/

template <class T> void CListe<T>::setTaille(const int t)
{
    iTaille = t;
}

/********* Surcharges d'operateurs *********/

/*******************************************/

template <class T> void CListe<T>::affiche()
{
    if(isEmpty())
        cout << "La liste ne contient aucune donnee ..." << endl;
    else
	{
		Cellule<T> *pTemp;

        for (pTemp = pTete; pTemp != NULL; pTemp = pTemp->pNext)
        {
            cout << endl << *(pTemp->val) << endl;
            system("PAUSE");
        }
	}
}

template <class T> bool CListe<T>::isEmpty()
{
    if (pTete == NULL)
        return true;
    else
        return false;
}

template <class T> void CListe<T>::supprimer(const T& elem)
{
	if(isEmpty())
    {
        cout << "La liste ne contient aucune donnee ..." << endl;
        return; // la liste est vide -> rien faire
    }

	Cellule<T>* pPrec = pTete;

	if(*(pPrec->val) == elem) // si le premier élément est le bon -> efface
	{
		pTete = pPrec->pNext;
		delete pPrec->val;
		delete pPrec;
		iTaille--;
	}
	else
	{
		Cellule<T> *pTemp;

		pTemp = pTete->pNext;

		while(pTemp != NULL)
		{
			if(*(pTemp->val) == elem)
			{
				pPrec->pNext = pTemp->pNext;
				delete pTemp->val;
				delete pTemp;
				pTemp = pPrec->pNext;
				iTaille--;
				return;
			}
			else
			{
				pPrec = pTemp;
				pTemp = pTemp->pNext;
			}
		}
	}
}

/*template <class T> Iterateur<T> CListe<T>::getIterateur()
{
	Iterateur<T> it(pTete);
	return it;
}*/

template class CListe<float>;
template class CListe<CData>;
template class CListe<CData1D>;
template class CListe<CData2D>;
