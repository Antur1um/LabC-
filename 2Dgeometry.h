#pragma once

#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <typeinfo>
#include "Exceptions.h"
using namespace std;


class Figure
{
public:

    Figure() {};
    virtual ~Figure() {}
    virtual double CalcSpace() = 0;
};




    class Circle : public Figure
    {
    private:
        unsigned int R;

    public:

        Circle(unsigned int  r);



        virtual ~Circle() {}




        double CalcSpace();
        unsigned int GetR();
    };





class Triangle :public Figure
{

private:
    unsigned int A, B, C;
public:

    Triangle(unsigned int a = 5, unsigned int b = 5, unsigned int c = 2)
    {
        if (!TestMySides(a, b, c))
        {

            Exception e(a, "It is imposible triangle"); throw e;
        }
        else
        {
            A = a;
            B = b;
            C = c;
        }




    }
    double CalcPer();
    bool TestMySides(unsigned int a, unsigned int b, unsigned int c);

    double CalcSpace();
    
    unsigned int GetA();

    unsigned int GetB();

    unsigned int GetC();


};


