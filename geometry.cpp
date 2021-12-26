
#include "Exceptions.h"
#include "geometry.h"
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <typeinfo>

using namespace std;



// // // //Circle // // //

    Circle::Circle(double r)
    {
        if (r <= 0) {Exception error = Exception("Wrong value in Circle"); throw error; }
        this->R = r;
    }

    Figure* Circle::Clone(){return new Circle(R);}


    double Circle::CalcSpace()
    {
        return R * R * M_PI;;
    }

    double Circle::GetR() { return R; }


// // // // Triangle // // // //

 double Triangle::CalcPer() { return (A + B + C) / 2; }

 bool Triangle::TestMySides(unsigned int a, unsigned int b, unsigned int c)
 {
     if (a + b >= c && a + c >= b && b + c >= a && a > 0 && b > 0 && c > 0) { return true; }
     else return false;
 }

Figure* Triangle::Clone(){return new Triangle(A,B,C);}


 double Triangle::CalcSpace()
 {
     double p = CalcPer();
     return sqrt(p * (p - A) * (p - B) * (p - C));
 }

double Triangle::GetA()
 {
     return A;
 }
double Triangle::GetB()
 {
     return B;
 }

double Triangle::GetC()
 {
     return C;
 }
