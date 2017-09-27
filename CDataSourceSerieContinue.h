#ifndef CDATASOURCESERIECONTINUE_H_INCLUDED
#define CDATASOURCESERIECONTINUE_H_INCLUDED

#include "CDataSource.h"
#include "CListeS.h"
#include "CListeTriee.h"

class CDataSourceSerieContinue : public CDataSource
{
    private:
        CListeS<CData1D> *L;
        float fDebut;
        float fIntervalle;
    public:
        CDataSourceSerieContinue();
        CDataSourceSerieContinue(std::string n, std::string s, int eff, CListeS<CData1D>& liste, CListeTriee<float>& lTriee);
        ~CDataSourceSerieContinue();

        /********* Getters *********/

        float getXi(int i);
        float getYi(int i);
        CListeS<CData>* getL();
        float getDebut() const;
        float getIntervalle() const;

        /********* Setters *********/

        /********* Surcharges d'opérateurs *********/

        /***************************/

        void afficheDonnees();
};

#endif // CDATASOURCESERIECONTINUE_H_INCLUDED
