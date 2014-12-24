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
    GameEngine/mythread.cpp \
    UI/difficulty.cpp \
    UI/difficultyui.cpp \
    UI/gamepara.cpp \
    UI/graphui.cpp \
    UI/keypress.cpp \
    UI/operation.cpp \
    UI/operationui.cpp \
    UI/res.cpp \
    UI/screen.cpp \
    UI/screenui.cpp \
    UI/sound.cpp \
    UI/soundui.cpp \
    UI/value.cpp \
    UI/valueshow.cpp \
    GraphicEngine/bulletyellowgraphic.cpp

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
    GameEngine/mythread.h \
    GraphicEngine/bulletyellowgraphic.h \
    UI/difficulty.h \
    UI/difficultyUI.h \
    UI/gamepara.h \
    UI/graphUI.h \
    UI/keypress.h \
    UI/operation.h \
    UI/operationUI.h \
    UI/screen.h \
    UI/screenUI.h \
    UI/sound.h \
    UI/soundUI.h \
    UI/ui_difficulty.h \
    UI/ui_operation.h \
    UI/ui_screen.h \
    UI/ui_sound.h \
    UI/ui_valueshow.h \
    UI/value.h \
    UI/valueshow.h

FORMS    += mainwindow.ui
