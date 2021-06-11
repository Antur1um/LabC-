// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;



struct Tree
{
	int capacity{};
	string manufacter{};
	double price{};
	bool Have{};
	Tree* Left{};
	Tree* Right{};
};


void Add(int Capacity, string manufacter, double price, bool have, Tree*& aBranch);
void AddL(int Capacity, string manufacter, double price, bool have, Tree*& aBranch);

void GetFile(string filename, Tree*& T);
void GetFileL(string filename, Tree*& T);
//void ToFile(string filename, Tree*& T);

void FindAndPrintNumber(Tree* T, int Data);
void FindAndPrintLetter(Tree* T, char Data);

void DeleteAll(Tree*& T);
void print(Tree* aBranch);

int main()
{
	int k, Numb, No;
	string Name, FileName;
	char letter;
	double Pri;
	bool H, Test;

	Tree* T = NULL;


	do {
		cout << "\tWhat do you want to do \n";

		cout << "1) Add element\n"
			<< "2) Print information about tree\n"
			<< "3) Print all that less then number\n"
			<< "4) Print all that start from letter\n"

			<< "\n5) Sort by number\n"
			<< "6) Sort by letter\n"
			<< "7) Donload from file\n"
			<< "8) Delete all\n"
			<< "0) Exit\n";
		cin >> k;

		switch (k)
		{

		case 1:
			cout << "\tYou want to add element\n";
			cout << "Input capacity: "; cin >> Numb;
			cout << "Input manufacter: "; cin >> Name;
			cout << "Input price: "; cin >> Pri;
			cout << "Have?"; cin >> H;
			Add(Numb, Name, Pri, H, T);
			break;
		case 2:
			cout << "\tYou want to print tree\n";
			print(T);
			break;

		case 3:
			cout << "\t You want to print all less then number\n";
			cout << "Input number "; cin >> No;
			FindAndPrintNumber(T, No);
			break;
		case 4:
			cout << "\t You want to print all that start from letter\n";
			cout << "Input letter"; cin >> letter;
			FindAndPrintLetter(T, letter);
			break;
		case 5:
			cout << "\tYou want to sort by number\n";
			cout << "\tYou want to sort by letter\n";
			DeleteAll(T);
			GetFile("Input.txt", T);
			break;





		case 6:
			cout << "\tYou want to sort by letter\n";
			DeleteAll(T);
			GetFileL("Input.txt", T);
			break;

		case 7: cout << "\t You want download from file\n";
			//cout << "Input file name";  cin >> FileName;
			//if (T) { cout << "\t\nThat file already loaded\n"; break; }
			GetFile("Input.txt", T);
			Test = true;
			break;

		case 8:
			cout << "\t You want delete all\n";
			//ToFile("output.txt", T);

			DeleteAll(T);
			break;


		}
	} while (k != 0);
	return 0;
}



void Add(int Capacity, string manufacter, double price, bool have, Tree*& aBranch)
{

	if (!aBranch)
	{
		aBranch = new Tree;
		aBranch->capacity = Capacity;
		aBranch->manufacter = manufacter;
		aBranch->price = price;
		aBranch->Have = have;
		aBranch->Left = NULL;
		aBranch->Right = NULL;
		return;
	}
	else {


		if (aBranch->capacity > Capacity)
		{
			Add(Capacity, manufacter, price, have, aBranch->Left);
		}
		else
		{
			Add(Capacity, manufacter, price, have, aBranch->Right);
		};
	}
}

void AddL(int Capacity, string manufacter, double price, bool have, Tree*& aBranch)
{

	if (!aBranch)
	{
		aBranch = new Tree;
		aBranch->capacity = Capacity;
		aBranch->manufacter = manufacter;
		aBranch->price = price;
		aBranch->Have = have;
		aBranch->Left = NULL;
		aBranch->Right = NULL;
		return;
	}
	else {


		if (aBranch->manufacter > manufacter)
		{
			AddL(Capacity, manufacter, price, have, aBranch->Left);
		}
		else
		{
			AddL(Capacity, manufacter, price, have, aBranch->Right);
		};
	}



}

void print(Tree* aBranch)
{
	if (!aBranch) return;


	print(aBranch->Left);

	cout << "Capacity " << aBranch->capacity << "\n";

	cout << "Manufacter " << aBranch->manufacter << "\n";

	cout << "Price " << aBranch->price << "\n";

	cout << "Have? "; if (aBranch->Have) { cout << " Yes\n "; }
	else cout << "No\n";
	cout << "\n";

	print(aBranch->Right);

	return;
}

void GetFile(string filename, Tree*& T)
{

	ifstream f(filename);
	if (!f) cout << "\t\nФайл не найден\n";
	if (f.eof()) cout << "\nФайл пуст\n";
	else {
		while (!f.eof()) {

			int Numb;
			string Name, FName;
			double Pri;
			bool H;

			f >> Numb;
			f >> Name;
			f >> Pri;
			f >> H;

			Add(Numb, Name, Pri, H, T);
		}
	}

	f.close();
}

void GetFileL(string filename, Tree*& T)
{

	ifstream f(filename);
	if (!f) cout << "\t\nФайл не найден\n";
	if (f.eof()) cout << "\nФайл пуст\n";
	else {
		while (!f.eof()) {

			int Numb;
			string Name, FName;
			double Pri;
			bool H;

			f >> Numb;
			f >> Name;
			f >> Pri;
			f >> H;

			AddL(Numb, Name, Pri, H, T);
		}
	}

	f.close();
}

void DeleteAll(Tree*& T)
{
	if (T)
	{
		if (T->Left) DeleteAll(T->Left);
		if (T->Right) DeleteAll(T->Right);
		delete T;
		T = NULL;
	}

	else
		cout << "\tIts empty already\n";

}

void FindAndPrintNumber(Tree* T, int Data)
{
	if (!T) return;
	FindAndPrintNumber(T->Left, Data);

	if (Data > T->capacity) {
		cout << "Capacity " << T->capacity << "\n";

		cout << "Manufacter " << T->manufacter << "\n";

		cout << "Price " << T->price << "\n";

		cout << "Have? "; if (T->Have) { cout << " Yes\n "; }
		else cout << "No\n";
		cout << "\n";
		/*if (!T->Left) { T = T->Right; }
		else { T = T->Left; }*/
	}
	FindAndPrintNumber(T->Right, Data);


}

void FindAndPrintLetter(Tree* T, char Data)
{
	if (!T) return;

	FindAndPrintLetter(T->Left, Data);
	if (Data == T->manufacter[0]) {
		cout << "Capacity " << T->capacity << "\n";

		cout << "Manufacter " << T->manufacter << "\n";

		cout << "Price " << T->price << "\n";

		cout << "Have? "; if (T->Have) { cout << " Yes\n "; }
		else cout << "No\n";
		cout << "\n";
	}
	FindAndPrintLetter(T->Right, Data);
}


/*void ToFile(string filename, Tree*& T)
{

	ToFile(filename, T->Left);

	ofstream fin(filename);

	fin << T->capacity << T->manufacter << T->price << T->Have << endl;
		fin.close();
	ToFile(filename, T->Right);
		}*/





































		// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
		// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

		// Советы по началу работы 
		//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
		//   2. В окне Team Explorer можно подключиться к системе управления версиями.
		//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
		//   4. В окне "Список ошибок" можно просматривать ошибки.
		//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
		//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
