/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void push (int new_data, string Color, string Manufacter, string type,
	   double price, bool nal);
void pushBuf (int new_data, string Color, string Manufacter, string type,
	 double price, bool have);
void
pop2 (struct Pen *next);

int peek ();
void displayB();
void pop ();
void display ();

void poptest ();
void popBuf ();
void popBuftest ();

int counter (string filename);



struct Pen
{

  string InkColor;
  string manufacter;
  string type;
  double price;
  int data;
  bool nal;



  struct Pen *next;
};

struct Buf
{

  string InkColor;
  string manufacter;
  string type;
  double price;
  int data;
  bool nal;

  

  struct Buf *nextB;
};


struct Pen *top;
struct Buf *topB;


int
main ()
{
  string a, b, c, s;
  int da, size, N;
  double pr;
  bool na = 1;

  size = counter ("data");

  for (int i = 0; i < size; i++)
    {
      fstream f_in ("Ink", ios::in);
      if (f_in)
	{
	  for (int j = -1; j < i; j++)
	    {
	      f_in >> a;
	    }
	  f_in.close ();

	}

      fstream in ("manufacter", ios::in);
      if (in)
	{
	  for (int j = -1; j < i; j++)
	    {
	      in >> b;
	    }
	  in.close ();
	}

      fstream n ("type", ios::in);
      if (n)
	{
	  for (int j = -1; j < i; j++)
	    {
	      n >> c;
	    }
	  n.close ();
	}

      fstream p ("price", ios::in);
      if (p)
	{
	  for (int j = -1; j < i; j++)
	    {
	      p >> pr;
	    }
	  p.close ();
	}

      fstream d ("data", ios::in);
      if (d)
	{
	  for (int j = -1; j < i; j++)
	    {
	      d >> da;
	    }
	  d.close ();
	}
	
	   fstream nalo ("Nal", ios::in);
      if (nalo)
	{
	  for (int j = -1; j < i; j++)
	    {
	      nalo >> na;
	    }
	  d.close ();
	}


      push (da, a, b, c, pr,na);
    }


 

  display ();

  cout << "\nTop element is " << peek () << "\n\n";


  int dat;
  string ty, In, Ma;
  double pri;
  bool z = 1, Nali;

  while (z)
    {

      cout <<
	"What do you want to do?\n 1.Add\n2.Remove\n3.Delete all\n4.Display\n5.Close";
      cin >> N;

      switch (N)
	{
	case 1:
	  {			

	    cout << "Input\n";

	    cout << "data(int) = ";
	    cin >> dat;
	    cout << "type = ";
	    cin >> ty;
	    cout << "Inkcolor = ";
	    cin >> In;
	    cout << "Manufacter = ";
	    cin >> Ma;
	    cout << "price = ";
	    cin >> pri;
	    cout<<"Have? ";
	    cin>>Nali;
	    push (dat, In, Ma, ty, pri,Nali);
	    display ();
	    break;
	  }

	case 2://идем в цикле, если это не тот элемент, то записываем в Buf и удаляем. Если тот то просто удаляем
	//специальной функцией, которая не сдвигает указатель.
	{
	    cout << "Input what do you want do Remove \n";

	    cout << "data(int) = ";
	    cin >> dat;
	    
	    struct Pen *temp;
	    struct Buf *tempB;
	    int con = 0, newdat;
	    temp = top;
	    tempB = topB;
	    

	    while (temp != NULL)
	  {

		if (temp->data != dat)
		  {
		      newdat = temp->data;// перезаписываем данные об узле в переменные
		      In = temp->InkColor;
		      Ma =temp->manufacter;
		      ty = temp->type;
		     pri = temp->price;
		     Nali = temp->nal;


		    pushBuf (newdat, In, Ma, ty, pri,Nali);
		    poptest();
		    
		  }

		else
		  {
              //poptest();
              pop();
              
              //popBuf();
              break;
		  }
		temp = temp->next;
	   }
	   
	   
	   


	    display ();
	    
	    //break;
	  }

	case 4:
	  {
	       
	    struct Buf *tempB;
	    
	    
	    tempB = topB;
	    
	      while(tempB!=NULL)
             
	        {
	       string InkB, ManufacterB,typeB;
	       int dataB;
	       double priceB;
	       bool NalB;
	       
	       dataB = tempB->data;// перезаписываем данные об узле в переменные
		      InkB = tempB->InkColor;
		     ManufacterB =tempB->manufacter;
		      typeB = tempB->type;
		     priceB = tempB->price;
		     NalB = tempB->nal;
		     
		     push(dataB,InkB,ManufacterB,typeB,priceB,NalB);
	       
	       tempB = tempB->nextB;}
	      
	      
	      
	      
	    display ();
	    displayB ();
	    break;
	  }
	case 5:
	  {
	    break;
	  }


	}
    }
  return 0;
}


void push (int new_data, string Color, string Manufacter, string type,
      double price, bool have)
{

  struct Pen *temp;

  temp = new Pen ();


  temp->data = new_data;
  temp->InkColor = Color;
  temp->manufacter = Manufacter;
  temp->type = type;
  temp->price = price;
  temp->nal = have;



  temp->next = top;


  top = temp;

  cout << "New element " << new_data << " is added" << endl;
}

void pushBuf (int new_data, string Color, string Manufacter, string type,
	 double price, bool have)
{

  struct Buf *tempB;

  tempB = new Buf ();


  tempB->data = new_data;
  tempB->InkColor = Color;
  tempB->manufacter = Manufacter;
  tempB->type = type;
  tempB->price = price;
  tempB->nal = have;



  tempB->nextB = topB;


  topB = tempB;

  cout << "New element " << new_data << " is added to Buf" << endl;
}



int peek ()
{
 
  if (top != NULL)
    return top->data;
  else
    {
      cout << "\nStack is empty" << endl;

      exit (1);
    }
}



void pop ()
{
  struct Pen *temp;

  
  if (top == NULL)
    {
      cout << "\nStack is empty" << endl;

      exit (1);
    }
  else
    {
      
      temp = top;		// top(789689898)---> (5588879) ---> ...
      // temp(789689898)

    
      top = top->next;		// top(5588879) ---> ...

      
      temp->next = NULL;

      cout << "Element " << temp->data << " is deleted" << endl;

     
      free (temp);
    }
}

void poptest ()//функция удаления, не сдвигающая текущий элемент
{
  struct Pen *temp;

  
  if (top == NULL)
    {
      cout << "\nStack is empty" << endl;

      exit (1);
    }
  else
    {
      
      temp = top;		
      

    
      top = top->next;		

      
      //temp->next = NULL;

      cout << "Element " << temp->data << " is deleted" << endl;

     
      free (temp);
    }
}

















void popBuf ()
{
  struct Buf *temp;

  
  if (top == NULL)
    {
      cout << "\nStack is empty" << endl;

      exit (1);
    }
  else
    {
      
      temp = topB;		// top(789689898)---> (5588879) ---> ...
      // temp(789689898)

    
      topB = topB->nextB;		// top(5588879) ---> ...

      
      temp->nextB = NULL;

      cout << "Element " << temp->data << " is deleted" << endl;

     
      free (temp);
    }
}

void popBuftest ()
{
  struct Buf *temp;

  
  if (top == NULL)
    {
      cout << "\nStack is empty" << endl;

      exit (1);
    }
  else
    {
      
      temp = topB;		// top(789689898)---> (5588879) ---> ...
      // temp(789689898)

    
      topB = topB->nextB;		// top(5588879) ---> ...

      
      //temp->nextB = NULL;

      cout << "Element " << temp->data << " is deleted" << endl;

     
      free (temp);
    }
}


















void display ()
{
  struct Pen *temp;

 
  if (top == NULL)
    {
      cout << "\nStack is empty" << endl;

      exit (1);
    }
  else
    {
      temp = top;
      cout << "Current stack: \n";
      while (temp != NULL)
	{
	  
	  cout << temp->data << " " << temp->manufacter << " " << temp->
	    type << " " << temp->price << " ";
	    
	    if (temp->nal)
	    {cout<<"yes"<<endl;}
	    else
	    {cout<<"no"<<endl;}


	  
	  temp = temp->next;
	}
      cout << endl;
    }
}

void
displayB ()
{
  struct Buf *temp;

  
  if (topB == NULL)
    {
      cout << "\nStack is empty" << endl;

      exit (1);
    }
  else
    {
      temp = topB;
      cout << "Current buf stack: \n";
      while (temp != NULL)
	{
	
	  cout << temp->data << " " << temp->manufacter << " " << temp->
	    type << " " << temp->price << " " ;
	    
	    
	    if (temp->nal)
	    {cout<<"yes"<<endl;}
	    else
	    {cout<<"no"<<endl;}


	 
	  temp = temp->nextB;
	}
      cout << endl;
    }
}


int
counter (string filename)
{
  ifstream in (filename);
  size_t count = 0;
  int x;
  while (in >> x)
    count++;
  //std::cout << count << std::endl;
  return count;
}



