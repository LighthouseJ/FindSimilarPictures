#-------------------------------------------------
#
# Project created by QtCreator 2010-11-06T16:49:41
#
#-------------------------------------------------

QT       += core gui

TARGET = FindSimilarPictures
TEMPLATE = app

INST_PATH = /home/nathan/Downloads/install

INCLUDEPATH += $${INST_PATH}/include
LIBS += -L$${INST_PATH}/lib -lpuzzle

SOURCES += src/main.cpp\
           src/mainwindow.cpp \
           src/directoryscanner.cpp

HEADERS  += src/mainwindow.h \
            src/directoryscanner.h

FORMS    += ui/mainwindow.ui
