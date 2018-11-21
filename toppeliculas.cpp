#include "toppeliculas.h"
#include "ui_toppeliculas.h"
#include "mainwindow.h"
#include "pelicula.h"

TopPeliculas::TopPeliculas(Pelicula peliculas[27],int num,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TopPeliculas)
{
    ui->setupUi(this);

    Pelicula top[27];

    for(int i = 0; i < 28-num; i++){

        top[i] = peliculas[i];

    }

    Pelicula aux;

    //se ordenan las peliculas de mayor  a menor
    for(int i = 0; i < 28-num; i++){

        for(int j = 0; j < 28-num; j++){

            if(top[i].getNroCalf() >= top[j].getNroCalf()){

                aux = top[i];
                top[i] = top[j];
                top[j] = aux;
            }

        }

    }

    // se ordenan las 10 con mas votos por eu promedio de calificacion
    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 9; j++){

            if(top[i].getPromCalf() >= top[j].getPromCalf()){

                aux = top[i];
                top[i] = top[j];
                top[j] = aux;


            }

        }
    }

    int ejex = 10, ejey = 90, contador = 1,gen = 0;
    QString name[5];
    QString titulo,aaa,genero,director,estudio;
    name[0] = "background-image: url(:/images/img1.jpg)";
    name[1] = "background-image: url(:/images/img2.jpg)";
    name[2] = "background-image: url(:/images/img3.jpg)";
    name[3] = "background-image: url(:/images/img4.jpg)";

    while( contador <= 10){

        QString nombreLabel = "labela"+QString::number(contador);
        QString nombreLabel1 = "labela"+QString::number(contador+1);
        QString nombreLabel2 = "labela"+QString::number(contador+2);
        QString nombreLabel3 = "labela"+QString::number(contador+3);

        QLabel *label[5];
        top[contador-1].getPelicula(titulo,aaa,director,genero,estudio);

        label[0] = new QLabel(this);
        label[1] = new QLabel(this);
        label[2] = new QLabel(this);
        label[3] = new QLabel(this);

        label[0]->setGeometry(ejex,ejey,41,51);
        label[1]->setGeometry(ejex+50,ejey-10,180,17);
        label[2]->setGeometry(ejex+50,ejey+10,141,15);
        label[3]->setGeometry(ejex+50,ejey+25,141,25);


        if(genero == "Terror")
        {
            gen = 0;
        }
        else if( genero == "Comedia"){
            gen = 1;
        }else if( genero == "Misterio")
        {
                gen = 2;
        }else{
            gen = 3;
        }

        label[0]->setStyleSheet(name[gen]);
        label[0]->setObjectName(nombreLabel);

        label[1]->setStyleSheet("font: 75 14pt 'Tahoma';");
        label[1]->setStyleSheet("font-weight: bold;");

        label[1]->setObjectName(nombreLabel1);
        label[2]->setObjectName(nombreLabel2);
        label[3]->setObjectName(nombreLabel3);
        label[3]->setStyleSheet("color: rgba(255,255,255);");
        label[2]->setStyleSheet("color: rgba(255,255,255);");
        label[1]->setStyleSheet("color: rgba(255,255,255);");
        QString title = titulo+", "+aaa+", "+QString::number(top[contador-1].getPromCalf(),'f',1)+" Prom Calf";
        label[1]->setText(title);
        label[2]->setText(genero);
        label[3]->setText(director+" \n"+estudio);

         ejex += 240;
        if( contador%2 == 0 ){
            ejey += 70;
            ejex = 10;

        }

        contador++;
    }


}

TopPeliculas::~TopPeliculas()
{
    delete ui;
}

void TopPeliculas::on_regresar_clicked()
{
    close();
}
