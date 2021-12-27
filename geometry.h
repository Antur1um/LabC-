#ifndef GEOMETRY_H
#define GEOMETRY_H
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
    virtual Figure* Clone()=0;
    virtual double CalcSpace() = 0;
};






class Circle : public Figure
    {
    private:
        double R;

    public:

        Circle(double  r);



        virtual ~Circle() {}


     virtual Figure* Clone();

        double CalcSpace();
        double GetR();
    };





class Triangle :public Figure
{

private:
   double A, B, C;
public:

    Triangle(double a , double b , double c )
    {
        if (!TestMySides(a, b, c))
        {

            Exception e("It is imposible triangle"); throw e;
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

     virtual Figure* Clone();

    double CalcSpace();

   double GetA();

    double GetB();

    double GetC();


};
#endif // GEOMETRY_H
