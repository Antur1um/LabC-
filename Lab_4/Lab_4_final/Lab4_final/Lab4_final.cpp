﻿// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Lab3(Моя).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <typeinfo>
//#include <Windows.h>

using namespace std;


class Datetime
{
private:
    unsigned int second, minute, hour, day, month, year;


public:
    Datetime() {
        second = 0;
        minute = 0;
        hour = 0;
        day = 1;
        month = 1;
        year = 1970;

        cout << "Construct оf date is work\n";
    }

    ~Datetime() { cout << "Destruct of date is work \n "; };



   unsigned int GetSecond()
    {
        if (second < 60) {return second; }

        else cout << "\n The second error! \n ";
    }

   unsigned int GetMinute()
    {
        if (minute < 60) { return minute; }

        else { cout << "\n The minute error \n"; }
    }

   unsigned int GetHour(int& v)
    {
        if (hour <= 23) {return hour; }

        else cout << "\n* The hour error \n ";
    }

   unsigned int GetDay()
    {
        if (day <= 31) { return day; }
           

        else cout << "\n* The day error \n ";
    }

   unsigned int GetMonth(int& v)
    {
        if (month <= 12) { return month; }

        else cout << "\n* The month error \n ";
    }

   unsigned int GetYear(int& v)
    {
        if (year >= 0) {return year;}

        else cout << "\n* The year error \n ";
    }

    void AddDate(unsigned int d, unsigned int mon, unsigned int y, unsigned int h, unsigned int min, unsigned int sec) {
        if (sec < 60)
            second = sec;
        else
            cout << "\n The second error! \n ";


        if (min < 60)
            minute = min;
        else
            cout << "\n The minute error \n";


        if (h < 24)
            hour = h;
        else
            cout << "\n* The hour error \n ";


        if (d < 32)
            day = d;
        else
            cout << "\n* The day error \n ";


        if (mon < 13)
            month = mon;
        else
            cout << "\n* The month error \n ";


        if (y >= 0)
            year = y;
        else
            cout << "\n* The year error \n ";
    }


   virtual void Print()
    {
        if (day < 10) { cout << 0; } cout << day << ".";
        if (month < 10) { cout << 0; } cout << month << "." << year << "  ";
        if (hour < 10) { cout << 0; } cout << hour << ":";
        if (minute < 10) { cout << 0; } cout << minute << ":";
        if (second < 10) { cout << 0; } cout << second << "\n";




        //cout << day << "." << month << "." << year << " " << hour << ":" << minute << ":" << second << "\n";
    }

   /* void AddDate(unsigned int d, unsigned int mon, unsigned int y, unsigned int h, unsigned int min, unsigned int sec)
    {
        day = d;
        month = mon;
        year = y;
        hour = h;
        minute = min;
        second = sec;
    }*/


    /* void GetCurrentDate()
      {
          time_t
              now = time(0);
          struct tm  tstruct;
          char buf[80];
          tstruct = *localtime(&now);

          strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

          cout << "System date: " << buf << endl;
      }*/

      /* void CurrentDate()
       {
           SYSTEMTIME st;
           GetLocalTime(&st);

           second = st.wSecond;
           minute = st.wMinute;
           hour = st.wHour;
           day = st.wDay;
           month = st.wMonth;
           year = st.wYear;
       }*/







};


class NDatetime :public Datetime {

public:
    unsigned int Msec{};
    NDatetime() :Datetime() { cout << "Ndate greated"; }

    unsigned int GetMseconnd()
    {
        if (Msec >= 0 && Msec <= 999) { return Msec; }
        else cout << "\n* The msecond error ";
    }

    void AddDateExt(int ms, int sd, int me, int hr, int dy, int mh, int yr)
    {
    
        AddDate(sd, me, hr, dy, mh, yr);

        if (ms >= 0 && ms <= 999)
            Msec = ms;
        else
            cout << "\n* Error invalid mseconds values! ";
    
    
          }
    void Print
    {
    if (day < 10) { cout << 0; } cout << day << ".";
    if (month < 10) { cout << 0; } cout << month << "." << year << "  ";
    if (hour < 10) { cout << 0; } cout << hour << ":";
    if (minute < 10) { cout << 0; } cout << minute << ":";
    if (second < 10) { cout << 0; } cout << second << "\n"; 
    if (Msec < 10) { cout << 00; } cout << Msec << "\n";
    else if (Msec < 100) { cout << Msec << "\n"; }
    else cout << Msec << "\n";
    
    
    
    }
};



class Node {

public:
    Node* prev;
    Node* next;
    NDatetime* data;

    Node() {
        prev = NULL;
        next = NULL;
        data = new NDatetime;
        cout << "\n Node is greated \n";

    };

    void AddNode(unsigned int d, unsigned int mon, unsigned int y, unsigned int h, unsigned int min, unsigned int sec)
    {
        Datetime* newObj = new Datetime;
        data = newObj;
        newObj->AddDate(d, mon, y, h, min, sec);
        cout << "Node created\n";
    }
};



class List {
private:
    Node* First;
    Node* Last;
    Node* C;
public:
    List() {
        First = NULL;
        Last = NULL;
        C = NULL;
    }

    ~List() {};

    void AddElement(unsigned int d, unsigned int mon, unsigned int y, unsigned int h, unsigned int min, unsigned int sec)
    {

        if (First == NULL) {
            Node* temp = new Node;

            temp->next = NULL;
            temp->prev = NULL;

            C = temp;
            First = temp;
            Last = temp;

            temp->AddNode(d, mon, y, h, min, sec);

        }
        else if (First != NULL && Last != NULL)
        {
            Node* tem = new Node;
            if (First == Last) {

                tem->prev = First;
                tem->next = NULL;
                tem->prev->next = tem;

                C = tem;
                Last = tem;

                tem->AddNode(d, mon, y, h, min, sec);

            }

            if (First != Last && C != Last) {

                tem->prev = C;
                tem->next = C->next;
                C->next->prev = tem;
                C->next = tem;

                C = tem;

                tem->AddNode(d, mon, y, h, min, sec);

            }

            if (C == Last && First != Last) {

                tem->prev = C;
                tem->next = NULL;
                C->next = tem;

                Last = tem;
                C = tem;

                tem->AddNode(d, mon, y, h, min, sec);

            }


        }


    }

    void MoveNext()
    {

        /* if (C != NULL)*/ C = C->next;

    };
    void MovePrev()
    {
        /*if (C != NULL)*/ C = C->prev;
    };

    void PrintList()
    {
        if (First != NULL) {

            Node* temp = C;
            C = First;
            while (C != NULL)
            {
                C->data->Print();
                MoveNext();
            }
        }
        else { cout << "Empty\n"; }

    }

    void PrintListSort()
    {

        if (First != NULL) {

            Node* temp = C;
            C = First;
            while (C != NULL) {
                if (C->next != NULL) {
                    cout << "Date: ";  C->data->Print(); cout << " Next date: "; C->next->data->Print(); cout << endl;
                    MoveNext();
                }
                if (C->next == NULL) {
                    cout << "Date: ";  C->data->Print(); cout << " Next date: not found :(" << endl;
                    break;
                }
            }
        }
    }


    void GetF(string filename)
    {


        unsigned int sec, min, h, d, mon, y;

        ifstream fin(filename);

        if (fin) {




            while (fin >> d >> mon >> y >> h >> min >> sec) {
                cout << d << "." << mon << "." << y << "  " << h << ":" << min << ":" << sec << "\n";
                AddElement(d, mon, y, h, min, sec);

            }
        }
        else {
            cout << "Error! Current file not found!";
        }

        fin.close();
    }

};



class ListExt : public List 
{










};



class FileWork {

public:
    void GetFile(string filename, List L) //не передавать class'ы по значению(ссылки или указатели)!!!
    {

        unsigned int sec, min, h, d, mon, y;

        ifstream fin(filename);

        if (fin) {




            while (fin >> d >> mon >> y >> h >> min >> sec) {
                cout << d << "." << mon << "." << y << "  " << h << ":" << min << ":" << sec << "\n";
                L.AddElement(d, mon, y, h, min, sec);

            }
        }
        else {
            cout << "Error! Current file not found!";
        }

        fin.close();
    }


};




class App {
public:
    void start()
    {

        NDatetime LL;
        List list;

        list.GetF("Date.txt");

        //List* L = &list;


        //FileWork file;

        //file.GetFile("Date(2).txt", list);



        int key = -1;
        do {

            cout << "----MENU----" << endl;
            cout << "1) Print All" << endl;
            cout << "2) Print sort" << endl;
            cout << "3) Input from keyboard" << endl;
            cout << "0) Exit" << endl << endl;

            cout << "Insert key->"; cin >> key;

            switch (key)
            {
            case 1: {

                list.PrintList();

                break;
            }

            case 2: {

                list.PrintListSort();

                break;
            }

            case 3: {
                //Datetime sysTime;
                //sysTime.GetCurrentDate();
                unsigned int sec, min, h, d, mon, y;
                cout << "day = "; cin >> d;
                cout << "month = "; cin >> mon;
                cout << "year = "; cin >> y;
                cout << "hour = "; cin >> h;
                cout << "minute = "; cin >> min;
                cout << "second = "; cin >> sec;


                list.AddElement(d, mon, y, h, min, sec);
                break;
            }

            default:

                if (key != 0) cout << "Error! Not found in menu!" << endl;

                break;
            }

        } while (key != 0);

    }

};



class UI {






};



int main()
{
    App app;

    app.start();

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
