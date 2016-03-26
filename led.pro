#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T18:31:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = led
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paint1.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    paint1.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    res.qrc
