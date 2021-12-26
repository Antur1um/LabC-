#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

#include <QGraphicsScene>  //Поверхность для рисования
#include <QGraphicsRectItem>
#include <QPainter>


#include "Cylinder.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

      void TryMenu();


    ~MainWindow();


     void ErrorMes(QString mes);

     void DrawCircle(double);
     void DrawTriangle(double,double,double);
     void DrawTrianglePrism(double, double, double, double);
     void DrawCylinder(double,double);






private slots:

     void on_comboBox_currentTextChanged(const QString &arg1);

     void on_pushButton_clicked();
      void on_pushButton_2_clicked();
        void on_pushButton_3_clicked();
      void on_pushButton_4_clicked();
      void on_pushButton_5_clicked();









private:
    Ui::MainWindow *ui;



    double QstringtoNumber();
    void Update_Menu();
    void DisplayMenu(QString);
    void ComboBox();
    void WhatBuild(QString);

     QGraphicsScene *paper;

     CylinderCollection* col;





};
#endif // MAINWINDOW_H
