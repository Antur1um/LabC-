// Geometry.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;




//double CalcVolume(double h, Figure* f)
//{return h * f->CalcSpace();}


class Figure
{
public:

    //Figure() {};
    virtual double CalcSpace() { return 0; }
};

class Circle : public Figure
{
private:
    unsigned int R;

public:
    Circle(unsigned int r = 5) { R = 5; }

    double CalcSpace() { return R * R * M_PI; }
    unsigned int GetR() { return R; }
};

class Triangle :public Figure
{

private:
    unsigned int A, B, C;
public:

    Triangle(unsigned int a = 5, unsigned int b = 5, unsigned int c = 2)
    {
        if (TestMySides(a, b, c))
        {
            A = a;
            B = b;
            C = c;

        }
        else
        {
            cout << "It's imposible trangle \n";
            A = 5;
            B = 5;
            C = 5;
        }




    }
    double CalcPer() { return (A + B + C) / 2; }
    bool TestMySides(unsigned int a, unsigned int b, unsigned int c)
    {
        if (a + b >= c && a + c >= b && b + c >= a) { return true; }
        else return false;
    }
    double CalcSpace()
    {
        double p = CalcPer();
        return sqrt(p * (p - A) * (p - B) * (p - C));
    }
};



class Cylinder
{
private:
    Figure* type;
    double H;
public:
    Cylinder() {}

    Cylinder(double h, Figure* adr)
    {
        if (h > 0) { H = h; }
        type = adr;
    }


    double CalcVolume() { return H * type->CalcSpace(); }
};




class TriangleStar : public Figure
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
};

class LostSector : public Figure, public Circle
{
private:
    unsigned int Angle;
public:
    LostSector(unsigned int a)
    {
        Angle = a;

    }

    double Calcspace() { return (GetR() * GetR() * M_PI) - (GetR() * GetR() * Angle * M_PI) / (360); }
};




int main()
{
    Circle C;
    Triangle T(5, 5, 6);
    Figure* F = &C;
    Figure* F2 = &T;
    Cylinder cyl(5, F2);

    cout << "Space of Triangle" << "\n";
    cout << T.CalcSpace() << "\n";

    cout << "Volume of Cylinder \n ";

    cout << cyl.CalcVolume() << "\n";








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
