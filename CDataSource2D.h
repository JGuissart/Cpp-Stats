#ifndef CDATASOURCE2D_H_INCLUDED
#define CDATASOURCE2D_H_INCLUDED

#include "CDataSource.h"
#include "CListeS.h"

class CDataSource2D : public CDataSource
{
    private:
        CListeS<CData2D> *L;
        std::string sujet2;
        int type2;
    public:
        CDataSource2D();
        CDataSource2D(std::string n, std::string s1, std::string s2, int eff, int t1, int t2, CListeS<CData2D>& lTemp);
        ~CDataSource2D();

        /********* Getters *********/

        std::string getSujet2() const;
        int getType2() const;
        float getXi(int i);
        float getYi(int i);
        CListeS<CData>* getL();

        /********* Setters *********/

        void setSujet2(const std::string s);
        void setType2(const int t);

        /********* Surcharges d'opérateurs *********/

        /***************************/

        void afficheDonnees();
};

#endif // CDATASOURCE2D_H_INCLUDED
