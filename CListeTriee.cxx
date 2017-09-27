#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "CListeTriee.h"

using namespace std;

template <class T> CListeTriee<T>::CListeTriee()
{

}

template <class T> CListeTriee<T>::~CListeTriee()
{

}

/********* Getters *********/

/********* Setters *********/

/********* Surcharges d'operateurs *********/

/*******************************************/

template <class T> void CListeTriee<T>::ajout(const T& elem)
{
	Cellule<T> *pNew, *pTemp, *pPrec;

    pNew = new Cellule<T>;

    if (pNew == NULL) // Utiliser exception
        throw InvalidMemoryException("Erreur d'allocation de memoire lors de l'ajout d'un nouvel element dans CListeTriee.");
    else
    {
        pNew->val = new T;
        if (pNew->val == NULL)
            throw InvalidMemoryException("Erreur d'allocation de memoire pour la valeur de la structure Cellule dans CListeTriee.");
        else
        {
            *(pNew->val) = elem;

            if (this->pTete == NULL) // Si la liste est vide
            {
                pNew->pNext = NULL;
                this->pTete = pNew;
            }
            else
            {
                pPrec = NULL;
                pTemp = this->pTete;

                while (pTemp != NULL && *(pTemp->val) < *(pNew->val))
                {
                    pPrec = pTemp;
                    pTemp = pTemp->pNext;
                }

                if (pPrec == NULL) // Si on doit insérer en début de liste
                {
                    pNew->pNext = this->pTete;
                    this->pTete = pNew;
                }
                else
                {
                    pNew->pNext = pTemp;
                    pPrec->pNext = pNew;
                }
            }
            this->iTaille++;
        }
    }
}

template <class T> void CListeTriee<T>::affiche()
{
    if (this->isEmpty())
        cout << "La liste est vide ..." << endl;
    else
    {
        Cellule<T> *pTemp;
        for (pTemp = this->pTete; pTemp != NULL; pTemp = pTemp->pNext)
            cout << *(pTemp->val) << " - ";
    }
}

template class CListeTriee<float>;
/*template class CListreTriee<CData>;
template class CListreTriee<CData1D>;*/
