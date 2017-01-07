#-------------------------------------------------
#
# Project created by QtCreator 2017-01-07T11:25:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    food.cpp \
    gamecontroller.cpp \
    snake.cpp \
    wall.cpp

HEADERS  += mainwindow.h \
    food.h \
    constants.h \
    gamecontroller.h \
    snake.h \
    wall.h

RESOURCES += \
    images.qrc

