#ifndef INSERTARPELICULA_H
#define INSERTARPELICULA_H

#include <QMainWindow>

namespace Ui {
class insertarPelicula;
}

class insertarPelicula : public QMainWindow
{
    Q_OBJECT

public:
    explicit insertarPelicula(QWidget *parent = 0);
    ~insertarPelicula();

private slots:
    void on_pushButton_clicked();

private:
    Ui::insertarPelicula *ui;
};

#endif // INSERTARPELICULA_H
