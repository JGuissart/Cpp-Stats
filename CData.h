#ifndef CDATA_H_INCLUDED
#define CDATA_H_INCLUDED

#include <iostream>

class CData
{
	protected:
	public:
		CData() {};
		virtual ~CData() {};

		/********* Getters *********/

        /********* Setters *********/

        /********* Surcharges d'operateurs *********/

        bool operator==(const CData& d) { return true; };
        friend std::ostream& operator<<(std::ostream& o, const CData& d) { return o; };

        /*******************************************/

        //virtual void affiche() = 0;
};

#endif // CDATA_H_INCLUDED
