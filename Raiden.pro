#-------------------------------------------------
#
# Project created by QtCreator 2014-12-09T13:35:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Raiden
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GameEngine/bullet.cpp \
    GameEngine/enemy.cpp \
    GameEngine/fighter.cpp \
    GameEngine/flyingobject.cpp \
    GameEngine/game.cpp \
    GameEngine/item.cpp \
    GameEngine/missile.cpp \
    GraphicEngine/graphic.cpp \
    GraphicEngine/graphicengine.cpp \
    UI/control.cpp \
    General/data.cpp \
    GameEngine/bomb.cpp \
    General/hitpoint.cpp \
    GameEngine/player.cpp \
    UI/difficultyui.cpp \
    UI/graphui.cpp \
    UI/keypress.cpp \
    UI/main.cpp \
    UI/mainwindow.cpp \
    UI/operationui.cpp \
    UI/screenui.cpp \
    UI/soundui.cpp \
    UI/value.cpp

HEADERS  += mainwindow.h \
    stdafx.h \
    GameEngine/bomb.h \
    GameDesign/design.h \
    GameEngine/bullet.h \
    GameEngine/enemy.h \
    GameEngine/fighter.h \
    GameEngine/flyingobject.h \
    GameEngine/game.h \
    GameEngine/item.h \
    GameEngine/missile.h \
    General/circle.h \
    General/point.h \
    GraphicEngine/graphic.h \
    GraphicEngine/graphicengine.h \
    UI/control.h \
    General/data.h \
    res.h \
    General/hitpoint.h \
    GameEngine/player.h \
    GameDesign/enemytype.h \
    UI/difficultyUI.h \
    UI/graphUI.h \
    UI/keypress.h \
    UI/mainwindow.h \
    UI/operationUI.h \
    UI/screenUI.h \
    UI/soundUI.h \
    UI/value.h

FORMS    += mainwindow.ui
