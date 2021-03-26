/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;
void PrintMatr(int** M, int n, int m);
void PrintMatr(double** M,int n,int m);
void NewMatr(int**& M, int n, int m);
void NewMatr(double**& M,int n,int m);
void DelMatr(int**& M, int n, int m);
void DelMatr(double**& M, int n, int m);
void GetMatr(int** M,int n,int m);
void GetMatr(double** M,int n,int m);
void GetMass(int s, int c, double **arr);
void Getcopy(double** a, double** M2, int s,int c);
void MakeOneMatr(double** a,int s,int c);
bool DoppelStrings(double **B, int n, int m, int k);
double Delta(double **A, double *x, int n, int m);
int ZeroStrings(double **B, int n, int m, int k);
bool TriangMatr(double **A, double **B, int n, int m, double& det);
bool Solve(double **A, double **B, double *x, int n, int m, double& det);
void SwitchStrings(double **B, int n, int m, int k);

double DelSC(double** M2,int s, int c, int curentstring, int curentcolon, double* Mas, double** obr);
void GetMinor(double** M2, int s,int c,double** ObratMatr);
//void DelSC(double** M2,int s, int c, int curentstring, int curentcolon);
double GiveMeDet(double **B, int n, int m);
int main()
{
    setlocale(LC_ALL, "Russian");
    bool f;
    double** a;
    double** M2;
    double** rev;
    double** ObratMatr;
    double* results;
    double det = 1;
    int s = 3,c = 4,N;
    results = new double[s];
    
 
    
     
    
    cout<<"Выберите тип матрицы:\n1.Готовая матрица\n2.Случайная матрица\n3.Единичная матрица\n4.Нулевая матрица\n5.Матрица Гильберта"<<endl;    
    cin>>N;
switch(N)
{
    case 1:
   {
        NewMatr(a,s,c);
        NewMatr(M2,s,c);
        
        GetMass(s,c,a);
        Getcopy(a,M2,s,c);
        
        //NewMatr(ObratMatr,s,c);
        //GetMass(s,c,ObratMatr);
        //GetMinor(M2,s,c,ObratMatr);
        
        //cout<<GiveMeDet(M2,s,c)<<endl;
        
   PrintMatr(M2, s,c);
   //PrintMatr(ObratMatr, s,c);
        
  
        
        
        break;
    }
    
    case 2:
    {
        cout<<"Enter string number:"<<endl;
        cin>>s;
        cin>>c;
        
        
        NewMatr(a,s,c);
        NewMatr(M2,s,c);
        for (unsigned int i = 0; i < s; i++) for (unsigned int j = 0; j < c; j++) 
            a[i][j] = rand() % 100;
        Getcopy(a,M2,s,c);    
        PrintMatr(M2, s, c);
        break;
    }
    
    case 3:
    {
         cout<<"Enter string number:"<<endl;
        cin>>s;
        cin>>c;
        NewMatr(a,s,c);
        NewMatr(M2,s,c);
        MakeOneMatr(a,s,c);
        Getcopy(a,M2,s,c);    
        PrintMatr(M2, s, c);
        break;
    }
    
    case 4:
    {
    cout<<"Enter string number:"<<endl;
        cin>>s;
        cin>>c;    
    NewMatr(a,s,c);
    NewMatr(M2,s,c);
    for (unsigned int i = 0; i < s; i++) for (unsigned int j = 0; j < c; j++) 
            a[i][j] = 0;
            
    Getcopy(a,M2,s,c);    
    PrintMatr(M2, s, c);  
     break;
    }
   
    
    case 5:
    {
         cout<<"Enter string number:"<<endl;
        cin>>s;
        cin>>c;
        
       NewMatr(a,s,c);
       NewMatr(M2,s,c);
        for (int i = 0; i < s; i++)
    for (int j = 0; j < c; j++)
        a[i][j] = 1. / (i + j + 1);
        
        Getcopy(a,M2,s,c);    
        PrintMatr(M2, s, c);
        break;
    }
    
    
    //default:
      //{cout << "Incorrect number" << endl;}
      
    
    
}   
   
      //Устранение одиннаковых строк
    for ( int i = s - 1; i >= 1; i--)
    {
        DoppelStrings(M2, s, c, i);
    }
    //Устранение нулевых строк
    for ( int i = 0; i < s; i++)
    {
        int pos = ZeroStrings(M2, s, c, i);
        if (pos != -1)
        {
            //Заменяем нулевую строку
            for (unsigned int l = 0; l < c; l++)
            {
                M2[pos][l] = M2[s - 1][l];
            }
            //Зануляем крайнюю строку
            for (unsigned int l = 0; l < c; l++)
            {
                M2[s - 1][l] = 0;
            }
            s--;
        }
    }
    while (ZeroStrings(M2, s, c, s - 1) != -1)
    {
        s--;
    }
    PrintMatr(M2, s, c);

    //Решение задач
    f = Solve(a, M2, results, s, c, det);
    cout << "Ответы: \n";
    for (unsigned int i = 0; i < s; i++) {
        cout << results[i];
        if (i != s - 1) cout << ", ";
        else cout << endl;
    }
    cout << "\nПогрешность = " << Delta(a, results, s, c) << endl;
    if(s==c)
    {
    cout << "\nОпределитель = " << det << endl;
    }   
    
   
   
   
   
   
   
   
   
    
     
return 0;    
        
        
        
}

// ФУНКЦИИ
void PrintMatr(int** M, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(5) << M[i][j];
        cout << endl;
    }
    cout << endl;
}
void PrintMatr(double** M,int n,int m)
{
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(20) << M[i][j];
        cout << endl;
    }
    cout << endl;
}
// печатать

void NewMatr(int**& M, int n, int m)
{
    cout << "\t-New int matr-" << endl;
    M = new int* [n];
    for (int i = 0; i < n; i++)
        M[i] = new int[m];
}
void NewMatr(double**& M,int n,int m)
{
    cout << "\t-New double matr-" << endl;
    M = new double* [n];
    for (int i = 0; i < n; i++)
        M[i] = new double[m];
}
void DelMatr(int**& M, int n, int m)
{
    cout << "\t-Delete int matr-" << endl;
    for (int i = 0; i < n; i++)
        delete[]M[i];
    delete[]M;
}

void DelMatr(double**& M, int n, int m)
{
    cout << "\t-Delete double matr-" << endl;
    for (int i = 0; i < n; i++)
        delete[]M[i];
    delete[]M;
}

void GetMatr(int** M,int n,int m)
{
    cout<<"Enter matrix, sized "
    <<n<<"x"<<m<<":"<<endl;
    
    for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
          cin>>M[i][j];
}
void GetMatr(double** M,int n,int m)
{
    cout<<"Enter matrix, sized "
    <<n<<"x"<<m<<":"<<endl;
    
    for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
          cin>>M[i][j];
}
bool DoppelStrings(double **B, int n, int m, int k)
{
    for (int i = 0; i < k; i++) {
        bool doppel = true;
        for (unsigned int j = 0; j < m; j++) {
            if (B[i][j] != B[k][j]) doppel = false;
        }
        if (doppel == true) {
            for (unsigned int j = 0; j < m; j++) B[k][j] = 0;
             PrintMatr(B, n, m);
            return true;
        }
    }
    return false;
}
double Delta(double **A, double *x, int n, int m) {
    double *y = new double[n];
    for (unsigned int i = 0; i < n; i++) {
        double res = 0;
        for (unsigned int j = 0; j < n; j++) {
            res += A[i][j] * x[j];
        }
        y[i] = res;
        cout << y[i] << ' ';
    }
    cout << endl;
    double max;
    max = fabs(y[0] - A[0][m - 1]);
    for (unsigned int i = 1; i < n; i++) {
        if (fabs(y[i] - A[i][m - 1]) > max) max = fabs(y[i] - A[i][m - 1]);
    }

    delete[] y;
    y = NULL;
    return max;
}
int ZeroStrings(double **B, int n, int m, int k) {
    for (unsigned int i = 0; i < m - 1; i++) {
        if (B[k][i] != 0) return -1;
    }
    return k;
}

//Удаляем нулевую строку

bool TriangMatr(double **A, double **B, int n, int m, double& det)
{
    double koef;
    for (unsigned int k = 0; k < n; k++) for (unsigned int i = k + 1; i < n; i++)
    {
        if (B[k][k] == 0) SwitchStrings(B, n, m, k);
        koef = -1 * B[i][k] / B[k][k];
        for (unsigned int j = k; j < n + 1; j++) B[i][j] = B[i][j] + B[k][j] * koef;
    }
    
    for (unsigned int j = 0; j < n; j++) {
        det *= B[j][j];
    }
    if (det == 0) return false;
    else
    return true;
    
}
double GiveMeDet(double **B, int n, int m)
{
    double** matr;
    NewMatr(matr,n,m);
    Getcopy(B,matr,n,m);
    double koef;
    double deter = 1;
    for (unsigned int k = 0; k < n; k++) for (unsigned int i = k + 1; i < n; i++)
    {
        if (matr[k][k] == 0) SwitchStrings(matr, n, m, k);
        koef = -1 * matr[i][k] / matr[k][k];
        for (unsigned int j = k; j < n + 1; j++) matr[i][j] = matr[i][j] + matr[k][j] * koef;
    }
    
    for (unsigned int j = 0; j < n; j++) 
    {
        deter *= matr[j][j];
    }
   DelMatr(matr,n,m);
    return deter;
    
}
bool Solve(double **A, double **B, double *x, int n, int m, double& det)
{
    double res = 0;
    if (TriangMatr(A, B, n, m, det) == true) {
        for (int i = n - 1; i >= 0; i--) {
            res = 0;
            for (int j = i + 1; j <= n - 1; j++) res = res - x[j] * B[i][j];
            res += B[i][m - 1];
            x[i] = res / B[i][i];
        }
        return true;
    }
    cout << "\nСистема не имеет единственного решения\n";
    return false;
}
//Функция решения

void SwitchStrings(double **B, int n, int m, int k) {
    double* buf = new double[m];
    //Нахождение строки с максимальным по модулю элементом
    int pos = k + 1;
    double max = 0;
    if (n - k > 1) {
        for (unsigned int i = k + 1; i < n; i++) {
            if (fabs(B[i][k]) > max) {
                max = fabs(B[i][k]);
                pos = i;
                //cout << endl << max << endl;
            }
        }
    }
    //Перемещение строк
    //Буфер
    for (unsigned int l = 0; l < m; l++) {
        buf[l] = B[k][l];
    }
    //Заменяем k-тую строку
    for (unsigned int l = 0; l < m; l++) {
        B[k][l] = B[pos][l];
    }
    //Заменяем целевую строку
    for (unsigned int l = 0; l < m; l++) {
        B[pos][l] = buf[l];
    }
    //PrintMatr(n, m, B);
    delete[] buf;
}

void GetMass(int s, int c, double **arr) {
    ifstream f("Mass.txt");
    if (!f) 
    {cout << "\nerror";}
    else {
        for (unsigned int i = 0; i < s; i++) {
            for (unsigned int j = 0; j < c; j++) {
                f >> arr[i][j];
            }
        }
    }
    f.close();
}
void Getcopy(double** a, double** M2, int s,int c)
{
    for ( int i = 0; i < s; i++)
    for ( int j = 0; j < c; j++)
    M2[i][j] = a[i][j];
}    
 void MakeOneMatr(double** a,int s,int c)
{
    for(int i=0;i<s;i++)
    for(int j=0;j<c;j++)
    {
        if(i==j){a[i][j]=1;}
        else{a[i][j]=0;}
    }
}

void GetMinor(double** M2, int s,int c,double** ObratMatr)
{
    int curentstring,curentcolon;
    double** copy;
    double** obr;
    double* Mas;
    Mas = new double[s*c];
    NewMatr(copy,s,c);
    Getcopy(M2,copy,s,c);
    NewMatr(obr, s-1,c-1);
    if(s!=c){cout<<"Нет обратной"<<endl;}
    
    else
    {
        
        
        for(int i=0;i<s;i++)
        for(int j=0;j<c;j++)
        {
            //DelSC(copy,s,c,i,j,Mas,obr);
            ObratMatr[i][j]=pow(-1,i+j) * DelSC(copy,s,c,i,j,Mas,obr); //GiveMeDet(obr,s-1,c-1);//Записываем в финальную матрицу
            
        }
        
        
        
        
        
    }
    
    
}
double DelSC(double** M2,int s, int c, int curentstring, int curentcolon, double* Mas, double** obr)//Mas это массив в который мы будем записывать матрицу как строчку
{
    int col=0;
    double ans;
   
     for(int k=0;k<s;k++)
      for(int j=0;j<c;j++)
      {
          if(k!=curentstring && j!=curentcolon)
          {
            Mas[col]=M2[k][j];//записали в массив
            col++;
          }
      }
    for(int a=0;a<s-1;a++)
     for(int b=0;b<c-1;b++)
     {
        obr[a][b]=Mas[a];
        PrintMatr(obr, s-1,c-1);
     }
     
   return GiveMeDet(obr,s-1,c-1);  
      
      
      
}







//Проходим по всей матрице ищем нули, если находим, то меняем на 0.0(если не сработает, то другое число)
//Создаем матрице размером на один меньше(ведь будем вычеркивать)
//Под вычеркиванием строк понимаем зануление строк и столбцов
//Затем снова проходим по матрице и ненулевые элементы записываем в созданную маленькую матрицу
 
