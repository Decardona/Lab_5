#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "toppeliculas.h"
#include "insertpeliculas.h"
#include "pelicula.h"
#include <QFile>
#include <QString>
#include <QFileDialog>
#include <QTextStream>
#include <QWidget>
#include <QVBoxLayout>

Pelicula Peliculas[27]; //variables usadas para almacenar las peliculas
double calif_peliculas[27] = {0}; //en estas variables se al macenaran las calificaciones que se les de a cada pelicula

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    calif = 0;

     // mostrar peliculas
    QFile filecsv("C:/Users/PORTATIL-VICTOR/Desktop/CatalogoPeliculasProm/CatalogoPeliculas/peliculas.csv");  // se carga el archivo

    filecsv.open(QIODevice::ReadOnly | QIODevice::Text); //se abre para lectura unicamente
    if( filecsv.isOpen() ){ //si el archivo se abrio o esta abierto

        QString titulo,director,estudio,genero,aaa; // variables para ir guardando la informacion del archivo

        int ejex = 10, ejey = 50, contador = 1,gen = 0;
        QString name[5];
        name[0] = "background-image: url(:/images/img1.jpg)";
        name[1] = "background-image: url(:/images/img2.jpg)";
        name[2] = "background-image: url(:/images/img3.jpg)";
        name[3] = "background-image: url(:/images/img4.jpg)";

        while( !filecsv.atEnd() && contador <= 28){

            if( contador > 20){
                        if(contador == 21){

                            ui->comboBox_10->setEnabled(true);
                            ui->label_50->setText("Valorar");
                             ui->label_2->setDisabled(true);
                        }else if( contador == 22 ){

                            ui->comboBox_23->setEnabled(true);
                            ui->label_129->setText("Valorar");
                           ui->label_11->setDisabled(true);

                        }else if( contador == 23 ){

                            ui->comboBox_25->setEnabled(true);
                            ui->label_110->setText("Valorar");
                            ui->label_15->setDisabled(true);

                        }else if( contador == 24 ){

                            ui->comboBox_26->setEnabled(true);
                            ui->label_131->setText("Valorar");
                            ui->label_21->setDisabled(true);
                        }else if( contador == 25 ){

                            ui->comboBox_29->setEnabled(true);
                            ui->label_54->setText("Valorar");
                            ui->label_26->setDisabled(true);
                        }else if( contador == 26 ){

                            ui->comboBox_27->setEnabled(true);
                            ui->label_144->setText("Valorar");
                            ui->label_31->setDisabled(true);
                        }else if(contador == 27){

                            ui->comboBox_11->setEnabled(true);
                            ui->label_55->setText("Valorar");
                            ui->label_36->setDisabled(true);
                        }
            }
            QString line = filecsv.readLine();
            QStringList string = line.split(",");

            QString nombreLabel = "label"+QString::number(contador);
            QString nombreLabel1 = "label"+QString::number(contador+1);
            QString nombreLabel2 = "label"+QString::number(contador+2);
            QString nombreLabel3 = "label"+QString::number(contador+3);

            QLabel *label[5];  // se agregan 5 label dinamicamente dentro de la ventana para ir mostrando las peliculas

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

            //posicion en laventana de cada pelicula
            label[0]->setGeometry(ejex,ejey,41,51);
            label[1]->setGeometry(ejex+50,ejey-10,125,17);
            label[2]->setGeometry(ejex+50,ejey+10,125,15);
            label[3]->setGeometry(ejex+50,ejey+25,125,25);

            label[0]->setStyleSheet(name[gen]);
            label[0]->setObjectName(nombreLabel);

            label[1]->setStyleSheet("font: 75 10pt 'Tahoma';");
            label[1]->setStyleSheet("font-weight: bold;");

            label[1]->setObjectName(nombreLabel1);
            label[2]->setObjectName(nombreLabel2);
            label[3]->setObjectName(nombreLabel3);
            label[3]->setStyleSheet("background-color: rgba(255,255,255,0%);");

            //se muestra la pelicula en la ventana
            label[1]->setText(titulo+", "+aaa);
            label[2]->setText(genero);
            label[3]->setText(director+" \n"+estudio);

             ejex += 180;
            if( contador%6 == 0 ){ //se usa para saber cuando hay que mostrar una pelicula en una nueva fila
                ejey += 98;
                ejex = 10;

                if( contador >= 18)
                    ejey -= 9;
            }
            contador++;

        }
        pelic_subidas = 29-contador;
    }

    filecsv.close(); //se cierra el archivo.
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::valoradas(){

    TopPeliculas *Top;
    Top = new TopPeliculas(Peliculas,pelic_subidas,this);
    ui->label_3->setText("prim: "+QString::number(Peliculas[0].getNroCalf()));

    Top->show();
}

void MainWindow::insertar(){

    if( pelic_subidas > 1){

        QFile filecsv("C:/Users/PORTATIL-VICTOR/Desktop/CatalogoPeliculasProm/CatalogoPeliculas/peliculas.csv");  // se carga el archivo

        filecsv.open(QIODevice::Append); //se abre para lectura unicamente
        QString cadena;
        cadena = ui->lineEdit->text()+","+ui->lineEdit_2->text()+","+ui->lineEdit_3->text()+","+ui->comboBox->currentText()+","+ui->lineEdit_4->text()+"\n";
        QTextStream stream(&filecsv);
        if(filecsv.isOpen()){

            stream << cadena;
            ui->label_3->setText("se guardo en el archivo");

        }

        filecsv.close();
        int gen = 0;
        QString name[5];
        name[0] = "background-image: url(:/images/img1.jpg)";
        name[1] = "background-image: url(:/images/img2.jpg)";
        name[2] = "background-image: url(:/images/img3.jpg)";
        name[3] = "background-image: url(:/images/img4.jpg)";
        name[4] = "background-image: url(:/images/img0.jpg)";
        if( ui->comboBox->currentText() == "Terror")
        {
            gen = 0;
        }
        else if( ui->comboBox->currentText() == "Comedia"){
            gen = 1;
        }else if( ui->comboBox->currentText() == "Misterio")
        {
                gen = 2;
        }else{
            gen = 3;
        }
        // con estas estructuras de decicion se hace visible el combobox de la pelicula que se agrego y se agrega texto
        if(pelic_subidas == 8){

            ui->comboBox_10->setEnabled(true);
            ui->label_50->setText("Valorar");

            ui->label_2->setStyleSheet(name[gen]);
            ui->label_4->setText(ui->lineEdit->text()+", "+ui->lineEdit_2->text());
            ui->label_4->setStyleSheet("font-weight: bold;");

            ui->label_6->setText(ui->comboBox->currentText()+"\n"+ui->lineEdit_3->text()+"\n"+ui->lineEdit_4->text());

        }else if( pelic_subidas == 7 ){

            ui->comboBox_23->setEnabled(true);
            ui->label_129->setText("Valorar");

            ui->label_11->setStyleSheet(name[gen]);
            ui->label_7->setText(ui->lineEdit->text()+", "+ui->lineEdit_2->text());
            ui->label_7->setStyleSheet("font-weight: bold;");

            ui->label_9->setText(ui->comboBox->currentText()+"\n"+ui->lineEdit_3->text()+"\n"+ui->lineEdit_4->text());

        }else if( pelic_subidas == 6 ){

            ui->comboBox_25->setEnabled(true);
            ui->label_110->setText("Valorar");

            ui->label_15->setStyleSheet(name[gen]);
            ui->label_12->setText(ui->lineEdit->text()+", "+ui->lineEdit_2->text());
            ui->label_12->setStyleSheet("font-weight: bold;");

            ui->label_14->setText(ui->comboBox->currentText()+"\n"+ui->lineEdit_3->text()+"\n"+ui->lineEdit_4->text());

        }else if( pelic_subidas == 5 ){

            ui->comboBox_26->setEnabled(true);
            ui->label_131->setText("Valorar");

            ui->label_21->setStyleSheet(name[gen]);
            ui->label_17->setText(ui->lineEdit->text()+", "+ui->lineEdit_2->text());
            ui->label_17->setStyleSheet("font-weight: bold;");

            ui->label_20->setText(ui->comboBox->currentText()+"\n"+ui->lineEdit_3->text()+"\n"+ui->lineEdit_4->text());

        }else if( pelic_subidas == 4 ){

            ui->comboBox_29->setEnabled(true);
            ui->label_54->setText("Valorar");

            ui->label_26->setStyleSheet(name[gen]);
            ui->label_22->setText(ui->lineEdit->text()+", "+ui->lineEdit_2->text());
            ui->label_22->setStyleSheet("font-weight: bold;");

            ui->label_24->setText(ui->comboBox->currentText()+"\n"+ui->lineEdit_3->text()+"\n"+ui->lineEdit_4->text());

        }else if( pelic_subidas == 3 ){

            ui->comboBox_27->setEnabled(true);
            ui->label_144->setText("Valorar");

            ui->label_31->setStyleSheet(name[gen]);
            ui->label_28->setText(ui->lineEdit->text()+", "+ui->lineEdit_2->text());
            ui->label_28->setStyleSheet("font-weight: bold;");

            ui->label_30->setText(ui->comboBox->currentText()+"\n"+ui->lineEdit_3->text()+"\n"+ui->lineEdit_4->text());

        }else{

            ui->comboBox_11->setEnabled(true);
            ui->label_55->setText("Valorar");

            ui->label_36->setStyleSheet(name[gen]);
            ui->label_33->setText(ui->lineEdit->text()+", "+ui->lineEdit_2->text());
            ui->label_33->setStyleSheet("font-weight: bold;");

            ui->label_35->setText(ui->comboBox->currentText()+"\n"+ui->lineEdit_3->text()+"\n"+ui->lineEdit_4->text());

        }

        pelic_subidas--; // se desminuye el numero de peliculas que el usuario puede subir

        Peliculas[27-pelic_subidas].setPelicula(ui->lineEdit->text(),ui->lineEdit_2->text()
                                                ,ui->lineEdit_3->text(),ui->comboBox->currentText(),
                                                ui->lineEdit_4->text());
        ui->lineEdit->setText("Titulo");
        ui->lineEdit_2->setText("aaa");
        ui->lineEdit_3->setText("Director");
        ui->lineEdit_4->setText("Estudio");


    }else{
        //se le informa al usuario que no puede agregar mas peliculas por medio de el label
        ui->label_3->setText("No se pueden agregar mas peliculas");
    }

}

void MainWindow::on_comboBox_2_activated(int index)
{
        int calfc = Peliculas[0].getNroCalf()+index;

        calif++;
        Peliculas[0].setNroCalf(calfc);
        calif_peliculas[0] += 1;
        Peliculas[0].setPromCalf(calfc/calif_peliculas[0]);
        ui->label_10->setText("+"+QString::number(index));

}

void MainWindow::on_comboBox_4_activated(int index)
{
    int calfc = Peliculas[1].getNroCalf()+index;
    calif++;
    Peliculas[1].setNroCalf(calfc);
    calif_peliculas[1] += 1;
    Peliculas[1].setPromCalf(calfc/calif_peliculas[1]);

    ui->label_16->setText("+"+ui->comboBox_4->currentText());
}

void MainWindow::on_comboBox_3_activated(int index)
{
    int calfc = Peliculas[2].getNroCalf()+index;
    calif++;
    Peliculas[2].setNroCalf(calfc);
    calif_peliculas[2] += 1;
    Peliculas[2].setPromCalf(calfc/calif_peliculas[2]);

    ui->label_18->setText("+"+ui->comboBox_3->currentText());
}
void MainWindow::on_comboBox_6_activated(int index)
{
    int calfc = Peliculas[3].getNroCalf()+index;
    calif++;
    Peliculas[3].setNroCalf(calfc);
    calif_peliculas[3] += 1;
    Peliculas[3].setPromCalf(calfc/calif_peliculas[3]);

    ui->label_25->setText("+"+ui->comboBox_6->currentText());
}
void MainWindow::on_comboBox_5_activated(int index)
{
    int calfc = Peliculas[4].getNroCalf()+index;
    calif++;
    Peliculas[4].setNroCalf(calfc);
    calif_peliculas[4] += 1;
    Peliculas[4].setPromCalf(calfc/calif_peliculas[4]);

    ui->label_27->setText("+"+ui->comboBox_5->currentText());
}
void MainWindow::on_comboBox_7_activated(int index)
{
    int calfc = Peliculas[5].getNroCalf()+index;
    calif++;
    Peliculas[5].setNroCalf(calfc);
    calif_peliculas[5] += 1;
    Peliculas[5].setPromCalf(calfc/calif_peliculas[5]);
    ui->label_32->setText("+"+ui->comboBox_7->currentText());
}
void MainWindow::on_comboBox_14_activated(int index)
{
    int calfc = Peliculas[6].getNroCalf()+index;
    calif++;
    Peliculas[6].setNroCalf(calfc);
    calif_peliculas[6] += 1;
    Peliculas[6].setPromCalf(calfc/calif_peliculas[6]);

    ui->label_39->setText("+"+ui->comboBox_14->currentText());
}
void MainWindow::on_comboBox_12_activated(int index)
{
    int calfc = Peliculas[7].getNroCalf()+index;
    calif++;
    Peliculas[7].setNroCalf(calfc);
    calif_peliculas[7] += 1;
    Peliculas[7].setPromCalf(calfc/calif_peliculas[7]);

    ui->label_69->setText("+"+ui->comboBox_12->currentText());
}
void MainWindow::on_comboBox_8_activated(int index)
{
    int calfc = Peliculas[8].getNroCalf()+index;
    calif++;
    Peliculas[8].setNroCalf(calfc);
    calif_peliculas[8] += 1;
    Peliculas[8].setPromCalf(calfc/calif_peliculas[8]);
    ui->label_40->setText("+"+ui->comboBox_8->currentText());
}
void MainWindow::on_comboBox_13_activated(int index)
{
    int calfc = Peliculas[9].getNroCalf()+index;
    calif++;
    Peliculas[9].setNroCalf(calfc);
    calif_peliculas[9] += 1;
    Peliculas[9].setPromCalf(calfc/calif_peliculas[9]);
    ui->label_78->setText("+"+ui->comboBox_13->currentText());
}
void MainWindow::on_comboBox_15_activated(int index)
{
    int calfc = Peliculas[10].getNroCalf()+index;
    calif++;
    Peliculas[10].setNroCalf(calfc);
    calif_peliculas[10] += 1;
    Peliculas[10].setPromCalf(calfc/calif_peliculas[10]);

    ui->label_60->setText("+"+ui->comboBox_15->currentText());
}
void MainWindow::on_comboBox_16_activated(int index)
{
    int calfc = Peliculas[11].getNroCalf()+index;
    calif++;
    Peliculas[11].setNroCalf(calfc);
    calif_peliculas[11] += 1;
    Peliculas[11].setPromCalf(calfc/calif_peliculas[11]);

    ui->label_80->setText("+"+ui->comboBox_16->currentText());
}

void MainWindow::on_comboBox_19_activated(int index)
{
    int calfc = Peliculas[12].getNroCalf()+index;
    calif++;
    Peliculas[12].setNroCalf(calfc);
    calif_peliculas[12] += 1;
    Peliculas[12].setPromCalf(calfc/calif_peliculas[12]);

    ui->label_44->setText("+"+ui->comboBox_19->currentText());
}
void MainWindow::on_comboBox_17_activated(int index)
{
    int calfc = Peliculas[13].getNroCalf()+index;
    calif++;
    Peliculas[13].setNroCalf(calfc);
    calif_peliculas[13] += 1;
    Peliculas[13].setPromCalf(calfc/calif_peliculas[13]);
    ui->label_93->setText("+"+ui->comboBox_17->currentText());
}
void MainWindow::on_comboBox_9_activated(int index)
{
    int calfc = Peliculas[14].getNroCalf()+index;
    calif++;
    Peliculas[14].setNroCalf(calfc);
    calif_peliculas[14] += 1;
    Peliculas[14].setPromCalf(calfc/calif_peliculas[14]);
    ui->label_45->setText("+"+ui->comboBox_9->currentText());
}
void MainWindow::on_comboBox_18_activated(int index)
{
    int calfc = Peliculas[15].getNroCalf()+index;
    calif++;
    Peliculas[15].setNroCalf(calfc);
    calif_peliculas[15] += 1;
    Peliculas[15].setPromCalf(calfc/calif_peliculas[15]);
    ui->label_102->setText("+"+ui->comboBox_18->currentText());
}
void MainWindow::on_comboBox_20_activated(int index)
{
    int calfc = Peliculas[16].getNroCalf()+index;
    calif++;
    Peliculas[16].setNroCalf(calfc);
    calif_peliculas[16] += 1;
    Peliculas[16].setPromCalf(calfc/calif_peliculas[16]);
    ui->label_84->setText("+"+ui->comboBox_20->currentText());
}
void MainWindow::on_comboBox_21_activated(int index)
{
    int calfc = Peliculas[17].getNroCalf()+index;
    calif++;
    Peliculas[17].setNroCalf(calfc);
    calif_peliculas[17] += 1;
    Peliculas[17].setPromCalf(calfc/calif_peliculas[17]);
    ui->label_104->setText("+"+ui->comboBox_21->currentText());
}
void MainWindow::on_comboBox_24_activated(int index)
{
    int calfc = Peliculas[18].getNroCalf()+index;
    calif++;
    Peliculas[18].setNroCalf(calfc);
    calif_peliculas[18] += 1;
    Peliculas[18].setPromCalf(calfc/calif_peliculas[18]);
    ui->label_49->setText("+"+ui->comboBox_24->currentText());
}
void MainWindow::on_comboBox_22_activated(int index)
{
    int calfc = Peliculas[19].getNroCalf()+index;
    calif++;
    Peliculas[19].setNroCalf(calfc);
    calif_peliculas[19] += 1;
    Peliculas[19].setPromCalf(calfc/calif_peliculas[19]);
    ui->label_119->setText("+"+ui->comboBox_22->currentText());
}
void MainWindow::on_comboBox_10_activated(int index)
{
    int calfc = Peliculas[20].getNroCalf()+index;
    calif++;
    Peliculas[20].setNroCalf(calfc);
    calif_peliculas[20] += 1;
    Peliculas[20].setPromCalf(calfc/calif_peliculas[20]);
    ui->label_50->setText("+"+ui->comboBox_10->currentText());
}
void MainWindow::on_comboBox_23_activated(int index)
{
    int calfc = Peliculas[21].getNroCalf()+index;
    calif++;
    Peliculas[21].setNroCalf(calfc);
    calif_peliculas[21] += 1;
    Peliculas[21].setPromCalf(calfc/calif_peliculas[21]);
    ui->label_129->setText("+"+ui->comboBox_23->currentText());
}
void MainWindow::on_comboBox_25_activated(int index)
{
    int calfc = Peliculas[22].getNroCalf()+index;
    calif++;
    Peliculas[22].setNroCalf(calfc);
    calif_peliculas[22] += 1;
    Peliculas[22].setPromCalf(calfc/calif_peliculas[22]);
    ui->label_110->setText("+"+ui->comboBox_25->currentText());
}
void MainWindow::on_comboBox_26_activated(int index)
{
    int calfc = Peliculas[23].getNroCalf()+index;
    calif++;
    Peliculas[23].setNroCalf(calfc);
    calif_peliculas[23] += 1;
    Peliculas[23].setPromCalf(calfc/calif_peliculas[23]);
    ui->label_131->setText("+"+ui->comboBox_26->currentText());
}
void MainWindow::on_comboBox_29_activated(int index)
{
    int calfc = Peliculas[24].getNroCalf()+index;
    calif++;
    Peliculas[24].setNroCalf(calfc);
    calif_peliculas[24] += 1;
    Peliculas[24].setPromCalf(calfc/calif_peliculas[24]);
    ui->label_54->setText("+"+ui->comboBox_29->currentText());
}
void MainWindow::on_comboBox_27_activated(int index)
{
    int calfc = Peliculas[25].getNroCalf()+index;
    calif++;
    Peliculas[25].setNroCalf(calfc);
    calif_peliculas[25] += 1;
    Peliculas[25].setPromCalf(calfc/calif_peliculas[25]);
    ui->label_144->setText("+"+ui->comboBox_27->currentText());
}
void MainWindow::on_comboBox_11_activated(int index)
{
    int calfc = Peliculas[26].getNroCalf()+index;
    calif++;
    Peliculas[26].setNroCalf(calfc);
    calif_peliculas[26] += 1;
    Peliculas[26].setPromCalf(calfc/calif_peliculas[26]);
    ui->label_55->setText("+"+ui->comboBox_11->currentText());
}
