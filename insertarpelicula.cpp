#include "insertarpelicula.h"
#include "ui_insertarpelicula.h"
#include "mainwindow.h"

insertarPelicula::insertarPelicula(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::insertarPelicula)
{
    ui->setupUi(this);
}

insertarPelicula::~insertarPelicula()
{
    delete ui;
}

void insertarPelicula::on_pushButton_clicked()
{
    MainWindow *Abrir = new MainWindow();

    Abrir->show();
    close();
}
