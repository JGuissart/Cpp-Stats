#ifndef DATASOURCE_H_INCLUDED
#define DATASOURCE_H_INCLUDED

#include "CListeS.h"
#include "InvalidBasicException.h"
#include "InvalidDataException.h"
#include "InvalidFileException.h"
#include "InvalidMemoryException.h"

#include <string>

class CDataSource
{
    protected:
        std::string nom;
        std::string sujet;
        int effTotal;
        int type;
    public:
        CDataSource();
        CDataSource(std::string n, std::string s, int eff, int t);
        virtual ~CDataSource();

        /********* Getters *********/

        std::string getNom() const;
        std::string getSujet() const;
        int getEffectifTotal() const;
        int getType() const;
        virtual float getXi(int i) = 0;
        virtual float getYi(int i) = 0;
        virtual CListeS<CData>* getL() = 0;

        /********* Setters *********/

        void setNom(const std::string n);
        void setSujet(const std::string s);
        void setEffectifTotal(const int eff);
        void setType(const int t);

        /********* Surcharges d'opérateurs *********/

        /***************************/

        static int DISCRETE;
        static int CONTINUE;
        static int INCONNUE;
};

#endif // DATASOURCE_H_INCLUDED
