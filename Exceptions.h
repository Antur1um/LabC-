#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#pragma once


#include <iostream>
#include <typeinfo>
using namespace std;

class Exception
{

private:

    const char* message;

public:

    Exception(const char* m) :  message(m)
    {
        cout << "Exception created\n";
    }
    const char* GetMessage();



};

#endif // EXCEPTIONS_H
