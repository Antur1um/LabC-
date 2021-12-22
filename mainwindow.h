#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsScene>//Поверхность для рисования
#include <QGraphicsRectItem>
#include <QPainter>


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


     void Error();




private:
    Ui::MainWindow *ui;

    void Update_Menu();
    void DisplayMenu(QString);
    void ComboBox();


     QGraphicsScene *paper;





};
#endif // MAINWINDOW_H
