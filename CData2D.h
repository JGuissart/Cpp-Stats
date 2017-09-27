#ifndef CDATA2D_H_INCLUDED
#define CDATA2D_H_INCLUDED

#include "CData.h"

#include <iostream>

class CData2D : public CData
{
    private:
        float fValeur1;
        float fValeur2;
    public:
        CData2D();
        CData2D(float v1, float v2);
        ~CData2D();

        /********* Getters *********/

		float getValeur1() const;
		float getValeur2() const;

        /********* Setters *********/

        void setValeur1(const float v);
        void setValeur2(const float v);

        /********* Surcharges d'operateurs *********/

        bool operator<(const CData2D& d);
		bool operator>(const CData2D& d);
		bool operator<=(const CData2D& d);
		bool operator>=(const CData2D& d);
		bool operator==(const CData2D& d);
		CData2D& operator=(const CData2D& d);
		friend std::ostream& operator<<(std::ostream& o, const CData2D& d);

        /*******************************************/

        void affiche();
};

#endif // CDATA2D_H_INCLUDED
