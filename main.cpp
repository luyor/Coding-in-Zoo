#include "mainwindow.h"
#include <QApplication>
#include "stdafx.h"
#include "GameEngine/game.h"
#include "UI/control.h"


#include "res.h"

GraphicEngine graphic_engine;
Data data;
Control control;
GamePara gamepara;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Raiden");
    w.show();



    return a.exec();
}
