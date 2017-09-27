#include "InvalidMemoryException.h"

#include <iostream>
#include <string>

using namespace std;

InvalidMemoryException::InvalidMemoryException() : InvalidBasicException()
{

}

InvalidMemoryException::InvalidMemoryException(string msg) : InvalidBasicException(msg)
{

}

InvalidMemoryException::InvalidMemoryException(const InvalidMemoryException& IME) : InvalidBasicException((InvalidBasicException&)IME)
{

}

InvalidMemoryException::~InvalidMemoryException()
{

}

ostream& operator<<(std::ostream& o, const InvalidMemoryException& IME)
{
    o << IME.getMessage();

    return o;
}
