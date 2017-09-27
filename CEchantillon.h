#ifndef CECHANTILLON_H_INCLUDED
#define CECHANTILLON_H_INCLUDED

#include "CListe.h"
#include "CListeTriee.h"
#include "CData.h"
#include "CDataSource.h"
#include "CDataSourceSerieDiscrete.h"
#include "CDataSourceSerieContinue.h"
#include "CDataSource2D.h"
#include "InvalidBasicException.h"
#include "InvalidDataException.h"
#include "InvalidFileException.h"
#include "InvalidMemoryException.h"

#include <iostream>
#include <string>
#include <fstream>

class CEchantillon
{
    private:
        CDataSource *source;
        float fMin;
        float fMax;

        int calculEffTotal1DContinue(std::ifstream& f, int col, CListeTriee<float>& lTriee);
        int calculEffTotal1DDiscrete(std::ifstream& f, int col, CListeS<CData1D>* lTemp);
        int lectureType(std::string l, int col);
        int calculEffTotal2D(std::ifstream& f, int col1, int col2, CListeS<CData2D>* lTemp);
        std::string lectureColonne(std::string ligne, int col);
    public:
        CEchantillon();
        CEchantillon(std::string nF, int col);
        CEchantillon(std::string nF, int col1, int col2);
        ~CEchantillon();

        /********* Getters *********/

        CDataSource* getSource() const;
        int getEffectifTotal() const;

        /********* Setters *********/

        /********* Surcharges d'operateurs *********/

        /*******************************************/

        void Affiche();
};

#endif // CECHANTILLON_H_INCLUDED
