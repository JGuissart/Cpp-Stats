#ifndef INVALIDBASICEXCEPTION_H
#define INVALIDBASICEXCEPTION_H

#include <iostream>
#include <string>

class InvalidBasicException
{
    protected:
        std::string sMessage;
    public:
        InvalidBasicException();
        InvalidBasicException(std::string msg);
        InvalidBasicException(const InvalidBasicException& other);
        ~InvalidBasicException();

        /********* Getters *********/

        std::string getMessage() const;

        /********* Setters *********/

        void setMessage(const std::string msg);

        /********* Surcharges d'opérateurs *********/

        friend std::ostream& operator<<(std::ostream& o, const InvalidBasicException& IBE);
};

#endif // INVALIDBASICEXCEPTION_H
