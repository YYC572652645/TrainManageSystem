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
    traindata/qreadini.cpp \
    traininfoselect/traininfoselect.cpp \
    userinfoinsert/userinfoinsert.cpp \
    userinfoselect/userinfoselect.cpp \
    messagebox/messagedialog.cpp

HEADERS  += mainwindow.h \
    traindata/database.h \
    traindata/qreadini.h \
    globaldef.h \
    traininfoselect/traininfoselect.h \
    userinfoinsert/userinfoinsert.h \
    userinfoselect/userinfoselect.h \
    messagebox/messagedialog.h

FORMS    += mainwindow.ui \
    traininfoselect/traininfoselect.ui \
    userinfoinsert/userinfoinsert.ui \
    userinfoselect/userinfoselect.ui \
    messagebox/messagedialog.ui

RESOURCES += \
    res.qrc

RC_FILE += myapp.rc

DISTFILES +=
