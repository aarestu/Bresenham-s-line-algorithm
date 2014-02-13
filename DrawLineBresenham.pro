#-------------------------------------------------
#
# Project created by QtCreator 2014-02-13T17:10:14
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = DrawLineBresenham
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH += D://opencv//sources//opencv_bin//install//include

LIBS += D://opencv//sources//opencv_bin//bin//*.dll
