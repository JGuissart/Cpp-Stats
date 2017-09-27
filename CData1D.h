#ifndef CDATA1D_H_INCLUDED
#define CDATA1D_H_INCLUDED

#include "CData.h"

#include <iostream>

class CData1D : public CData
{
    private:
        float fValeur;
        int iEffectif;
    public:
        CData1D();
        CData1D(float v, int e);
        ~CData1D();

        /********* Getters *********/

		float getValeur() const;
		int getEffectif() const;

        /********* Setters *********/

        void setValeur(const float v);
        void setEffectif(const int e);

        /********* Surcharges d'operateurs *********/

        bool operator<(const CData1D& d);
		bool operator>(const CData1D& d);
		bool operator<=(const CData1D& d);
		bool operator>=(const CData1D& d);
		bool operator==(const CData1D& d);
		CData1D& operator=(const CData1D& d);
		friend std::ostream& operator<<(std::ostream& o, const CData1D& d);

        /*******************************************/

        void affiche();
};

#endif // CDATA1D_H_INCLUDED
