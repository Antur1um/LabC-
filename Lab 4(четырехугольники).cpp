// Lab 4(четырехугольники).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#define PI 3.14159265

using namespace std;

class Parall {
private:
    unsigned int _w;
    unsigned int _l;
    unsigned int _h;
public:
    Parall(unsigned int w = 1, unsigned int l = 1, unsigned int h = 1)
    {
        _w = w;
        _h = h;
        _l = l;
    }

    unsigned int getHeight() {return _h;}
    unsigned int getWidth() { return _w; }
    unsigned int getLength() { return _l; }

    void setHeight(unsigned int h = 1) {_h = h;}
    void setWidth(unsigned int w = 1) {_w = w;}
    void setLength(unsigned int l = 1) {_l = l;}

    virtual double calcVolume() {return _w * _h * _l;}
};

class Circle : public Parall {
private:
    unsigned int _r;
public:
    Circle(unsigned int r = 1, unsigned int h = 1) {_r = r; setHeight(h);}

    virtual double calcVolume() {
        return (PI * getHeight() * (_r * _r));
    }
};

class Triangle : public Parall {
public:
    Triangle(unsigned int w = 1, unsigned int l = 1, unsigned int h = 1) {
        setHeight(h);
        setWidth(w);
        setLength(l);
    }

    virtual double calcVolume() {
        return ((getWidth() * getLength()) / 2) * getHeight();
    }
};

int main() {
    

    Parall _par = { 4, 4, 4 };
    Parall& _buf = _par;
  cout << "Space of parall  = " << _buf.calcVolume() << "\n";
    cout << _par.calcVolume() << "\n\n";

    Circle _circ = { 5, 5 };
    Parall& _buf2 = _circ;
    cout << "Space of cylinder = " << _buf2.calcVolume() << "\n";
    cout << _circ.calcVolume() << "\n\n";

    Triangle _tri = { 4, 4, 4 };
    Parall& _buf3 = _tri;
   cout << "Space of Rectangle = " << _buf3.calcVolume() << "\n";
   cout << _tri.calcVolume() << "\n\n";

    return 0;
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
