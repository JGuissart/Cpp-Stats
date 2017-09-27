#include "InvalidBasicException.h"

#include <iostream>
#include <string>

using namespace std;

InvalidBasicException::InvalidBasicException()
{
    setMessage("Default exception");
}

InvalidBasicException::InvalidBasicException(string msg)
{
    setMessage(msg);
}

InvalidBasicException::InvalidBasicException(const InvalidBasicException& IBE)
{
    setMessage(IBE.getMessage());
}

InvalidBasicException::~InvalidBasicException()
{

}

/********* Getters *********/

string InvalidBasicException::getMessage() const
{
    return sMessage;
}

/********* Setters *********/

void InvalidBasicException::setMessage(const string msg)
{
    sMessage = msg;
}

/********* Surcharges d'opérateurs *********/

ostream& operator<<(std::ostream& o, const InvalidBasicException& IBE)
{
    o << IBE.getMessage();

    return o;
}
