#include "wdmain.h"
#include "ui_WDMain.h"
#include "toppeliculas.h"
#include "insertpeliculas.h"
#include "pelicula.h"
#include <QFile>  //libreria para
#include <QString>
#include <QFileDialog>
#include <QTextStream>
#include <QWidget>

{
WDMain::WDMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WDMain)
{
    ui->setupUi(this);

     // mostrar peliculas
    QFile filecsv("C:/Users/erick/Downloads/peliculas.csv");

    filecsv.open(QIODevice::ReadOnly | QIODevice::Text);
    if( filecsv.isOpen() ){

        QString titulo,director,estudio,genero,aaa;

        int ejex = 10, ejey = 50, contador = 1,gen = 0;
        QString name[5];
        name[0] = "background-image: url(:/images/f4.jpg)";
        name[1] = "background-image: url(:/images/f4.jpg)";
        name[2] = "background-image: url(:/images/f4.jpg)";
        name[3] = "background-image: url(:/images/f4.jpg)";



        while(!filecsv.atEnd() && contador <= 29){
            QString line = filecsv.readLine();
            QStringList string = line.split(",");

            QString nombreLabel = "label"+QString::number(contador);
            QString nombreLabel1 = "label"+QString::number(contador+1);
            QString nombreLabel2 = "label"+QString::number(contador+2);
            QString nombreLabel3 = "label"+QString::number(contador+3);

            QLabel *label[5];

            titulo = string.value(0);
            aaa = string.value(1);
            director = string.value(2);
            genero = string.value(3);
            estudio = string.value(4);

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

             Peliculas[contador-1].setPelicula(titulo,aaa,director,genero,estudio);
             Peliculas[contador-1].setNroCalf(0);
             Peliculas[contador-1].setPromCalf(0);


            label[0] = new QLabel(this);
            label[1] = new QLabel(this);
            label[2] = new QLabel(this);
            label[3] = new QLabel(this);

            label[0]->setGeometry(ejex,ejey,41,51);
            label[1]->setGeometry(ejex+50,ejey-10,141,17);
            label[2]->setGeometry(ejex+50,ejey+10,141,15);
            label[3]->setGeometry(ejex+50,ejey+25,141,25);

            label[0]->setStyleSheet(name[gen]);
            label[0]->setObjectName(nombreLabel);

            label[1]->setStyleSheet("font: 75 10pt 'Tahoma';");
            label[1]->setStyleSheet("font-weight: bold;");

            label[1]->setObjectName(nombreLabel1);
            label[2]->setObjectName(nombreLabel2);
            label[3]->setObjectName(nombreLabel3);
            label[3]->setStyleSheet("background-color: rgba(255,255,255,0%);");

            label[1]->setText(titulo+", "+aaa);
            label[2]->setText(genero);
            label[3]->setText(director+" \n"+estudio);

             ejex += 180;
            if( contador%6 == 0 ){
                ejey += 98;
                ejex = 10;

                if( contador >= 18)
                    ejey -= 9;
            }
            contador++;

        }
    }

    filecsv.close();
}

WDMain::~WDMain()
{
    delete ui;
}


void WDMain::Actualizar(int pos)
{
    QFile filecsv("C:/Users/erick/Downloads/peliculas.csv");
    pos = pelic_subidas;
    filecsv.open(QIODevice::ReadOnly | QIODevice::Text);

    if( filecsv.isOpen() ){

        QString titulo,director,estudio,genero,aaa;
        int ejex = 190, ejey = 344, contador = 1,gen = 0;
        QString name[5];
        name[0] = "background-image: url(:/images/f4.jpg)";
        name[1] = "background-image: url(:/images/f4.jpg)";
        name[2] = "background-image: url(:/images/f4.jpg)";
        name[3] = "background-image: url(:/images/f4.jpg)";

        while(!filecsv.atEnd() && contador <= 29){
            if( contador == 30-pos){
                QString line = filecsv.readLine();
                QStringList string = line.split(",");

                QString nombreLabel = "label"+QString::number(contador);
                QString nombreLabel1 = "label"+QString::number(contador+1);
                QString nombreLabel2 = "label"+QString::number(contador+2);
                QString nombreLabel3 = "label"+QString::number(contador+3);

                QLabel *label[5];

                titulo = string.value(0);
                aaa = string.value(1);
                director = string.value(2);
                genero = string.value(3);
                estudio = string.value(4);

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

                Peliculas[30-pos].setPelicula(titulo,aaa,director,genero,estudio);


                label[0] = new QLabel();
                label[1] = new QLabel();
                label[2] = new QLabel();
                label[3] = new QLabel();

                if( pos > 5){

                    ejex = ejex + 180*(30-pos);

                    label[0]->setGeometry(ejex,ejey,41,51);
                    label[1]->setGeometry(ejex+50,ejey-10,141,17);
                    label[2]->setGeometry(ejex+50,ejey+10,141,15);
                    label[3]->setGeometry(ejex+50,ejey+25,141,25);
                    if(pos == 6)
                        ejey = ejey + 98;
                }else{

                    ejex = ejex + 180*(30-pos);

                    label[0]->setGeometry(ejex,ejey,41,51);
                    label[1]->setGeometry(ejex+50,ejey-10,141,17);
                    label[2]->setGeometry(ejex+50,ejey+10,141,15);
                    label[3]->setGeometry(ejex+50,ejey+25,141,25);
                }

                label[0]->setStyleSheet(name[gen]);
                label[0]->setObjectName(nombreLabel);

                label[1]->setStyleSheet("font: 75 10pt 'Tahoma';");
                label[1]->setStyleSheet("font-weight: bold;");

                label[1]->setObjectName(nombreLabel1);
                label[2]->setObjectName(nombreLabel2);
                label[3]->setObjectName(nombreLabel3);
                label[3]->setStyleSheet("background-color: rgba(255,255,255,0%);");

                label[1]->setText(titulo+", "+aaa);
                label[2]->setText(genero);
                label[3]->setText(director+" \n"+estudio);


                contador++;

            }
        }

    }
}

void WDMain::valoradas(){

    TopPeliculas *Top =  new TopPeliculas(Peliculas,this);

    Top->show();
    close();
}

void WDMain::insertar(){

    InsertPeliculas *Insertar = new InsertPeliculas();

    if( pelic_subidas > 0){

        Insertar->show();
        if(pelic_subidas == 9){

            ui->comboBox_10->setEnabled(true);
            ui->label_50->setText("Valorar");
        }
        else if( pelic_subidas == 8 ){

            ui->comboBox_23->setEnabled(true);
            ui->label_129->setText("Valorar");
        }else if( pelic_subidas == 7 ){

            ui->comboBox_25->setEnabled(true);
            ui->label_110->setText("Valorar");

        }else if( pelic_subidas == 6 ){

            ui->comboBox_26->setEnabled(true);
            ui->label_131->setText("Valorar");

        }else if( pelic_subidas == 5 ){

            ui->comboBox_29->setEnabled(true);
            ui->label_54->setText("Valorar");

        }else if( pelic_subidas == 4 ){

            ui->comboBox_27->setEnabled(true);
            ui->label_144->setText("Valorar");

        }else if( pelic_subidas == 3 ){

            ui->comboBox_11->setEnabled(true);
            ui->label_55->setText("Valorar");
        }else if( pelic_subidas == 2 ){


            ui->comboBox_28->setEnabled(true);
            ui->label_154->setText("Valorar");
        }else if( pelic_subidas == 1 ){

            ui->comboBox_30->setEnabled(true);
            ui->label_135->setText("Valorar");
        }

        pelic_subidas--;
        close();
    }else{

        ui->label_3->setText("No se pueden agregar mas peliculas");
    }

}
