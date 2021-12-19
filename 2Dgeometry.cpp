
#include "Exceptions.h"
#include "2Dgeometry.h"
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <typeinfo>

using namespace std;


	Circle::Circle(unsigned int r)
	{
		if (r <= 0) {Exception error = Exception(0, "Error in Circle"); throw error; }
		this->R = r;
	}


	double Circle::CalcSpace()
	{
		return R * R * M_PI;;
	}

	unsigned int Circle::GetR() { return R; }




 double Triangle::CalcPer() { return (A + B + C) / 2; }

 bool Triangle::TestMySides(unsigned int a, unsigned int b, unsigned int c)
 {
	 if (a + b >= c && a + c >= b && b + c >= a && a > 0 && b > 0 && c > 0) { return true; }
	 else return false;
 }

 double Triangle::CalcSpace()
 {
	 double p = CalcPer();
	 return sqrt(p * (p - A) * (p - B) * (p - C));
 }

 unsigned int Triangle::GetA()
 {
	 return A;
 }

 unsigned int Triangle::GetB()
 {
	 return B;
 }

 unsigned int Triangle::GetC()
 {
	 return C;
 }
