#include "pelicula.h"

Pelicula::Pelicula()
{
    Nro_Calf = 0;
    Prom_Calf = 0;
}

void Pelicula::setPelicula(QString title, QString aaa, QString Direct, QString gen, QString Estd){

    Titulo = title;
    Anio = aaa;
    Director = Direct;
    Genero = gen;
    Estudio = Estd;
}

void Pelicula::getPelicula(QString &titul, QString &anio, QString &direct, QString &gen, QString &estd){

    titul = Titulo;
    anio = Anio;
    direct = Director;
    gen = Genero;
    estd = Estudio;
}

void Pelicula::setNroCalf(int nro){

    Nro_Calf = nro;
}

void Pelicula::setPromCalf(double prom){

    Prom_Calf = prom;
}

int Pelicula::getNroCalf(){

    return Nro_Calf;
}

double Pelicula::getPromCalf(){

    return Prom_Calf;
}
