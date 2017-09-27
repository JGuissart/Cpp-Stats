#include "InvalidFileException.h"

#include <iostream>
#include <string>

using namespace std;

InvalidFileException::InvalidFileException() : InvalidBasicException()
{

}

InvalidFileException::InvalidFileException(string msg) : InvalidBasicException(msg)
{

}

InvalidFileException::InvalidFileException(const InvalidFileException& IFE) : InvalidBasicException ((InvalidBasicException&) IFE)
{

}

InvalidFileException::~InvalidFileException()
{

}

/********* Getters *********/

/********* Setters *********/

/********* Surcharges d'opérateurs *********/

ostream& operator<<(std::ostream& o, const InvalidFileException& IFE)
{
    o << IFE.getMessage();

    return o;
}
