#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "insertpeliculas.h"

namespace Ui {
class WDMain;
}

class WDMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit WDMain(QWidget *parent = 0);
    Pelicula Peliculas[30];

    int pelic_subidas = 9;
    void Actualizar();
    ~MainWindow();

private:
    Ui::WDMain *ui;
public slots:
    void valoradas();
    void insertar();
};

#endif // MAINWINDOW_H
