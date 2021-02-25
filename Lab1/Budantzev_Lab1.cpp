/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include<ctime>
#include <fstream>
#include <malloc.h>
using namespace std;


int main ()
{
  void Greatingmas (double *Mas, int x);
  void printmas (double *Mas, int &x);
  void AddelementEND (double *Mas, int &x);
  void AddelementBEGIN (double *Mas, int &x);
  void AddelementANYPLACE (double *Mas, int &x);
  void DeleteelemetEND (double *Mas, int &x);
  void DeleteelementBEGIN (double *Mas, int &x);
  void DeleteelementANYPLACE (double *Mas, int &x);
  void AddelementAFTERFIND(double *Mas, int &x);
  void DeleteAllElementAFTERFIND(double *Mas, int &x, int &y);
  




  int N, s, e, a, el, c, counter=0, size;
  bool W = true;
  double *arr;

  cout << "Input number of elements" << endl;
  cin >> size;
  arr = (double *) malloc (size * sizeof (double));
  Greatingmas (arr, size);


  while (W)
 {
      cout << "1. Print mass " << endl;
      cout << "2. Add element (end) " << endl;
      cout << "3. Add element (begin) " << endl;
      cout << "4. Add element (anyplace) " << endl;
      cout << "5. Delete element(end) " << endl;
      cout << "6. Delete element(begin) " << endl;
      cout << "7. Delete element(anyplace) " << endl;
      cout << "8. Add element (after find) " << endl;
      cout << "9. Delete element(after find) " << endl;
      cout << "10. Close " << endl;


      cout << "Input nember:" << endl;
      cin >> N;
      if (N == 10)
	   {break;}
	   
	   
      switch (N)
	 {


	case 1:
	  cout << "Printing" << endl;
	  printmas (arr, size);
	  break;


	case 2:
	  AddelementEND (arr, size);
	  break;

	case 3:
	  AddelementBEGIN (arr, size);
	  break;

	case 4:
	  AddelementANYPLACE (arr, size);
	  break;

    case 5:
	  DeleteelemetEND(arr, size);
	  break;

	case 6:
	  DeleteelementBEGIN (arr, size);
	  DeleteelemetEND(arr, size);
	  DeleteelemetEND(arr, size);
	  break;
	  
	case 7:
      DeleteelementANYPLACE(arr, size);
      DeleteelemetEND(arr, size);
	  DeleteelemetEND(arr, size);
      break;
    
	case 8:
      AddelementAFTERFIND(arr, size);
      break;
    
	case 9:
      DeleteAllElementAFTERFIND(arr, size, counter);
      while(counter > 0)
    {
        counter--;
        DeleteelemetEND(arr, size);
        DeleteelemetEND(arr, size);
    }
      break;
    
    
	default:
	  cout << "Incorrect number" << endl;
	  break;
	}


  }

  return 0;
}

void
printmas (double *Mas, int &x)
{
  for (int i = 0; i < x; i++)
    {
      cout << Mas[i] << endl;
    }
}


void
AddelementEND (double *Mas, int &x)
{
  double el;
  x++;
  Mas = (double *) realloc (Mas, (x) * sizeof (double));
  cout << "Input new element" << endl;
  cin >> el;
  Mas[x - 1] = el;
}


void DeleteelemetEND (double *Mas, int &x)
{
  x-=1;
  Mas = (double *) realloc (Mas, (x) * sizeof (double));
}

void AddelementBEGIN (double *Mas, int &x)
{
  double el, e;
  x++;
  Mas = (double *) realloc (Mas, (x) * sizeof (double));
  for (int i = x; i >= 1; i--)
    {

      Mas[i] = Mas[i - 1];
    }
  cout << "Input new element" << endl;
  cin >> el;
  Mas[0] = el;


}

void
AddelementANYPLACE (double *Mas, int &x)
{
  int p;
  cout << "Input place(less then " << x + 1 << ")" << endl;
  cin >> p;
  x++;
  Mas = (double *) realloc (Mas, (x) * sizeof (double));
  for (int i = x; i >= p; i--)
    {

      Mas[i] = Mas[i - 1];
    }
  int el;
  cout << "Input new element" << endl;
  cin >> el;
  Mas[p - 1] = el;
}

void DeleteelementBEGIN (double *Mas, int &x)
{
  double el;
  x++;
  Mas = (double *) realloc (Mas, (x) * sizeof (double));
  
  Mas[x - 1] = Mas[0];
  for (int i = 0; i <= x-2; i++)
    {
      Mas[i] = Mas[i + 1];
    }
  
}

void DeleteelementANYPLACE (double *Mas, int &x)
{
    int p;
  cout << "Input place(less then " << x + 1 << ")" << endl;
  cin >> p;
  x++;
  Mas = (double *) realloc (Mas, (x) * sizeof (double));
  Mas[p-1]=Mas[x-1];
  for (int i = p-1; i <= x-2; i++)
    {
      Mas[i] = Mas[i + 1];
    }

}


void AddelementAFTERFIND(double *Mas, int &x)
{
    double F; int c=0;
    cout<<"input element you want to find"<<endl;
    cin>>F;
    
    int i=0;
    while(i<x)
    {
        c++;
        
        if(Mas[i]==F)
        {break;}
        else
        {
            i++;
        }
        
    }
    
    if(c==x)
    
   {cout<<"Error"<<endl;}
    
    else
    {
  x++;
  Mas = (double *) realloc (Mas, (x) * sizeof (double));
  for (int i = x; i >= c; i--)
    {
        Mas[i] = Mas[i - 1];
    }
  int el;
  cout << "Input new element" << endl;
  cin >> el;
  Mas[c] = el;
    }
}


void DeleteAllElementAFTERFIND(double *Mas, int &x, int &y)
{
    bool t=0;
    double F; int c=-1;
    cout<<"input element you want to find"<<endl;
    cin>>F;
    
    int i=0;
    for(int i=0;i<x;i++)
    {
        c++;
        if(Mas[i]==F)
        { 
            t=1;
            y++;
            x++;
            Mas = (double *) realloc (Mas, (x) * sizeof (double));
            Mas[c]=Mas[x-1];
            for (int j = c; j <= x-2; j++)
           {Mas[j] = Mas[j + 1];}
        }
        
    }
    if(t==0){cout<<"Not found"<<endl;}
}

void Greatingmas (double *Mas, int x)
{
  
  fstream f_in ("Testmas.txt", ios::in);
  if (f_in)
    {
      for (int i = 0; i < x; i++)
	{
	  f_in >> Mas[i];
	}

      f_in.close ();
    }
}