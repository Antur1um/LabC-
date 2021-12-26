#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Cylinder.h"
#include "geometry.h"
#include "Exceptions.h"
#include <QGraphicsScene>
#include <QMessageBox>
#include <QStatusBar>


#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <QString>
#include <math.h>
#include <typeinfo>
using namespace std;






MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    Update_Menu();\
    ui->statusbar->showMessage("0 Fgures in collection");
       col = new CylinderCollection;


}


MainWindow::~MainWindow()
{
    delete ui;
    delete col;
}


void MainWindow::ErrorMes(QString mes)
{

    QMessageBox::about(this, "error" , mes);
}



//сигнал, о том что в comboBox изменился текст

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1 )
{
    QString k = ui->comboBox->currentText();
    DisplayMenu(k);
}




void MainWindow::on_pushButton_clicked()
{
    if(col->getNumber()!=0)
    {
col->delCylinder(col->getNumber()-1);
ui->statusbar->showMessage("Cylinder deleted");
    }

    else
        ErrorMes("You list is empty");


}


 void MainWindow::on_pushButton_2_clicked()
 {

    // Произошло нажатие на кнопку Add

     try
     {


     if(ui->comboBox->currentText() == "Triangle cylinder")
     {
         double a,b,c,h;

         a=ui->lineEdit->text().toDouble();
          b=ui->lineEdit_2->text().toDouble();
             c=ui->lineEdit_3->text().toDouble();
              h=ui->lineEdit_4->text().toDouble();




              Figure* base = new Triangle(a,b,c);
              Cylinder* cyl = new TriangleCylinder(h,base);\

            col->AddCylinder(cyl);
             ui->statusbar->showMessage("Triangle cylinder added to collection");

            delete base;

         }


     else if(ui->comboBox->currentText() == "Circle cylinder")
     {

         double a, h;

         a=ui->lineEdit->text().toDouble();
         h = ui->lineEdit_2->text().toDouble();

         Figure* base = new Circle(a);
         Cylinder* cyl = new CircleCylinder(h,base);

         col->AddCylinder(cyl);
         ui->statusbar->showMessage("Circle cylinder added to collection");

         QString t = QString::number(col->getNumber());


         ui->statusbar->showMessage("Now you have: ");
         ui->statusbar->showMessage(t);

         delete base;
         }
}

  catch(Exception e){ErrorMes(e.GetMessage());}
  catch (...){ErrorMes("Unknown error");}


 }



void MainWindow::on_pushButton_3_clicked()
{

if(col->getNumber()-1>=1)
{

    Cylinder* Cyl = col->getCylinder(col->getNumber()-1);


    if(Cyl->WhatType() == 0)
    {
        DisplayMenu("Circle cylinder");

        CircleCylinder* Cir = static_cast<CircleCylinder*>(Cyl);

    QString S = QString::number(Cir->GetSquare());
    QString V = QString::number(Cir->CalcVolume());
    QString R = QString::number(Cir->GetR());
     QString H = QString::number(Cir->GetH());


        ui->label_2->setText(S);
        ui->label_4->setText(V);

        ui->lineEdit->setText(R);
        ui->lineEdit_3->setText(H);

        DrawCylinder(Cir->GetR(),Cir->GetH());


        delete Cir;
      }

    else if(Cyl->WhatType()==1)
    {
        DisplayMenu("Triangle cylinder");

         TriangleCylinder* Tri  = static_cast<TriangleCylinder*>(Cyl);

         QString s = QString::number(Tri->GetSquare());
         QString v = QString::number(Tri->CalcVolume());

         QString A = QString::number(Tri->GetA());
         QString B = QString::number(Tri->GetB());
         QString C = QString::number(Tri->GetC());
         QString h = QString::number(Tri->GetH());



             ui->label_2->setText(s);
             ui->label_4->setText(v);


             ui->lineEdit->setText(A);
             ui->lineEdit_2->setText(B);
             ui->lineEdit_3->setText(C);
             ui->lineEdit_4->setText(h);

             DrawTrianglePrism(Tri->GetA(),Tri->GetB(),Tri->GetC(), Tri->GetH());

             delete Tri;

         }
       }

    else{ErrorMes("Next element does not exist");}

      }













 void MainWindow::on_pushButton_4_clicked() // Отслеживаем нажатия кнопки Next
 {
     if(col->getNumber()+1 >= 2)
     {

     Cylinder* Cyl = col->getCylinder(col->getNumber()+1);


     if(Cyl->WhatType() == 0)
     {
         DisplayMenu("Circle cylinder");

         CircleCylinder* Cir = static_cast<CircleCylinder*>(Cyl);

     QString S = QString::number(Cir->GetSquare());
     QString V = QString::number(Cir->CalcVolume());
     QString R = QString::number(Cir->GetR());
      QString H = QString::number(Cir->GetH());


         ui->label_2->setText(S);
         ui->label_4->setText(V);

         ui->lineEdit->setText(R);
         ui->lineEdit_3->setText(H);


         delete Cir;
       }

     else if(Cyl->WhatType()==1)
     {
         DisplayMenu("Triangle cylinder");

          TriangleCylinder* Tri  = static_cast<TriangleCylinder*>(Cyl);

          QString s = QString::number(Tri->GetSquare());
          QString v = QString::number(Tri->CalcVolume());

          QString A = QString::number(Tri->GetA());
          QString B = QString::number(Tri->GetB());
          QString C = QString::number(Tri->GetC());
          QString h = QString::number(Tri->GetH());



              ui->label_2->setText(s);
              ui->label_4->setText(v);


              ui->lineEdit->setText(A);
              ui->lineEdit_2->setText(B);
              ui->lineEdit_3->setText(C);
              ui->lineEdit_4->setText(h);

          }
        }

     else{ErrorMes("Next element does not exist");}

       }



 void MainWindow::on_pushButton_5_clicked() //Отслеживаем нажатия на кнопку Draw
 {

    //Добавь сюда try
    //Нужно не только прятать ненужные кнопки, но и блокировать их
     //Возможно нужно удалять текст из lineEdit //Уже удалил.

     //Порядок работы на завтра: 1. Доделать чтение введенных данных и кнопку "Draw", подключив к ней исключения 2. Разобраться в работе с коллекцией и подключить её к кнопкам
     //Проверить на предмет вылетов(Не  долго), Оставить свои комментарии к коду.

//Кнопка Draw работает, но если что-то ввести, а потом стереть, то сообщение об ошибке не выводится




QString h = ui->comboBox->currentText();

try{

  if(h=="Triangle")
  {

        if(ui->lineEdit->hasAcceptableInput() && ui->lineEdit_2->hasAcceptableInput() && ui->lineEdit_3->hasAcceptableInput())
           {
              DrawTriangle(ui->lineEdit->text().toDouble(),ui->lineEdit_2->text().toDouble(),ui->lineEdit_3->text().toDouble());
            }


  }

  else if(h=="Circle")
  {
        if(ui->lineEdit->isModified())
       {DrawCircle(ui->lineEdit->text().toDouble());}
  }

  else if(h=="Triangle cylinder")
  {
      if(ui->lineEdit->hasAcceptableInput() && ui->lineEdit_2->hasAcceptableInput() && ui->lineEdit_3->hasAcceptableInput() && ui->lineEdit_4->hasAcceptableInput())
      {DrawTrianglePrism(ui->lineEdit->text().toDouble(),ui->lineEdit_2->text().toDouble(),ui->lineEdit_3->text().toDouble(), ui->lineEdit_4->text().toDouble());}
  }



  else if(h=="Circle cylinder")
  {
      if(ui->lineEdit->isModified() && ui->lineEdit_2->isModified() )
      {DrawCylinder(ui->lineEdit->text().toDouble(),ui->lineEdit_2->text().toDouble());}
  }

}

catch(Exception e)
{
    ErrorMes(e.GetMessage());



}


}







//Отображение окна

void MainWindow::Update_Menu()
{

ui->comboBox->blockSignals(true);
 ui->comboBox->clear();
    ui->comboBox->addItem("Triangle");
    ui->comboBox->addItem("Circle");
    ui->comboBox->addItem("Triangle cylinder");
    ui->comboBox->addItem("Circle cylinder");

ui->comboBox->blockSignals(false);

DisplayMenu("Triangle");

}

void MainWindow::DisplayMenu(QString t)
{

    if(t == "Circle cylinder")
      {
       if(paper!= nullptr)
                {
                   delete paper;
                   paper = nullptr;
                }

       ui->lineEdit->clear();

       ui->lineEdit_2->clear();

       ui->lineEdit_3->clear();

       ui->lineEdit_4->clear();

       ui->lineEdit->blockSignals(true);

       ui->lineEdit_2->blockSignals(true);

       ui->lineEdit_3->blockSignals(true);

       ui->lineEdit_4->blockSignals(true);


       ui->lineEdit->blockSignals(false);

       ui->lineEdit_2->blockSignals(false);

       ui->lineEdit_3->blockSignals(false);

       ui->lineEdit_4->blockSignals(false);



        ui->label->setText("Square");
        ui->label_3->setText("Volume");

        ui->label->setVisible(true);
         ui->label_2->setVisible(true);
          ui->label_3->setVisible(true);
           ui->label_4->setVisible(true);
            ui->label_5->setVisible(true);
             ui->label_6->setVisible(true);

              ui->lineEdit->setVisible(true);
              ui->lineEdit_2->setVisible(true);



        ui->label_5->setText("Radius");
        ui->label_6->setText("Height");

        ui->label_7->setVisible(false);
        ui->label_8->setVisible(false);
        ui->lineEdit_3->setVisible(false);
         ui->lineEdit_4->setVisible(false);
         ui->lineEdit_3->blockSignals(true);
         ui->lineEdit_4->blockSignals(true);



    }


    if(t == "Triangle cylinder")
    {

        if(paper!= nullptr)
                {
                   delete paper;
                   paper = nullptr;
                }



        ui->lineEdit->clear();

        ui->lineEdit_2->clear();

        ui->lineEdit_3->clear();

        ui->lineEdit_4->clear();

        ui->lineEdit->blockSignals(true);

        ui->lineEdit_2->blockSignals(true);

        ui->lineEdit_3->blockSignals(true);

        ui->lineEdit_4->blockSignals(true);


        ui->lineEdit->blockSignals(false);

        ui->lineEdit_2->blockSignals(false);

        ui->lineEdit_3->blockSignals(false);

        ui->lineEdit_4->blockSignals(false);

        ui->label->setVisible(true);
         ui->label_2->setVisible(true);
          ui->label_3->setVisible(true);
           ui->label_4->setVisible(true);
            ui->label_5->setVisible(true);
             ui->label_6->setVisible(true);
             ui->label_7->setVisible(true);
             ui->label_8->setVisible(true);


             ui->lineEdit->setVisible(true);
             ui->lineEdit_2->setVisible(true);
             ui->lineEdit_3->setVisible(true);
             ui->lineEdit_4->setVisible(true);

             ui->lineEdit->blockSignals(false);
             ui->lineEdit_2->blockSignals(false);
             ui->lineEdit_3->blockSignals(false);
             ui->lineEdit_4->blockSignals(false);

             ui->label->setText("Square");
             ui->label_3->setText("Volume");

             ui->label_5->setText("Side A");
             ui->label_6->setText("Side B");
              ui->label_7->setText("Side C");
               ui->label_8->setText("Height");
                }




    if(t=="Circle")
   {


            if(paper!= nullptr)
                    {
                       delete paper;
                       paper = nullptr;
                    }





            ui->lineEdit->clear();

            ui->lineEdit_2->clear();

            ui->lineEdit_3->clear();

            ui->lineEdit_4->clear();

            ui->lineEdit->blockSignals(true);

            ui->lineEdit_2->blockSignals(true);

            ui->lineEdit_3->blockSignals(true);

            ui->lineEdit_4->blockSignals(true);


            ui->lineEdit->blockSignals(false);

            ui->lineEdit_2->blockSignals(false);

            ui->lineEdit_3->blockSignals(false);

            ui->lineEdit_4->blockSignals(false);




            ui->label->setVisible(true);
               ui->label->setText("Square");
                  ui->label_2->setVisible(true);

            ui->label_3->setVisible(false);
             ui->label_4->setVisible(false);

             ui->label_6->setVisible(false);
              ui->label_7->setVisible(false);
              ui->label_8->setVisible(false);


              ui->lineEdit_2->setVisible(false);
              ui->lineEdit_3->setVisible(false);
                 ui->lineEdit_4->setVisible(false);


             ui->label_5->setText("Radius");




                    }



        if(t=="Triangle")
       {


                if(paper!= nullptr)
                        {
                           delete paper;
                           paper = nullptr;
                        }



                ui->lineEdit->clear();

                ui->lineEdit_2->clear();

                ui->lineEdit_3->clear();

                ui->lineEdit_4->clear();

                ui->lineEdit->blockSignals(true);

                ui->lineEdit_2->blockSignals(true);

                ui->lineEdit_3->blockSignals(true);

                ui->lineEdit_4->blockSignals(true);


                ui->lineEdit->blockSignals(false);

                ui->lineEdit_2->blockSignals(false);

                ui->lineEdit_3->blockSignals(false);

                ui->lineEdit_4->blockSignals(false);


                ui->label->setVisible(true);
                 ui->label_2->setVisible(true);
                  ui->label_3->setVisible(false);
                   ui->label_4->setVisible(false);
                    ui->label_5->setVisible(true);
                     ui->label_6->setVisible(true);
                     ui->label_7->setVisible(true);
                     ui->label_8->setVisible(false);


                     ui->lineEdit->setVisible(true);
                     ui->lineEdit_2->setVisible(true);
                     ui->lineEdit_3->setVisible(true);
                     ui->lineEdit_4->setVisible(false);
                     ui->lineEdit_4->blockSignals(true);

                     ui->label->setText("Square");
                     ui->label_3->setVisible(false);

                     ui->label_5->setText("Side A");
                     ui->label_6->setText("Side B");
                      ui->label_7->setText("Side C");
                       ui->label_8->setVisible(false);
        }





}

void MainWindow::DrawTrianglePrism(double a, double b, double c, double h )
{

   paper = new QGraphicsScene(this);

        ui->graphicsView->setScene(paper);

        QPen blackpen(Qt::black);
           blackpen.setWidth(2);
           blackpen.setColor("#00000");

           QPen dotpen(Qt::black);
           dotpen.setStyle(Qt::DotLine);
           dotpen.setWidth(2);
           dotpen.setColor("#00000");

           if(h>=a && h>=b && h>=c)
               {
                   a = (a*200)/h;
                   b = (b*200)/h;
                   c = (c*200)/h;
                   h = 200;
               }
               else if(b>=c && b>=a)
               {
                   a = (a*200)/b;
                   c = (c*200)/b;
                   h = (h*200)/b;
                   b = 200;
               }
               else if(c>=b && c>=a)
               {
                   a = (a*200)/c;
                   b = (b*200)/c;
                   h = (h*200)/c;
                   c = 200;
               }
               else
               {
                   b = (b*200)/a;
                   c = (c*200)/a;
                   h = (h*200)/a;
                   a = 200;
               }


               double x = ( b*b - (c*c - a*a) )/(2*a);
               double y = sqrt( b*b - x*x);
               x = abs(x);  y = abs(y)*50 /100;

               paper->addLine(0,0, a, 0, dotpen);
               paper->addLine(0, 0, x, y, blackpen);
               paper->addLine(x, y, a, 0, blackpen);

               paper->addLine(0,-h, a, -h, blackpen);
               paper->addLine(0, -h, x, -h+y, blackpen);
               paper->addLine(x, -h+y, a, -h, blackpen);

               paper->addLine(0,0,0,-h, blackpen);
               paper->addLine(a,0,a,-h, blackpen);
               paper->addLine(x,y,x,-h+y, blackpen);



}

void MainWindow::DrawCylinder(double r, double h)
{
    paper = new QGraphicsScene(this);

    ui->graphicsView->setScene(paper);

    QPen blackpen(Qt::black);
    blackpen.setWidth(2);
    blackpen.setColor("#000000");

    QPen dotpen(Qt::black);
    dotpen.setStyle(Qt::DotLine);
    dotpen.setWidth(2);
    dotpen.setColor("#000000");

    if(h>=r*2)
    {
       r = (200*r)/h;
       h = 200;
    }
    else{
       h = (200*h)/r;
       r = 200;
    }

    double d1 = r*2;
    double d2 = 27*d1 / 100;

    paper->addEllipse(0, -h, d1, d2, blackpen);
    paper->addEllipse(0, 0, d1, d2, dotpen);
    paper->addLine(0,-h+(d2/2), 0, d2/2, blackpen);
    paper->addLine(d1,-h+(d2/2), d1, d2/2, blackpen);

    QPainterPath path;
    path.moveTo(0, d2/2);
    path.arcTo(0, 0, d1, d2, 180, 180);
    paper->addPath(path, blackpen);

}

void MainWindow::DrawTriangle(double a, double b, double c)
{

    paper = new QGraphicsScene(this);

         ui->graphicsView->setScene(paper);

         QPen blackpen(Qt::black);
            blackpen.setWidth(2);
            blackpen.setColor("#00000");






               if(b>=c && b>=a)
                {
                    a = (a*200)/b;
                    c = (c*200)/b;

                    b = 200;
                }
                else if(c>=b && c>=a)
                {
                    a = (a*200)/c;
                    b = (b*200)/c;

                    c = 200;
                }
                else
                {
                    b = (b*200)/a;
                    c = (c*200)/a;

                    a = 200;
                }










            double x = ( b*b - (c*c - a*a) )/(2*a);
            double y = sqrt( b*b - x*x);


             // A(0,0); B(0,a); C(x,y);
            paper->addLine(0,0, a, 0, blackpen);   // A(0,0); B(0,a); C(x,y);
            paper->addLine(0, 0, x, y, blackpen);
            paper->addLine(x, y, a, 0, blackpen);




}

void MainWindow::DrawCircle(double r)
{

    paper = new QGraphicsScene(this);

         ui->graphicsView->setScene(paper);

         QPen blackpen(Qt::black);
            blackpen.setWidth(2);
            blackpen.setColor("#00000");


            r=25*r;

 paper->addEllipse(0, 0, r, r, blackpen);




}




















