#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Cylinder.h"
#include "geometry.h"
#include "Exceptions.h"

#include <QMessageBox>



#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <QString>
#include <math.h>
#include <typeinfo>
using namespace std;






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::Error()
{

    QMessageBox::about(this, "error" , "Something bad happening");
}




void MainWindow::Update_Menu()
{

ui->comboBox->blockSignals(true);

    ui->comboBox->addItem("Triangle");
    ui->comboBox->addItem("Circle");
    ui->comboBox->addItem("Triangle cylinder");
    ui->comboBox->addItem("Circle cylinder");
    ui->comboBox->addItem("Circle");
ui->comboBox->blockSignals(false);

}




void MainWindow::DisplayMenu(QString t)
{

    if(t == "Circle cylinder")
      {
        /*if(paper!= nullptr)
                {
                   delete paper;
                   paper = nullptr;
                }*/

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
    }


    if(t == "Triangle cylinder")
    {

        /*if(paper!= nullptr)
                {
                   delete paper;
                   paper = nullptr;
                }*/




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

             ui->label->setText("Square");
             ui->label_3->setText("Volume");

             ui->label_5->setText("Side A");
             ui->label_6->setText("Side B");
              ui->label_7->setText("Side C");
               ui->label_8->setText("Height");
                }




    if(t=="Circle")
   {


            /*if(paper!= nullptr)
                    {
                       delete paper;
                       paper = nullptr;
                    }*/


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

                     ui->label->setText("Square");
                     ui->label_3->setVisible(false);

                     ui->label_5->setText("Side A");
                     ui->label_6->setText("Side B");
                      ui->label_7->setText("Side C");
                       ui->label_8->setVisible(false);
        }





}

void MainWindow::TryMenu()
{


    QString k = "Circle cylinder";

    DisplayMenu(k);








}









