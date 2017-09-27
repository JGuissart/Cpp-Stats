#ifndef CDATASOURCESERIEDISCRETE_H_INCLUDED
#define CDATASOURCESERIEDISCRETE_H_INCLUDED

#include "CDataSource.h"
#include "CListeS.h"

#include <iostream>
#include <string>
#include <fstream>

class CDataSourceSerieDiscrete : public CDataSource
{
    private:
        CListeS<CData1D> *L;
    public:
        CDataSourceSerieDiscrete();
        CDataSourceSerieDiscrete(std::string n, std::string s, int eff, CListeS<CData1D>& liste);
        ~CDataSourceSerieDiscrete();

        /********* Getters *********/

        float getXi(int i);
        float getYi(int i);
        CListeS<CData>* getL();

        /********* Setters *********/

        /********* Surcharges d'opérateurs *********/

        /***************************/

        void afficheDonnees();
};

#endif // CDATASOURCESERIEDISCRETE_H_INCLUDED
