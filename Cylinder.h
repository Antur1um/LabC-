#pragma once

#include "2Dgeometry.h"
#include "Exceptions.h" 


class Cylinder
{
private:
    Figure* f{};
    double h{};
protected:
    Cylinder(double h)
    {

        cout << "Cylinder::Cylinder" << endl;
        this->h = h;
    }


    void InitFigure(Figure* f);
 
    virtual Figure* CloneFigure(Figure* f) = 0;



public:
    virtual ~Cylinder() {}
   

    double CalcVolume();
   




};

class CircleCylinder : public Cylinder
{
protected:
    CircleCylinder(double h) :Cylinder(h) {}
    virtual Figure* CloneFigure(Figure* f);
   


public:
    static CircleCylinder* CreateInstance(Circle* f, double h);
  

    virtual ~CircleCylinder() {}
 

};

class TriangleCylinder : public Cylinder
{

protected:
    TriangleCylinder(double h) :Cylinder(h){}
    virtual Figure* CloneFigure(Figure* f);
 

public:

    static TriangleCylinder* CreateInstance(Triangle* f, double h);

    virtual ~TriangleCylinder() {}
};





