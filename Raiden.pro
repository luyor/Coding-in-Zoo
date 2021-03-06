#-------------------------------------------------
#
# Project created by QtCreator 2014-12-24T10:06:13
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = raiden
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
    UI/screen.cpp \
    UI/screenui.cpp \
    UI/sound.cpp \
    UI/soundui.cpp \
    UI/value.cpp \
    UI/valueshow.cpp \
    GraphicEngine/bulletyellowgraphic.cpp \
    GraphicEngine/bombatomicgraphic.cpp \
    GraphicEngine/missilegraphic.cpp \
    GraphicEngine/bombdispersegraphic.cpp \
    GameDesign/enemy1.cpp \
    GraphicEngine/enemy1graphic.cpp \
    GameDesign/design.cpp \
    GraphicEngine/enemybullet1graphic.cpp \
    GraphicEngine/itembulletlvupgraphic.cpp \
    GraphicEngine/itemscore1000graphic.cpp \
    GraphicEngine/soundengine.cpp \
    GraphicEngine/bulletbluegraphic.cpp \
    GraphicEngine/bulletpurplegraphic.cpp \
    UI/res.cpp \
    GameDesign/enemy2.cpp \
    GraphicEngine/enemy2graphic.cpp \
    GraphicEngine/fighter2graphic.cpp \
    GraphicEngine/enemy3graphic.cpp \
    GraphicEngine/enemy4graphic.cpp \
    GraphicEngine/itemmissile1graphic.cpp \
    GraphicEngine/itembombatomicgraphic.cpp \
    GameDesign/enemy3.cpp \
    GameDesign/enemy4.cpp \
    GameDesign/boss1.cpp \
    GraphicEngine/boss1graphic.cpp \
    GraphicEngine/boss2graphic.cpp \
    GraphicEngine/boss3graphic.cpp \
    GraphicEngine/enemybullet2graphic.cpp \
    GraphicEngine/enemybullet3graphic.cpp \
    GameDesign/boss3.cpp \
    GameDesign/boss2.cpp

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
    UI/valueshow.h \
    GraphicEngine/bombatomicgraphic.h \
    GraphicEngine/missilegraphic.h \
    GraphicEngine/bombdispersegraphic.h \
    GameDesign/enemy1.h \
    GraphicEngine/enemy1graphic.h \
    GameDesign/design.h \
    GraphicEngine/enemybullet1graphic.h \
    GraphicEngine/itembulletlvupgraphic.h \
    GraphicEngine/itemscore1000graphic.h \
    GraphicEngine/soundengine.h \
    GraphicEngine/bulletbluegraphic.h \
    GraphicEngine/bulletpurplegraphic.h \
    UI/res.h \
    GameDesign/enemy2.h \
    GraphicEngine/enemy2graphic.h \
    GraphicEngine/fighter2graphic.h \
    GraphicEngine/enemy3graphic.h \
    GraphicEngine/enemy4graphic.h \
    GraphicEngine/itemmissile1graphic.h \
    GraphicEngine/itembombatomicgraphic.h \
    GameDesign/enemy3.h \
    GameDesign/enemy4.h \
    GameDesign/boss1.h \
    GraphicEngine/boss1graphic.h \
    GraphicEngine/boss2graphic.h \
    GraphicEngine/boss3graphic.h \
    GraphicEngine/enemybullet2graphic.h \
    GraphicEngine/enemybullet3graphic.h \
    UI/soundui.h \
    GameDesign/boss3.h \
    GameDesign/boss2.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc

OTHER_FILES +=
