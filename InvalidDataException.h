#ifndef INVALIDDATAEXCEPTION_H
#define INVALIDDATAEXCEPTION_H

#include "InvalidBasicException.h"

#include <iostream>
#include <string>

class InvalidDataException : public InvalidBasicException
{
    public:
        InvalidDataException();
        InvalidDataException(std::string msg);
        InvalidDataException(const InvalidDataException& IDE);
        ~InvalidDataException();

        /********* Getters *********/

        /********* Setters *********/

        /********* Surcharges d'opérateurs *********/

        friend std::ostream& operator<<(std::ostream& o, const InvalidDataException& IDE);
};

#endif // INVALIDDATAEXCEPTION_H
