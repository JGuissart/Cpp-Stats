#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "CListeS.h"
#include "InvalidMemoryException.h"

using namespace std;

template <class T> CListeS<T>::CListeS()
{

}

template <class T> CListeS<T>::~CListeS()
{

}

template <class T> void CListeS<T>::ajout(const T& elem)
{
    Cellule<T> *pNew, *pTemp, *pPrec;

    pNew = new Cellule<T>;

    if (pNew == NULL)
        throw InvalidMemoryException("Erreur d'allocation de memoire lors de l'ajout d'un nouvel element dans CListeS.");
    else
    {
        pNew->val = new T;
        if (pNew->val == NULL)
            throw InvalidMemoryException("Erreur d'allocation de memoire lors de l'ajout d'une nouvelle valeur dans CListeS.");

        *(pNew->val) = elem;
        pNew->pNext = NULL;

        if (this->pTete == NULL)
            this->pTete = pNew;
        else
        {
            pTemp = this->pTete;
            pPrec = NULL;
            while (pTemp != NULL)
            {
                pPrec = pTemp;
                pTemp = pTemp->pNext;
            }
            pPrec->pNext = pNew;
        }
        this->iTaille++;
    }
}

template class CListeS<CData>;
template class CListeS<CData1D>;
template class CListeS<CData2D>;
