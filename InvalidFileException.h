#ifndef INVALIDFILEEXCEPTION_H
#define INVALIDFILEEXCEPTION_H

#include "InvalidBasicException.h"

#include <iostream>
#include <string>

class InvalidFileException : public InvalidBasicException
{
    public:
        InvalidFileException();
        InvalidFileException(std::string msg);
        InvalidFileException(const InvalidFileException& IFE);
        ~InvalidFileException();

        /********* Getters *********/

        /********* Setters *********/

        /********* Surcharges d'opérateurs *********/

        friend std::ostream& operator<<(std::ostream& o, const InvalidFileException& IFE);
};

#endif // INVALIDFILEEXCEPTION_H
