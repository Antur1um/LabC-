﻿
#include <iostream>
#include <string>

using namespace std;

void push(int new_data, double pri, string Name, double selprice);
string peek();
void pop();

void display();
int returnCount();
double returnCost();
struct Goods* deletelem(Goods* lst, Goods* First);

struct Goods {

	int counter{};
	double price{};
	double SellPrice{};
	string Name{};

	struct Goods* next{};
};


struct Goods* First;

double profit;
int howmany;
double fullcost;

int main()
{

	string NewName;
	int NewCounter, N;
	double NewPrice, SellPrice;
	bool z = 1;

	while (z)
	{
		cout << "What do you want to do?\n 1.Add\n2.Sell\n3.Display\n4.Close\n";
		cin >> N;

		switch (N)
		{
		case 1:
		{   cout << "Input Name" << " "; cin >> NewName;
			cout << "Input Count" << " "; cin >> NewCounter;
			cout << "Input price" << " "; cin >> NewPrice;
			cout << "Input SellPrice" << " "; cin >> SellPrice;

			push(NewCounter, NewPrice, NewName, SellPrice);

			cout << "Top Element it's " << peek() << endl;
			display();
			break;
		}


		case 2:
		{
			double finalprice;
			cout << "Input name: "; cin >> NewName;
			cout << "Input count: "; cin >> NewCounter;

			if (First == NULL)
			{cout << "\nQueue is empty" << endl; exit(1); break;}

			else
			{
				struct Goods* temp;

				temp = First;


				while (temp != NULL)
				{
					if (temp->Name != NewName)
					{temp = temp->next;}
					else
					{
						finalprice = temp->SellPrice - temp->price;

						if (temp->counter <= NewCounter)
						{
							cout << "We don't have so much\nYou will buy all.\n";
							NewCounter = temp->counter;
							profit += NewCounter * finalprice;

							deletelem(temp, First);
							break;}
						else
						{
							temp->counter -= NewCounter;
							//finalcounter = temp->counter - NewCounter;
							profit += NewCounter * finalprice;
							cout << "\t\t\nProfit = " << profit << endl;
							break;}
                        }
				      }
			        }
		          }



		case 3:
		{
			int c = 0;
			cout << "\tNow you have:" << returnCount() << endl;
			cout << "\tTotal price: " << returnCost() << endl;
			cout << "\tTotal profit: " << profit << endl;

			display();

			break; }


		case 4: {exit(1); break; }
		default: {exit(1); break; }

		}


	}
return 0;
}

void push(int new_data, double pri, string Name, double selprice)
{
	if (First == NULL)
	{
		First = new Goods;
		First->next = NULL;
		First->counter = new_data;
		First->price = pri;
		First->SellPrice = selprice;
		First->Name = Name;
	}

	else
	{

		struct Goods* temp;

		temp = First;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}


		temp->next = new Goods;



		temp->next->counter = new_data;
		temp->next->price = pri;
		temp->next->Name = Name;
		temp->next->SellPrice = selprice;


		temp->next->next = NULL; // 

	}

	cout << "\nNew element " << Name << " is added\n";
}






string peek()
{

	if (First != NULL) {


		return First->Name;
	}
	else
	{
		cout << "\nQueue is empty" << endl;

		exit(1);
	}
}


void pop()
{

	if (First == NULL) {
		cout << "\nQueue is empty" << endl;

		exit(1);
	}
	else {
		struct Goods* temp;


		temp = First->next;

		cout << "Element " << First->Name << " is deleted" << endl;


		free(First);


		First = temp;
	}
}



















void display()
{

	if (First == NULL)
	{
		cout << "\nQueue is empty" << endl;

		exit(1);
	}
	else
	{
		struct Goods* temp;

		temp = First;

		cout << "\nCurrent queue:\n ";
		while (temp != NULL)
		{

			cout << temp->Name << ":" << "\n\tCounter: " << temp->counter <<
				" \n\tPrice: " << temp->price << " \n\tSellPrice: " << temp->SellPrice << endl;




			temp = temp->next;
		}

		cout << endl;
	}
}





int returnCount()
{
	if (First == NULL)
	{
		cout << "\nQueue is empty" << endl; exit(1); return 0;
	}

	else
	{
		struct Goods* temp;
		temp = First;
		howmany = 0;


		while (temp != NULL)
		{
			howmany = howmany + temp->counter;
			

			temp = temp->next;
		}



	}
	return howmany;

}


double returnCost()
{
	if (First == NULL)
	{
		cout << "\nQueue is empty" << endl; exit(1); return 0;
	}

	else
	{
		struct Goods* temp;
		temp = First;
		fullcost = 0;



		while (temp != NULL)
		{
			fullcost += temp->counter * temp->price;
		

			temp = temp->next;
		}



	}
	return fullcost;

}


struct Goods* deletelem(Goods* lst, Goods* First)
{
	struct Goods* temp;
	temp = First;
	while (temp->next != lst)
	{
		temp = temp->next;
	}
	temp->next = lst->next; // переставляем указатель
	free(lst);

}





