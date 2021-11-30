// Lab_9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Lab_8-Exeception.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Geometry.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <typeinfo>
using namespace std;




//double CalcVolume(double h, Figure* f)
//{return h * f->CalcSpace();}

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




    const char* GetMessage() { return message; }
    int GetN() { return number; }

};

class Figure
{
public:

    Figure() {};
    virtual ~Figure() {}
    virtual double CalcSpace() = 0;
};


template<typename T>
class New_Circle:public Figure {

private:
    T R;

public:

    New_Circle(T r) :Figure()
    {
        if (r <= 0 ) { Exception error = Exception(0, "Error in Circle"); throw error; }
        this->R = r;
    }
    double CalcSpace() { return R * R * M_PI; }
    T GetR() { return R; }

};
/*
template<>
class New_Circle<double>:public Figure
{
private:
    double R;

public:

    New_Circle(double r) :Figure()
    {
        if (r <= 0 ) { Exception error = Exception(0, "Error in Circle"); throw error; }
        this->R = r;
    }





    virtual double CalcSpace() { return R * R * M_PI; }
    double GetR() { return R; }

};


template<>
class New_Circle<int> :public Figure
{
private:
    int R;

public:

    New_Circle(int r) :Figure()
    {
        if (r <= 0) { Exception error = Exception(0, "Error in Circle"); throw error; }
        this->R = r;
    }


    virtual double CalcSpace() { return R * R * M_PI; }
    int GetR() { return R; }

};

*/



template<typename T>
class New_Triangle :public Figure {

private:
    T A, B, C;

public:

    New_Triangle(T a , T b, T c )
    {
        if (!TestMySides(a, b, c) || typeid(a).name()!="int" || typeid(a).name()!="double")
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
    double CalcPer() { return (A + B + C) / 2; }
    bool TestMySides(T a, T b, T c)
    {
        if (a + b >= c && a + c >= b && b + c >= a && a > 0 && b > 0 && c > 0) { return true; }
        else return false;
    }


    double CalcSpace()
    {
        double p = CalcPer();
        return sqrt(p * (p - A) * (p - B) * (p - C));
    }

    T GetA() { return A; }

    T GetB() { return B; }

    T GetC() { return C; }



};



class Circle : public Figure
{
private:
    unsigned int R;

public:
    
    Circle(unsigned int  r) :Figure()
    {
        if (r <= 0) { Exception error = Exception(0, "Error in Circle"); throw error; }
        this->R = r;
    }


    virtual ~Circle() {}




    virtual  double CalcSpace() { return R * R * M_PI; }
    unsigned int GetR() { return R; }
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
    double CalcPer() { return (A + B + C) / 2; }
    bool TestMySides(unsigned int a, unsigned int b, unsigned int c)
    {
        if (a + b >= c && a + c >= b && b + c >= a && a > 0 && b > 0 && c > 0) { return true; }
        else return false;
    }
    double CalcSpace()
    {
        double p = CalcPer();
        return sqrt(p * (p - A) * (p - B) * (p - C));
    }

    unsigned int GetA() { return A; }

    unsigned int GetB() { return B; }

    unsigned int GetC() { return C; }


};



/*class TriangleStar : public Figure
{
private:
    unsigned int A, B;
public:
    TriangleStar(unsigned int a, unsigned int b)
    {
        A = a;
        B = b;
    }
    double Calcspace() { return ((A * B) / 8) * 4; }

    unsigned int GetA() { return A; }

    unsigned int GetB() { return B; }



};*/




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


    void InitFigure(Figure* f)
    {
        cout << "Cylinder::Init" << endl;
        this->f = CloneFigure(f);
    }




    virtual Figure* CloneFigure(Figure* f) = 0;
public:
    virtual ~Cylinder()
    {
        cout << "Cylinder::~Cylinder" << endl;
    }

    double CalcVolume()
    {
        cout << "Cylinder::CalcVolume" << endl;
        return (f->CalcSpace()) * h;
    }




};

class CircleCylinder : public Cylinder
{
protected:
    CircleCylinder(double h) :Cylinder(h)
    {
        cout << "CircleCylinder::CircleCylinder \n";
    }
    virtual Figure* CloneFigure(Figure* f)
    {
        cout << "CircleCylinder::CreateFigure" << endl;
        Circle* c = static_cast<Circle*>(f);
        return new Circle(c->GetR());
    }


public:
    static CircleCylinder* CreateInstance(Circle* f, double h)
    {

        if (h <= 0) { Exception e = Exception(h, "Error in CircleCylinder"); throw e; }
        CircleCylinder* circleCylinder = new CircleCylinder(h);
        circleCylinder->InitFigure(f);
        return circleCylinder;
    }

    virtual ~CircleCylinder()
    {
        cout << "CircleCylinder::~CircleCylinder" << endl;
    }

};

class TriangleCylinder : public Cylinder
{

protected:
    TriangleCylinder(double h) :Cylinder(h)
    {

        cout << "triangle cylinder created \n";
    }
    virtual Figure* CloneFigure(Figure* f)
    {
        Triangle* t = static_cast<Triangle*>(f);
        return new Triangle(t->GetA(), t->GetB(), t->GetC());
    }

public:

    static TriangleCylinder* CreateInstance(Triangle* f, double h)
    {
        if (h <= 0) { Exception e = Exception(h, "Error in TriangleCylinder"); throw e; }

        TriangleCylinder* trianglecylinder = new TriangleCylinder(h);
        trianglecylinder->InitFigure(f);
        return trianglecylinder;
    }

    virtual ~TriangleCylinder() {}
};





template<typename T>
class NewCylinder {

private:
    T base;
    double H;

public:

    NewCylinder(T f, double h)
    {
        base = f;
        H = h;

    }


    double CalcVolume()
    {
        return base->CalcSpace() * H;
    }

};
















/*class StarCylinder : public Cylinder
{

protected:

    StarCylinder(double h) :Cylinder(h)
    {
        cout << "Triangle cylinder created \n";
    }


    virtual Figure* CloneFigure(Figure* f)
    {
        TriangleStar* s = static_cast<TriangleStar*>(f);
        return new TriangleStar(s->GetA(), s->GetB());
    }

public:

    static StarCylinder* CreateInstance(TriangleStar* f, double h)
    {
        StarCylinder* starcyl = new StarCylinder(h);
        starcyl->InitFigure(f);
        return starcyl;
    }

    virtual ~StarCylinder() {}


};*/


/*class LostSector : public Figure, public Circle
{
private:
    unsigned int Angle;
public:
    LostSector(unsigned int a)
    {
        Angle = a;

    }

    double Calcspace() { return (GetR() * GetR() * M_PI) - (GetR() * GetR() * Angle * M_PI) / (360); }
};*/


//Шаблонные конструкторы для фигур.

int main()
{



    cout << "Start" << endl;

   
    Figure* f = new Circle(5);
    Figure* t = new New_Circle<double>(3.14);
    Figure* i = new New_Circle<int>(1);
    Figure* e = new New_Circle<unsigned int>(1);


    Figure* w = new New_Triangle<unsigned int>(5,5,2);

    Figure* q = new New_Triangle<double>(5.5, 5, 2);



    
    cout << f->CalcSpace() << "\n";
    cout << t->CalcSpace() << "\n";
    cout << i->CalcSpace() << "\n";
    cout << e->CalcSpace() << "\n";




    cout << w->CalcSpace() << "\n";

    cout <<q->CalcSpace() << "\n";

   



    //Triangle* t = new Triangle(5, 5, 2);

   //NewCylinder<Triangle*>  Cyl(t, 1);

    //cout << "New Cylinder   " << Cyl.CalcVolume() << "\n";

    //................................................................................	

 /* try

    {
      Figure* f = new Circle("5");
    }


    catch (Exception e)
    {

        cout << "Catch exception" << e.GetMessage() << " : " << e.GetN();


    }*/



    /*

    CircleCylinder* circleCylinder = CircleCylinder::CreateInstance(static_cast<Circle*>(f), 2);

    TriangleCylinder* trianglecylinder = TriangleCylinder::CreateInstance(static_cast<Triangle*>(t), 5);



    cout << "Volume(Circle): " << circleCylinder->CalcVolume() << endl;

    cout << "Volume(Triangle): " << trianglecylinder->CalcVolume() << endl;



    delete circleCylinder;
    delete trianglecylinder;
    cout << "Finish" << endl;
    return 0;*/


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
