#-------------------------------------------------
#
# Project created by QtCreator 2014-12-24T10:06:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = he1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GameEngine/bomb.cpp \
    GameEngine/bullet.cpp \
    GameEngine/enemy.cpp \
    GameEngine/fighter.cpp \
    GameEngine/flyingobject.cpp \
    GameEngine/game.cpp \
    GameEngine/item.cpp \
    GameEngine/missile.cpp \
    GameEngine/player.cpp \
    General/data.cpp \
    General/hitpoint.cpp \
    GraphicEngine/fighter1graphic.cpp \
    GraphicEngine/graphic.cpp \
    GraphicEngine/graphicengine.cpp \
    GraphicEngine/paintwidget.cpp \
    GraphicEngine/picnode.cpp \
    UI/control.cpp \
    GameEngine/mythread.cpp

HEADERS  += mainwindow.h \
    GameEngine/bomb.h \
    GameEngine/bullet.h \
    GameEngine/enemy.h \
    GameEngine/fighter.h \
    GameEngine/flyingobject.h \
    GameEngine/game.h \
    GameEngine/item.h \
    GameEngine/missile.h \
    GameEngine/player.h \
    General/circle.h \
    General/data.h \
    General/hitpoint.h \
    General/point.h \
    GraphicEngine/fighter1graphic.h \
    GraphicEngine/graphic.h \
    GraphicEngine/graphicengine.h \
    GraphicEngine/paintwidget.h \
    GraphicEngine/picnode.h \
    res.h \
    stdafx.h \
    UI/control.h \
    GameEngine/mythread.h

FORMS    += mainwindow.ui
