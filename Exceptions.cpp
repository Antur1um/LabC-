
#pragma warning(disable : 4996)


#include <iostream>
#include <typeinfo>
#include "Exceptions.h"
using namespace std;


//Exception::Exception(int n, const char* m) : number(n), message(m)
//{
    //cout << "Exception created\n";
//}

const char* Exception::GetMessage() { return message; }
int Exception::GetN() { return number; }


