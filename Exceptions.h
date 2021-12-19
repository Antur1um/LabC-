#pragma once


#include <iostream>
#include <typeinfo>
using namespace std;

class Exception
{

private:
    int number;
    const char* message;

public:

    Exception(int n, const char* m) : number(n), message(m)
    {
        cout << "Exception created\n";
    }
    const char* GetMessage();
    int GetN();


};

