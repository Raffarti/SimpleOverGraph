#-------------------------------------------------
#
# Project created by QtCreator 2013-10-03T01:57:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleOverGraph
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    outputwindow.cpp \
    dataextractor.cpp \
    graph.cpp \
    trayicon.cpp

HEADERS  += \
    mainwindow.h \
    outputwindow.h \
    dataextractor.h \
    graph.h \
    trayicon.h

FORMS    += \
    mainwindow.ui \
    outputwindow.ui

OTHER_FILES += \
    reader.py
