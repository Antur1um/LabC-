// Lab 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*#include "stdafx.h"*/
#include <iostream>
#include <string>
#include <fstream>
//#include <ctime>
//#include <chrono>
#include <sstream>
#include <Windows.h>
#include <typeinfo>

using namespace std;

unsigned short int charToNum(char str);

int Count = 0;





struct datetime
{
	struct Node
	{
		unsigned int second{};
		unsigned int minute{};
		unsigned int hour{};
		unsigned int day{};
		unsigned int month{};
		unsigned int year{};
		unsigned int counter{};
		Node* next;
		Node* prev;
	};



	Node* First = NULL;
	Node* Last = NULL;
	Node* Curent = NULL;
	int Count{};

	
	void Info();
	//void Clear();

	bool TestData(unsigned int sec, unsigned int min, unsigned int h, unsigned int d, unsigned int mon, unsigned int y);


	void TestPrevDate();
	


	void sysTime();
	void PrintInfo();
	
	void printNext();
	void printPrev();
	//bool Del();

	bool MoveNext();
	bool MovePrev();
	bool MoveFirst();
	bool MoveLast();

	bool Init(unsigned int sec, unsigned int min, unsigned int h, unsigned int d, unsigned int mon, unsigned int y);
	bool AddNext(unsigned int sec, unsigned int min, unsigned int h, unsigned int d, unsigned int mon, unsigned int y);


	//bool Del(int&, string&, double&, bool&);
	

	void GetFile(datetime S, string filename);

	

};


void datetime::TestPrevDate()
{
	
	



	for (Node* i = First->next; i; i = i->next) {

		//for( i; i->prev; i = i->prev)
		//{
		//cout << "It's here?";

		if (i->prev->year != i->year)
		{
			
			cout << i->counter << " . ";
			if (i->day < 10) { cout << 0; } cout << i->day << ".";
			if (i->month < 10) { cout << 0; } cout << i->month << "." << i->year << "  ";
			if (i->hour < 10) { cout << 0; } cout << i->hour << ":";
			if (i->minute < 10) { cout << 0; } cout << i->minute << ":";
			if (i->second < 10) { cout << 0; } cout << i->second << "\n";


			//cout << Curent->counter << " . ";
			if (i->prev->day < 10) { cout << 0; } cout << i->prev->day << ".";
			if (i->prev->month < 10) { cout << 0; } cout << i->prev->month << "." << i->prev->year << "  ";
			if (i->prev->hour < 10) { cout << 0; } cout << i->prev->hour << ":";
			if (i->prev->minute < 10) { cout << 0; } cout << i->prev->minute << ":";
			if (i->prev->second < 10) { cout << 0; } cout << i->prev->second << "\n \n \n";
		}

      }
	  


		
}

bool datetime::TestData(unsigned int sec, unsigned int min, unsigned int h, unsigned int d, unsigned int mon, unsigned int y)
{
	if (sec > 60 || min > 60 || h > 60 || d > 31 || mon > 12 || y > 9999) { return false; }
	else { return true;}
}

void datetime::sysTime()
{

	SYSTEMTIME st;
	GetLocalTime(&st);

	AddNext(st.wSecond, st.wMinute, st.wHour, st.wDay, st.wMonth, st.wYear);
}

bool datetime::Init(unsigned int sec,unsigned int min, unsigned int h, unsigned int d, unsigned int mon, unsigned int y)
{
	if (!First)
	{
		Count = 1;
		First = new Node;
		Last = First;
		Curent = First;
		First->prev = NULL;
		First->next = NULL;
		First->second = sec;
		First->minute = min;
		First->hour = h;
		First->day = d;
		First->month = mon;
		First->year = y;
		First->counter = Count;
		return true;

	}

	else {
		cout << "Error"; return false;
	}
}

bool datetime::AddNext(unsigned int sec, unsigned int min, unsigned int h, unsigned int d, unsigned int mon, unsigned int y)
{
	datetime S;

	if (!First) return Init(sec, min, h, d, mon, y);

	Count++;
	Node* temp = Curent->next;
	Curent->next = new Node;
	Curent->next->next = temp;
	Curent->next->prev = Curent;

	if (!temp)
		Last = Curent->next;
	else
		temp->prev = Curent->next;

	Curent = Curent->next;


	if (!S.TestData(sec, min, h, d, mon, y)) { cout << "Error\n"; return false; }

	Curent->second = sec;
	Curent->minute = min;
	Curent->hour = h;
	Curent->day = d;
	Curent->month = mon;
	Curent->year = y;
	Curent->counter = Count;

	return true;
}

bool datetime::MoveNext()
{
	if (!First) return false;
	if (!Curent) { Curent = First; return true; }
	if (!Curent->next) return false;
	Curent = Curent->next;
	return true;
}

bool datetime::MovePrev()
{
	if (!First) return false;
	if (!Curent) { Curent = First; return true; }
	if (!Curent->prev) return false;
	Curent = Curent->prev;
	return true;
}

bool datetime::MoveFirst()
{
	if (!First)return false;
	Curent = First;
	return true;
}


bool datetime::MoveLast()
{
	if (!Last)return false;
	Curent = Last;
	return true;
}


void datetime::GetFile(datetime S, string filename)
{
	unsigned int sec;
	unsigned int min;
	unsigned int h;
	unsigned int day;
	unsigned int mon;
	unsigned int y;

	ifstream f(filename);
	Node data;
	if (f)
	{
		while (!f.eof())
		{
			string temp;
			f >> temp;

			day = charToNum(temp[0]);
			day *= 10;
			day += charToNum(temp[1]);

			mon = charToNum(temp[3]);
			mon *= 10;
			mon += charToNum(temp[4]);

			y = charToNum(temp[6]);
			y *= 10;
			y += charToNum(temp[7]);
			y *= 10;
			y += charToNum(temp[8]);
			y *= 10;
			y += charToNum(temp[9]);

			f >> temp;

			h = charToNum(temp[0]);
			h *= 10;
			h += charToNum(temp[1]);

			min = charToNum(temp[3]);
			min *= 10;
			min += charToNum(temp[4]);

			sec = charToNum(temp[6]);
			sec *= 10;
			sec += charToNum(temp[7]);

			
			if (!S.TestData(sec, min, h, day, mon, y)) { cout << "Error\n"; return; }



			S.AddNext(sec, min, h, day, mon, y);
			S.MoveNext();
		}
	}
	f.close();
}

void datetime::PrintInfo()
{
	{
		if (!First) { cout << "Empty\n"; return; }


		Node* temp = First;

		cout << "Current list: \n";
		do
		{    
			cout << temp->counter << " . ";
			if (temp->day < 10) { cout << 0; } cout << temp->day << ".";
			if (temp->month < 10) { cout << 0; } cout << temp->month << "." << temp->year<<"  ";
			if (temp->hour < 10) { cout << 0; } cout << temp->hour << ":";
			if (temp->minute < 10) { cout << 0; } cout << temp->minute << ":";
			if (temp->second < 10) { cout << 0; } cout << temp->second << "\n";

			temp = temp->next;
		} while (temp);
	}

	MoveFirst();

}

void datetime::Info()
{
	/*if (Count) { cout << "\nNow you have: " << Count << " Watches\n"; }
	else { cout << "List is empty\n"; }*/
	if (Curent) {

		cout << "\nCurent date its:\n ";
		cout << Curent->counter << " . ";
		if (Curent->day < 10) { cout << 0; } cout << Curent->day << ".";
		if (Curent->month < 10) { cout << 0; } cout << Curent->month << "." << Curent->year << "  ";
		if (Curent->hour < 10) { cout << 0; } cout << Curent->hour << ":";
		if (Curent->minute < 10) { cout << 0; } cout << Curent->minute << ":";
		if (Curent->second < 10) { cout << 0; } cout << Curent->second << "\n";
	}


	else cout << " Empty \n ";



}

void datetime::printNext()
{
	MoveNext();
	Node* temp = Curent;
	cout << temp->counter << " . ";
	if (temp->day < 10) { cout << 0; } cout << temp->day << ".";
	if (temp->month < 10) { cout << 0; } cout << temp->month << "." << temp->year << "  ";
	if (temp->hour < 10) { cout << 0; } cout << temp->hour << ":";
	if (temp->minute < 10) { cout << 0; } cout << temp->minute << ":";
	if (temp->second < 10) { cout << 0; } cout << temp->second << "\n";

}

void datetime::printPrev()
{
	MovePrev();
	Node* temp = Curent;
	cout << temp->counter << " . ";
	if (temp->day < 10) { cout << 0; } cout << temp->day << ".";
	if (temp->month < 10) { cout << 0; } cout << temp->month << "." << temp->year << "  ";
	if (temp->hour < 10) { cout << 0; } cout << temp->hour << ":";
	if (temp->minute < 10) { cout << 0; } cout << temp->minute << ":";
	if (temp->second < 10) { cout << 0; } cout << temp->second << "\n";



}


struct timedelta {
	short int second;
	short int minute;
	short int hour;
	short int day;
	short int month;
	short int year;

	void minus(datetime t1, datetime t2);
	datetime timePlus(datetime t);
	void plusDelta(timedelta d);
};


void timedelta::minus(datetime t1, datetime t2) {
	second = t1.second - t2.second;
	minute = t1.minute - t2.minute;
	hour = t1.hour - t2.hour;
	day = t1.day - t2.day;
	month = t1.month - t2.month;
	year = t1.year - t2.year;
}


datetime timedelta::timePlus(datetime t) {
	t.second -= second;
	t.minute -= minute;
	t.hour -= hour;
	t.day -= day;
	t.month -= month;
	t.year -= year;

	return t;
}

void timedelta::plusDelta(timedelta d) {
	second -= d.second;
	minute -= d.minute;
	hour -= d.hour;
	day -= d.day;
	month -= d.month;
	year -= d.year;
}




unsigned short int charToNum(char str) {
	if (str == '0') return 0;
	else if (str == '1') return 1;
	else if (str == '2') return 2;
	else if (str == '3') return 3;
	else if (str == '4') return 4;
	else if (str == '5') return 5;
	else if (str == '6') return 6;
	else if (str == '7') return 7;
	else if (str == '8') return 8;
	else if (str == '9') return 9;

	return 256;
}







int main()
{
	datetime test;
	
	

	unsigned int sec = 5;
	unsigned int min = 10;
	unsigned int h = 15;
	unsigned int day = 17;
	unsigned int mon =  07;
	unsigned int y = 2017;



	test.Init(sec, min, h, day, mon, y);
	test.GetFile(test, "input.txt");
	test.Info();
	test.PrintInfo();
	cout << "Test\n";
	test.MoveFirst();
	//test.sysTime();

	//test.Info();
	//test.MoveLast();
	test.TestPrevDate();
	//test.PrintInfo();



	



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
