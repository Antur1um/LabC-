#include "Cylinder.h"
#include "2Dgeometry.h"
#include "Exceptions.h"



#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <typeinfo>
using namespace std;

void Cylinder::InitFigure(Figure* f)
{
	this->f = CloneFigure(f);
}
double Cylinder::CalcVolume()
{
	return (f->CalcSpace()) * h;
}







Figure* CircleCylinder::CloneFigure(Figure* f)
{
	Circle* c = static_cast<Circle*>(f);
	return new Circle(c->GetR());
}
CircleCylinder* CircleCylinder::CreateInstance(Circle* f, double h)
{
	if (h <= 0) { Exception e = Exception(h, "Error in CircleCylinder"); throw e; }
	CircleCylinder* circleCylinder = new CircleCylinder(h);
	circleCylinder->InitFigure(f);
	return circleCylinder;
}







Figure* TriangleCylinder::CloneFigure(Figure* f)
{
	Triangle* t = static_cast<Triangle*>(f);
	return new Triangle(t->GetA(), t->GetB(), t->GetC());
}

TriangleCylinder* TriangleCylinder::CreateInstance(Triangle* f, double h)
{
	if (h <= 0) { Exception e = Exception(h, "Error in TriangleCylinder"); throw e; }

	TriangleCylinder* trianglecylinder = new TriangleCylinder(h);
	trianglecylinder->InitFigure(f);
	return trianglecylinder;
}
