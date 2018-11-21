#-------------------------------------------------
#
# Project created by QtCreator 2010-05-06T01:07:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CatalogoPeliculas
TEMPLATE = app


SOURCES += main.cpp\
    toppeliculas.cpp \
    pelicula.cpp \
    mainwindow.cpp

HEADERS  += \
    toppeliculas.h \
    pelicula.h \
    mainwindow.h

FORMS    += \
    toppeliculas.ui \
    mainwindow.ui

RESOURCES += \
    imagenes.qrc
