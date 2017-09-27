#ifndef INVALIDMEMORYEXCEPTION_H
#define INVALIDMEMORYEXCEPTION_H

#include "InvalidBasicException.h"

#include <iostream>
#include <string>

class InvalidMemoryException : public InvalidBasicException
{
    public:
        InvalidMemoryException();
        InvalidMemoryException(std::string msg);
        InvalidMemoryException(const InvalidMemoryException& IME);
        ~InvalidMemoryException();

        /********* Getters *********/

        /********* Setters *********/

        /********* Surcharges d'opérateurs *********/

        friend std::ostream& operator<<(std::ostream& o, const InvalidMemoryException& IME);
};

#endif // INVALIDMEMORYEXCEPTION_H
