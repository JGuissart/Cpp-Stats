#include "InvalidDataException.h"

#include <iostream>
#include <string>

using namespace std;

InvalidDataException::InvalidDataException() : InvalidBasicException()
{

}

InvalidDataException::InvalidDataException(string msg) : InvalidBasicException(msg)
{

}

InvalidDataException::InvalidDataException(const InvalidDataException& IDE) : InvalidBasicException((InvalidBasicException&)IDE)
{

}

InvalidDataException::~InvalidDataException()
{

}

ostream& operator<<(std::ostream& o, const InvalidDataException& IDE)
{
    o << IDE.getMessage();

    return o;
}
