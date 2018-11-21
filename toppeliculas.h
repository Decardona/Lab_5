#ifndef TOPPELICULAS_H
#define TOPPELICULAS_H

#include <QMainWindow>
#include "pelicula.h"

namespace Ui {
class TopPeliculas;
}

class TopPeliculas : public QMainWindow
{
    Q_OBJECT

public:
    explicit TopPeliculas(Pelicula pelic[27],int num,QWidget *parent = 0);
    ~TopPeliculas();

private slots:
    void on_regresar_clicked();

private:
    Ui::TopPeliculas *ui;
};

#endif // TOPPELICULAS_H
