#ifndef CLISTETRIEE_H_INCLUDED
#define CLISTETRIEE_H_INCLUDED

#include "CListe.h"
#include "CData.h"
#include "CData1D.h"
#include "CData2D.h"
#include "InvalidMemoryException.h"

//template <class T> class Iterateur;
template <class T> class CListeTriee : public CListe<T>
{
    public:
        CListeTriee();
        ~CListeTriee();

        /********* Getters *********/

        /********* Setters *********/

        /********* Surcharges d'operateurs *********/

        /*******************************************/

        void ajout(const T& elem);
        void affiche();
};

#endif // CLISTETRIEE_H_INCLUDED
