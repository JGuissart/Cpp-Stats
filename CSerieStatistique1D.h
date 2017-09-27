#ifndef CSERIESTATISTIQUE1D_H_INCLUDED
#define CSERIESTATISTIQUE1D_H_INCLUDED

#include "CEchantillon.h"

class CSerieStatistique1D
{
    private:
        CDataSource *data;
        float moyenne;
        CListeTriee<float> mode;
        float mediane;
        float ecartType;
        float etendue;
        float coeffVariation;
        float fMin;
        float fMax;
    public:
        CSerieStatistique1D();
		CSerieStatistique1D(CEchantillon* E);
		~CSerieStatistique1D();

        /********* Getters *********/

        float getMoyenne() const;
        void afficheMode();
        float getMediane() const;
        float getEcartType() const;
        float getEtendue() const;
        float getCV() const;
        float getMin() const;
        float getMax() const;

        /********* Setters *********/

        /********* Surcharges d'operateurs *********/

        /*******************************************/

        void AfficheRapport();

        /********* Méthodes de calculs *********/

        float calculMoyenne();
        void calculMode();
        float calculMediane();
        float calculEcartType();
        float calculCoeffVariation();
        float calculEtendue();
};

#endif // CSERIESTATISTIQUE1D_H_INCLUDED
