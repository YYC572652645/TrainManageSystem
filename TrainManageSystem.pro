#-------------------------------------------------
#
# Project created by QtCreator 2017-09-07T12:59:12
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrainManageSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    traindata/database.cpp \
    traindata/qreadini.cpp

HEADERS  += mainwindow.h \
    traindata/database.h \
    traindata/qreadini.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

RC_FILE += myapp.rc
