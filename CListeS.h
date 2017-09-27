#ifndef CLISTES_H_INCLUDED
#define CLISTES_H_INCLUDED

#include "CListe.h"
#include "CData.h"
#include "CData1D.h"
#include "CData2D.h"

//template <class T> class Iterateur;
template <class T> class CListeS : public CListe<T>
{
    public:
        CListeS();
        ~CListeS();

        /********* Getters *********/

        /********* Setters *********/

        /********* Surcharges d'operateurs *********/

        /*******************************************/

        void ajout(const T& elem);
};

#endif // CLISTES_H_INCLUDED
