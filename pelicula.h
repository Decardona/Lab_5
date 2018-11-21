#ifndef PELICULA_H
#define PELICULA_H

#include <QString>

class Pelicula
{
private:
    QString Titulo;
    QString Anio;
    QString Director;
    QString Genero;
    QString Estudio;
    int Nro_Calf;
    double Prom_Calf;
public:
    Pelicula();

    void setPelicula(QString,QString,QString,QString,QString);

    void getPelicula(QString &,QString &,QString &,QString &,QString &);

    void setNroCalf(int);

    void setPromCalf(double);

    int getNroCalf();

    double getPromCalf();
};

#endif // PELICULA_H
