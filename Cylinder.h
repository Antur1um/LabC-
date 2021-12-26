#ifndef CYLINDER_H
#define CYLINDER_H
#pragma once

#include "geometry.h"
#include "Exceptions.h"
#include <vector>
#include <QString>



class Cylinder
{



protected:

Figure* F{};
double h{};


    Cylinder(double h,Figure* f)
    {

    if(h>0)
    {
        this->h = h;
        F = f->Clone();

       }

    else{Exception e("Wrong height vlue"); throw e; }


    }

    //void InitFigure(Figure* f);

    //virtual Figure* CloneFigure(Figure* f) = 0;



public:


    virtual unsigned short WhatType()=0;
    virtual ~Cylinder() {delete F;}
    double CalcVolume();


    double GetH();
    double GetSquare();

};




class CircleCylinder : public Cylinder
{
public:
       CircleCylinder(double, Figure*);

       //void setRadius(double);
       double GetR();
        virtual unsigned short WhatType();



    virtual ~CircleCylinder() {}


};



class TriangleCylinder : public Cylinder
{

public:
    TriangleCylinder(double, Figure*);

     virtual unsigned short WhatType();


            double GetA();
            double GetB();
            double GetC();


    virtual ~TriangleCylinder() {}
};



class CylinderCollection

{
private:

   unsigned short N=0;    // Счетчик Фигур

   vector <Cylinder*> shape;

public:




    void AddCylinder(Cylinder*);
      void delCylinder(int);

    Cylinder* getCylinder(int);  // Получение фигуры по номеру
    QString GetType(int);
    double getNumber();

     ~CylinderCollection();



};





















#endif // CYLINDER_H
