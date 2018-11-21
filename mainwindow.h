#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "insertpeliculas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int pelic_subidas;
    int calif;
public slots:
    void valoradas();
    void insertar();
private slots:
    void on_comboBox_14_activated(int index);
    void on_comboBox_12_activated(int index);
    void on_comboBox_4_activated(int index);
    void on_comboBox_2_activated(int index);
    void on_comboBox_3_activated(int index);
    void on_comboBox_6_activated(int index);
    void on_comboBox_5_activated(int index);
    void on_comboBox_7_activated(int index);
    void on_comboBox_8_activated(int index);
    void on_comboBox_15_activated(int index);
    void on_comboBox_16_activated(int index);
    void on_comboBox_19_activated(int index);
    void on_comboBox_13_activated(int index);
    void on_comboBox_17_activated(int index);
    void on_comboBox_9_activated(int index);
    void on_comboBox_18_activated(int index);
    void on_comboBox_20_activated(int index);
    void on_comboBox_21_activated(int index);
    void on_comboBox_24_activated(int index);
    void on_comboBox_22_activated(int index);
    void on_comboBox_10_activated(int index);
    void on_comboBox_23_activated(int index);
    void on_comboBox_25_activated(int index);
    void on_comboBox_26_activated(int index);
    void on_comboBox_29_activated(int index);
    void on_comboBox_27_activated(int index);
    void on_comboBox_11_activated(int index);


};

#endif // MAINWINDOW_H
