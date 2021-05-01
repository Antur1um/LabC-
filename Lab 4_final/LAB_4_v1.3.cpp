// Lab 4 final.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pen  //структура с информацией о ручке
{
	string pen;
	int counter;
	double Price;
	int year;
	void Print();
	bool Seria(char*& data, int& n);
};

void Pen::Print()  //Функция, печатает один элемент структуры.
{
	cout << "Pen: " << pen << "\t" << "Counter: " << counter << "\t" << "Price: " << Price << "\t" << "Year: " << year << endl << endl;
}

bool Pen::Seria(char*& data, int& n) //Функция сериализации данных
{
	size_t s = pen.size();

	int n0 = sizeof(size_t);
	int n1 = s;
	int n2 = sizeof(int);
	int n3 = sizeof(double);
	int n4 = sizeof(int);

	n = n0 + n1 + n2 + n3 + n4;

	data = new char[n];

	char* d0 = reinterpret_cast<char*>(&s);
	char* d1 = const_cast<char*>(pen.c_str());
	char* d2 = reinterpret_cast<char*>(&counter);
	char* d3 = reinterpret_cast<char*>(&Price);
	char* d4 = reinterpret_cast<char*>(&year);

	for (int i = 0; i < n0; i++) data[i] = d0[i];
	for (int i = 0; i < n1; i++) data[i + n0] = d1[i];
	for (int i = 0; i < n2; i++) data[i + n0 + n1] = d2[i];
	for (int i = 0; i < n3; i++) data[i + n0 + n1 + n2] = d3[i];
	for (int i = 0; i < n4; i++) data[i + n0 + n1 + n2 + n3] = d4[i];

	return true;
}

Pen DeSeria(char* data, int n) // Функция десиреализации данных
{
	Pen temp;
	int n0, n1, n2, n3, n4;
	n0 = sizeof(size_t);
	n2 = sizeof(int);
	n3 = sizeof(double);
	n4 = sizeof(int);

	size_t s = *reinterpret_cast<size_t*>(data);
	n1 = s;

	string ss(data + n0, s);
	temp.pen = ss;
	temp.counter = *reinterpret_cast<int*>(data + n0 + n1);
	temp.Price = *reinterpret_cast<double*>(data + n0 + n1 + n2);
	temp.year = *reinterpret_cast<int*>(data + n0 + n1 + n2 + n3);

	return temp;
}

struct MyQueue // Структура очередь
{
	struct Node //Подструктура содержащая данные(бинарные) и указатели на первый и следующий  элемент
	{
		int n; //похоже, тут хранится размер серии
		char* data;
		Node* next;
	};
	Node* First = NULL;  
	string Top;
	int Count = 0;
	bool Push(char*, int);
	bool Pop(char*&, int&);
	void Info();
	void PrintAll();
};

void MyQueue::PrintAll()
{
	MyQueue::Node* temp;
	temp = /*MyQueue::Node**/ First;
	cout << "Now you have\n";
	while (temp != NULL)
	{
		Pen Info;
		Info = DeSeria(temp->data, temp->n);
		Info.Print();
		temp = temp->next;
	}
	
}



bool MyQueue::Push(char* data, int n)
{
	if (!First)
	{
		First = new Node;
		First->next = NULL;
		First->data = new char[n];
		for (int i = 0; i < n; i++)
		{
			First->data[i] = data[i];
		}
		First->n = n;
		Count = 1;
	}
	else
	{
		Node* temp;
		temp = First;
		while (temp->next != NULL) temp = temp->next;
		temp->next = new Node;
		temp->next->next = NULL;
		temp->next->data = new char[n];
		for (int i = 0; i < n; i++)
		{
			temp->next->data[i] = data[i];
		}
		temp->next->n = n;
		Count++;
	}
	return true;
}

bool MyQueue::Pop(char*& data, int& n)
{
	if (!First) return false;
	Node* temp = First->next;
	n = First->n;
	data = new char[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = First->data[i];
	}
	delete First->data;
	delete First;
	First = temp;
	Count--;
	return true;
}

void MyQueue::Info()
{
	if (!First) cout << "Queue is empty" << endl << endl;
	else
	{
		cout << "Queue info: " << endl;
		cout << "Queue size = " << Count << endl << endl;
		cout << "First node:" << endl;
		cout << "Seria lenght = " << First->n << endl;
		Pen Info;
		Info = DeSeria(First->data, First->n);
		Info.Print();
	}
}

Pen DeSeria(char*, int);
void PrintBinaryFile(char*, int);
void ClearBinaryFile();
bool InputBinaryFile(MyQueue&);
void GetPen(MyQueue&, Pen&);
bool RemovePen(MyQueue&, Pen&);

void main()
{
	Pen Info;
	MyQueue Queue;
	int key = 0;
	char* data; int ssize;
	InputBinaryFile(Queue);
	do
	{
		cout << "\tSelect an action: \n";

		cout << "1) Add product\n"
			<< "2) Pull out product\n"
			<< "3) Empty Cart\n"
			<< "4) Cart Info\n"
			<< "5) Seria Data\n"
			<< "6) Clear File\n"
			<< "0) Exit\n";
		cout << "\n";
		cin >> key;
		cout << endl;
		switch (key)
		{
		case 1:
			cout << "Enter the name: "; cin >> Info.pen;

			cout << "Enter the count: "; cin >> Info.counter;

			cout << "Enter the price: "; cin >> Info.Price;

			cout << "Enter the year: "; cin >> Info.year;

			Info.Seria(data, ssize);
			Queue.Push(data, ssize);
			Queue.Info();
			delete[] data;
			break;
		case 2:
			cout << "Enter the name: "; cin >> Info.pen;

			cout << "Enter the counter: "; cin >> Info.counter;

			cout << "Enter the price: "; cin >> Info.Price;

			cout << "Enter the year: "; cin >> Info.year;

			RemovePen(Queue, Info);
			Queue.Info();
			break;
		case 3:

			
			while (Queue.Pop(data, ssize))
			{
				Info = DeSeria(data, ssize);
				Info.Print();
				delete[] data;
			}
			Queue.Info();
			break;
		case 4:
			Queue.Info(); cout << "\n";

			Queue.PrintAll();
            break;
		case 5:
			cout << "Enter the name: "; cin >> Info.pen;

			cout << "Enter the count: "; cin >> Info.counter;

			cout << "Enter the price: "; cin >> Info.Price;

			cout << "Enter the year: "; cin >> Info.year;
			Info.Seria(data, ssize);
			PrintBinaryFile(data, ssize);
			delete[] data;
			break;
		case 6:
			ClearBinaryFile();
			cout << "File is clear" << endl;
			break;
		default:
			if (key != 0)
			{
				cout << "There is no such action !" << endl << endl;
			}
			if (key == 0)
			{
				while (Queue.Pop(data, ssize))
				{
					delete[] data;
				}
				Queue.Info();
			}
			break;
		}
	} while (key != 0);
}

void PrintBinaryFile(char* data, int n)
{
	fstream out("out.dat", ios::app | ios::binary);
	out.write((char*)&n, sizeof(int));
	out.write(data, n);
	out.close();
}

void ClearBinaryFile()
{
	fstream out("out.dat", ios::out | ios::binary);
	out.close();
}

bool InputBinaryFile(MyQueue& Queue)
{
	fstream in("out.dat", ios::in | ios::binary);
	if (!in)
	{
		cout << "Error, there are no input binary file" << endl;
		return false;
	}

	int i = 1, n;
	Pen Info;

	while (!in.eof())
	{
		if (in.read((char*)&n, sizeof(int)))
		{
			cout << i << ")" << " Seria length: " << n << endl << endl;
			char* data = new char[n];
			in.read(data, n);
			i++;
			Queue.Push(data, n);
			Info = DeSeria(data, n);
			Info.Print();
			delete[] data;
		}
	}
	in.close();
	return true;
}

bool RemovePen(MyQueue& Queue, Pen& TempInfo)
{
	MyQueue QueueTemp;
	Pen Info;
	char* data = NULL;
	int n;
	bool stopFind = false, find = false;
	while (stopFind == false)
	{
		Info = DeSeria(Queue.First->data, Queue.First->n);
		if ((Info.pen == TempInfo.pen) && (Info.counter == TempInfo.counter) && (Info.Price == TempInfo.Price) && (Info.year == TempInfo.year))
		{
			Queue.Pop(data, n);
			find = true;
			stopFind = true;
			break;
		}
		QueueTemp.Push(Queue.First->data, Queue.First->n);
		Queue.Pop(data, n);
		if (Queue.First == NULL)
		{
			stopFind = true;
			break;
		}
	}
	if (find == true)
	{
		cout << endl << "Succesfuly remove pen!" << endl << endl;
	}
	else
	{
		cout << endl << "Can't find pen!" << endl << endl;
	}
	stopFind = false;
	while (stopFind == false)
	{
		if (find != true)
		{
			Queue.Push(QueueTemp.First->data, QueueTemp.First->n);
			QueueTemp.Pop(data, n);
		}
		find = false;
		if (QueueTemp.First == NULL) stopFind = true;
	}
	find = false;
	delete[] data;
	return true;
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
