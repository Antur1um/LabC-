// Final_Lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Cylinder.h"
#include "2Dgeometry.h"
#include "Exceptions.h"

#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <typeinfo>
using namespace std;


int main()
{
	cout << "Start" << endl;

    Triangle* t = new Triangle(5, 5, 2);

    Figure* f = new Circle(5);




    cout << t->CalcSpace() << "\n";

    cout << f->CalcSpace() << "\n";





    CircleCylinder* circleCylinder = CircleCylinder::CreateInstance(static_cast<Circle*>(f), 2);

    TriangleCylinder* trianglecylinder = TriangleCylinder::CreateInstance(static_cast<Triangle*>(t), 5);



    cout << "Volume(Circle): " << circleCylinder->CalcVolume() << endl;

    cout << "Volume(Triangle): " << trianglecylinder->CalcVolume() << endl;




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
