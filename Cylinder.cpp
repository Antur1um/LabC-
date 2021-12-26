#include "Cylinder.h"
#include "geometry.h"
#include "Exceptions.h"




#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <typeinfo>
using namespace std;




// // // Cylinder // // //
/*void Cylinder::InitFigure(Figure* f)
{
    this->F = CloneFigure(f);
}*/


double Cylinder::CalcVolume()
{
    return (F->CalcSpace()) * h;
}

double Cylinder::GetH(){ return h;}

double Cylinder::GetSquare(){return F->CalcSpace();}


 // // // // CircleCylinder // // //



CircleCylinder::CircleCylinder(double h, Figure* f):Cylinder(h,f){}

double CircleCylinder::GetR()
{

    Circle* c = static_cast<Circle*>(F);
        return c->GetR();

}



unsigned short CircleCylinder::WhatType(){return 0;}



// // // //Triangle cylinder // // // //

TriangleCylinder::TriangleCylinder(double h,Figure* f):Cylinder(h,f){};

double TriangleCylinder::GetA()
{
   Triangle* b =  static_cast<Triangle*>(F);
   return b->GetA();
}

double TriangleCylinder::GetB()
{
   Triangle* b =  static_cast<Triangle*>(F);
   return b->GetB();
}

double TriangleCylinder::GetC()
{
   Triangle* b =  static_cast<Triangle*>(F);
   return b->GetC();
}


unsigned short TriangleCylinder::WhatType(){return 1;}






// // // Cylinder collection // // // //



Cylinder* CylinderCollection::getCylinder(int n)
{
   return shape[n];
}

double CylinderCollection::getNumber()
{
    return N;
}
void  CylinderCollection::AddCylinder(Cylinder* new_shape)
{
     N++;

     shape.emplace_back(new_shape);
}

void CylinderCollection::delCylinder(int number)
{

       shape.erase(shape.cbegin()+number);
       N--;

}

CylinderCollection::~CylinderCollection()
{
    shape.clear();
    shape.shrink_to_fit();
}









