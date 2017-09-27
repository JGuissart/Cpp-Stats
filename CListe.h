#ifndef CLISTE_H_INCLUDED
#define CLISTE_H_INCLUDED

#include <iostream>

#include "structCellule.h"
#include "InvalidBasicException.h"
#include "InvalidDataException.h"
#include "CData.h"
#include "CData1D.h"
#include "CData2D.h"
//#include "Iterateur.h"

//template <class T> class Iterateur;
template <class T> class CListe
{
    protected:
        Cellule<T> *pTete;
        int iTaille;
    public:
        CListe();
        virtual ~CListe();

        /********* Getters *********/

        int getTaille() const;
        T* getElement(int n);

        /********* Setters *********/

        void setTaille(const int t);

        /********* Surcharges d'operateurs *********/

        /*******************************************/

        virtual void ajout(const T& elem) = 0;
        virtual void affiche();
        bool isEmpty();
        void supprimer(const T& elem);
        //Iterateur<T> getIterateur();
};

#endif // CLISTE_H_INCLUDED
