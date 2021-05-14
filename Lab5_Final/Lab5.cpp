// Lab5_final(nice).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// 5 Лабораторная.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int newCount = 0;

struct Watch
{
	struct Node
	{
		int number{};
		string manufacter{};
		double price{};
		bool Have{};
		Node* next{};
		Node* prev{};
	};

	Node* First = NULL;
	Node* Last = NULL;
	Node* Curent = NULL;
	int Count{};

	void Print();
	void Info() ;
	void Clear() ;




	bool MoveNext();
	bool MovePrev();
	bool MoveFirst();
	bool MoveLast();

	bool Init(int, string, double, bool);
	bool AddNext(int, string, double, bool);
	bool AddPrev(int, string, double, bool);
	bool AddFirst(int, string, double, bool);
	bool AddLast(int, string, double, bool);

	bool Del(int&, string&, double&, bool&);
	bool DelFirst(int&, string&, double&, bool&);
	bool DelLast(int&, string&, double&, bool&);

	void GetFile(Watch S, string filename);

	void SortByNumber(string how);

	void SortByLeter(string how);

	void ChangePlace(Node* i, Node* j);

};






void Watch::Print()
{
	if (!First) { cout << "Empty\n"; return; }


	Node* temp = First;

	cout << "Current list: \n";
	do
	{
		cout << "\nNumber: " << temp->number
			<< "\n" << "Manufacter: " << temp->manufacter
			<< "\n" << "Price: " << temp->price;
		if (temp->Have) { cout << "\nHave? Yes\n"; }
		else { cout << "\nHave? No\n"; }
		temp = temp->next;
	} while (temp);
}

void Watch::Info()
{
	if (Count) { cout << "\nNow you have: " << Count << " Watches\n"; }
	else { cout << "List is empty\n"; }
	if (Curent) {
		cout << "\nCurent element its:\n " << Curent->number << "\n"
			<< Curent->manufacter << "\n" << Curent->price << "\n" << Curent->Have << "\n";
	}

}

bool Watch::MoveFirst()
{
	if (!First)return false;
	Curent = First;
	return true;
}
\
bool Watch::MoveLast()
{
	if (!Last)return false;
	Curent = Last;
	return true;
}

bool Watch::MoveNext()
{
	if (!First) return false;
	if (!Curent) { Curent = First; return true; }
	if (!Curent->next) return false;
	Curent = Curent->next;
	return true;
}

bool Watch::MovePrev()
{
	if (!First) return false;
	if (!Curent) { Curent = First; return true; }
	if (!Curent->prev) return false;
	Curent = Curent->prev;
	return true;
}


bool Watch::Init(int nume, string Name, double Pri, bool H)
{
	if (!First)
	{
		First = new Node;
		Last = First;
		Curent = First;
		First->prev = NULL;
		First->next = NULL;
		First->number = nume;
		First->manufacter = Name;
		First->price = Pri;
		First->Have = H;
		Count = 1;
		return true;

	}

	else {
		cout << "Error"; return false;
	}
}

bool Watch::AddNext(int nume, string Name, double Pri, bool H)
{

	if (!First) return Init(nume, Name, Pri, H);

	Node* temp = Curent->next;
	Curent->next = new Node;
	Curent->next->next = temp;
	Curent->next->prev = Curent;

	if (!temp)
		Last = Curent->next;
	else
		temp->prev = Curent->next;

	Curent = Curent->next;

	Curent->number = nume;
	Curent->manufacter = Name;
	Curent->price = Pri;
	Curent->Have = H;
	Count++;

	return true;

}

bool Watch::AddPrev(int nume, string Name, double Pri, bool H)
{
	if (!First) return Init(nume, Name, Pri, H);

	Node* temp = Curent->prev;
	Curent->prev = new Node;
	Curent->prev->next = Curent;
	Curent->prev->prev = temp;

	if (!temp)
		First = Curent->prev;
	else
		temp->next = Curent->prev;

	Curent = Curent->prev;

	Curent->number = nume;
	Curent->manufacter = Name;
	Curent->price = Pri;
	Curent->Have = H;
	Count++;
	return true;
}

bool Watch::AddFirst(int nume, string Name, double Pri, bool H)
{
	if (MoveFirst()) return AddPrev(nume, Name, Pri, H);
	else return Init(nume, Name, Pri, H);
}

bool Watch::AddLast(int nume, string Name, double Pri, bool H)
{
	if (MoveLast())return AddNext(nume, Name, Pri, H);
	else return Init(nume, Name, Pri, H);
}


bool Watch::DelFirst(int& nume, string& Name, double& Pri, bool& H)
{
	if (!First) return false;
	if (Curent != First) MoveFirst();

	Node* temp = Curent->next;
	nume = Curent->number;
	Name = Curent->manufacter;
	Pri = Curent->price;
	H = Curent->Have;

	if (temp) temp->prev = NULL;
	delete Curent;
	Curent = temp;
	First = temp;
	Count--;
	if (!temp)
	{
		Last = NULL;
		return false;
	}

	return true;
}


bool Watch::DelLast(int& nume, string& Name, double& Pri, bool& H)
{
	if (!First) return false;
	if (Curent != Last) MoveLast();

	Node* temp = Curent->prev;
	nume = Curent->number;
	Name = Curent->manufacter;
	Pri = Curent->price;
	H = Curent->Have;

	if (temp) temp->next = NULL;
	delete Curent;
	Curent = temp;
	Last = temp;
	Count--;

	if (!temp) { First = NULL; return false; }
	return true;
}

bool Watch::Del(int& nume, string& Name, double& Pri, bool& H)
{
	if (!First) return false;
	if (!Curent) return false;

	if (Curent == First) return DelFirst(nume, Name, Pri, H);
	if (Curent == Last) return DelLast(nume, Name, Pri, H);

	Node* temp = Curent->next;
	nume = Curent->number;
	Name = Curent->manufacter;
	Pri = Curent->price;
	H = Curent->Have;

	Curent->prev->next = Curent->next;
	Curent->next->prev = Curent->prev;

	delete Curent;
	Curent = temp;
	Count--;
	return true;
}

void Watch::Clear()
{
	if (!MoveFirst()) { cout << "List is empty\n"; return; }

	int N; string Name; double Pri; bool H;
	while (Del(N, Name, Pri, H));
}

void Watch::GetFile(Watch S, string filename)
{

	int Numb;

	string Name, FName;
	double Pri;
	bool H;
	ifstream in(filename);
	if (!in)
	{
		cout << "Error\n";
		return;
	}



while (in >> Numb >> Name >> Pri >> H)
  {
	if (!First) { Init(Numb, Name, Pri, H); }
	AddNext(Numb, Name, Pri, H);
	MoveNext();
  }
     in.close();
}

/*void Watch::Sort()
{
	if (First && First->next)
	{
		//Node* C = First;
		MoveFirst();
		Node* P = NULL;
		Node* temp = NULL;
		bool mark = false;
		for (int i = 0; i; Curent->next)
		{
			temp = Curent->next;
			if (Curent->number > temp->number)
			{
				mark = true;
				Curent->next = temp->next;
				temp->next = Curent;
				if (P)
				{
					P->next = temp;
					temp->prev = P;
					P = temp;
				}
				if (Curent == First)
				{
					First = temp;
				}
				if (!Curent->next)
				{
					Last = Curent;
				}
				else
				{
					P = Curent;
					Curent = Curent->next;
				}
			}
			if (!mark)
				break;
			else
			{
				Curent = First;
				P = NULL;
				mark = false;
			}}}
else cout << "\nErorr";}*/



void Watch::SortByNumber(string how)
{
	for (Node* i = First; i; i = i->next) {
		for (Node* j = First; j; j = j->next) {
            if (how == "Up")
			{
				if (i->price < j->price)
				{
				   ChangePlace(i, j);
				}
			}
			else
				if (i->price > j->price)
				{
					ChangePlace(i, j);
				}


		}
	}
}
void Watch::SortByLeter(string how)
{
	for (Node* i = First; i; i = i->next) {
	       for (Node* j = First; j; j = j->next) {
			   if (how == "Up") {
				   if (i->manufacter < j->manufacter)
				   {
					   ChangePlace(i, j);
				   }
			   }
			   else
			   {
				   if (i->manufacter > j->manufacter)
				   {
					   ChangePlace(i, j);
				   }
			   }
			}
	}
}


void  Watch::ChangePlace(Node * i, Node * j)
{
	int B = i->number;
	double Pri = i->price;
	string Name = i->manufacter;
	bool H = i->Have;

	i->number = j->number;
	i->manufacter = j->manufacter;
	i->price = j->price;
	i->Have = j->Have;

	j->number = B;
	j->price = Pri;
	j->manufacter = Name;
	j->Have = H;
}





int main()
{
	Watch F;
	int k, N, Numb, FN;
	string M, Name, FName,how;
	double Pri, FP;
	bool H, FH;


	FN = 1245;
	FName = "First";
	FP = 1000.50;
	FH = 1;
	F.Init(FN, FName, FP, FH);
	F.GetFile(F, "Data.txt");
	F.DelFirst(FN, FName, FP, FH);
	F.MoveFirst();

	F.Print();
	F.Info();


	do {
		cout << "\tWhat do you want to do \n";

		cout << "1) Add First\n"
			<< "2) Add Last\n"
			<< "3) Add anyplace\n"
			<< "\n4) Delete First\n"
			<< "5) Delete Last\n"
			<< "6) Delete anyplace\n"
			<< "\n7) Sort by letter\n"
			<< "8) Sort by number\n"
			<< "9) Display list\n"
			<< "\n10) Clear the list\n"
			<< "11) Download to file\n"
			<< "0) Exit\n";
		cin >> k;

		switch (k)
		{

		case 1:
			cout << "\tYou want to add First element\n";
			cout << "Input number: "; cin >> Numb;
			cout << "Input manufacter: "; cin >> Name;
			cout << "Input price: "; cin >> Pri;
			cout << "Have?"; cin >> H;
			if (F.AddFirst(Numb, Name, Pri, H)) { cout << "\n\tFirst is added\n"; }
			break;
		case 2:
			cout << "\tYou want to add Last element\n";
			cout << "Input number: "; cin >> Numb;
			cout << "Input manufacter: "; cin >> Name;
			cout << "Input price: "; cin >> Pri;
			cout << "Have?"; cin >> H;
			if (F.AddLast(Numb, Name, Pri, H)) { cout << "\n\tLast is added\n"; }
			break;
		case 3:
			cout << "\tYou want to add element to anyplace\n";
			cout << "Input position"; cin >> N;
			cout << "Input number: "; cin >> Numb;
			cout << "Input manufacter: "; cin >> Name;
			cout << "Input price: "; cin >> Pri;
			cout << "Have?"; cin >> H;
			if (N == 1) { (F.AddFirst(Numb, Name, Pri, H)); break; }
			else if (N >= F.Count) { F.AddLast(Numb, Name, Pri, H); break; }
			else
			{
				F.MoveFirst();
				for (int i = 1; i < N - 1; i++) { F.MoveNext(); }
				if (F.AddNext(Numb, Name, Pri, H)) { cout << "\n\t Elepent added to " << N << " position\n"; }
				F.MoveFirst();
				break;
			}

		case 4:
			cout << "\t\n You want to delete first element\n";
			if (F.DelFirst(Numb, Name, Pri, H)) cout << "\t\nFirst is delete";
			F.MoveFirst();
			break;

		case 5:
			cout << "\t\n You want to delete last element\n";
			if (F.DelLast(Numb, Name, Pri, H)) cout << "\t\nLast is delete";
			F.MoveFirst();
			break;

		case 6:
			cout << "\tYou want to delete element on anyplace\n";
			cout << "Input position"; cin >> N;
			if (N == 1) { F.DelFirst(Numb, Name, Pri, H); }
			else if (N >= F.Count) { F.DelLast(Numb, Name, Pri, H); }
			F.MoveFirst();
			for (int i = 1; i < N; i++) { F.MoveNext(); }
			if (F.Del(Numb, Name, Pri, H)) { cout << "\n\t Elepent delete on " << N << " position\n"; }
			F.MoveFirst();
			break;


		case 7:
			
			cout << "\t\nYou want to sort by name\n";
			cout << "\nШn alphabetical order(Up) \t Vise versa(Down)\n";
			cin >> how;

				

			F.SortByLeter(how);


			break;
		case 8:

			cout << "\t\nYou want to sort by Price\n";
			cout << "\nAscending order(Up) \t Descending order(Down)\n";
			cin >> how;
			F.SortByNumber(how);
			break;

		case 9:
			F.Print();
			F.Info();
			break;

		case 10:
			cout << "\t\nYou want to clear list";
			F.Clear(); cout << "\nList is cleared";
			break;

		case 11:
			cout << "\t\nYou want to download to file\n";
			ofstream out;
			out.open("NewFile.txt");


			F.MoveLast();
			cout << F.Count;
			FN = F.Count;
			F.MoveFirst();
			for (int i = 0; i < FN; i++)
			{
				Numb = F.Curent->number;
				Name = F.Curent->manufacter;
				Pri = F.Curent->price;
				H = F.Curent->Have;
				if (H)
				{
					out << Numb << "  " << Name << "  " << Pri << "  " << " yes " << endl;
				}
				else
				{
					out << Numb << "  " << Name << "  " << Pri << "  " << " no " << endl;
				}

				F.MoveNext();
			}
			out.close();
			break;
		}
	} while (k != 0);
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
