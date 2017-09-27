#ifndef CSERIESTATISTIQUE2D_H_INCLUDED
#define CSERIESTATISTIQUE2D_H_INCLUDED

#include "CEchantillon.h"

class CSerieStatistique2D
{
    private:
        CDataSource *data;
        float moyenneVal1;
        float moyenneVal2;
        float A;
        float B;
        float correlation;
    public:
        CSerieStatistique2D();
        CSerieStatistique2D(CEchantillon* E);
        ~CSerieStatistique2D();

        /********* Getters *********/

        float getMoyenneVal1() const;
        float getMoyenneVal2() const;
        float getA() const;
        float getB() const;
        float getCorrelation() const;

        /********* Setters *********/

        /********* Surcharges d'operateurs *********/

        /*******************************************/

        void Affiche();
        void Prevision();

        /********* Méthodes de calculs *********/

        float calculMoyenneVal1();
        float calculMoyenneVal2();
        float calculA();
        float calculB();
        float calculCorrelation();
        float calculPrevisionXi(float x);
        float calculPrevisionYi(float y);
};

#endif // CSERIESTATISTIQUE2D_H_INCLUDED
