#include <QtWidgets>
#include "mainwindow.h"
#include "screenUI.h"
#include "soundUI.h"
#include "operationUI.h"
#include "difficultyUI.h"
#include "graphUI.h"
#include "keypress.h"
#include "value.h"


MainWindow::MainWindow()
{
    textEdit = new QPlainTextEdit;
    setCentralWidget(textEdit);
    setGeometry(500,500,800,600);
    createMenus();
}


void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Game(G)"));
    QAction *setMode1 = new QAction(tr("&1 Player Mode"), this);
    fileMenu->addAction(setMode1);
    QAction *setMode2 = new QAction(tr("&2 Player Mode"), this);
    fileMenu->addAction(setMode2);
    QAction *setLevel1 = new QAction(tr("& Level 1"), this);
    fileMenu->addAction(setLevel1);
    QAction *setLevel2 = new QAction(tr("& Level 2"), this);
    fileMenu->addAction(setLevel2);
    QAction *setLevel3 = new QAction(tr("& Level 3"), this);
    fileMenu->addAction(setLevel3);


    editMenu = menuBar()->addMenu(tr("&Option(O)"));
    QAction *Screen = new QAction(tr("&Screen"), this);
    editMenu->addAction(Screen);
    connect(Screen,SIGNAL(triggered()),this,SLOT(Screen()));

    QAction *Sound = new QAction(tr("&Sound"), this);
    editMenu->addAction(Sound);
    connect(Sound,SIGNAL(triggered()),this,SLOT(Sound()));
    QAction *Operation = new QAction(tr("&Operation"), this);
    editMenu->addAction(Operation);
    connect(Operation,SIGNAL(triggered()),this,SLOT(Operation()));
    QAction *Difficulty = new QAction(tr("&Difficulty"), this);
    connect(Difficulty,SIGNAL(triggered()),this,SLOT(Difficulty()));
    editMenu->addAction(Difficulty);
    QAction *Graph = new QAction(tr("&Graph"), this);
    editMenu->addAction(Graph);
    connect(Graph,SIGNAL(triggered()),this,SLOT(Graph()));
    helpMenu = menuBar()->addMenu(tr("&Help(H)"));
    QAction *Introduction = new QAction(tr("&Introduction"), this);
    helpMenu->addAction(Introduction);
    connect(Introduction,SIGNAL(triggered()),this,SLOT(Introduction()));
    QAction *Information = new QAction(tr("&Information"), this);
    helpMenu->addAction(Information);
    QAction *AboutUs = new QAction(tr("&About Us"), this);
    helpMenu->addAction(AboutUs);
    connect(AboutUs,SIGNAL(triggered()),this,SLOT(about()));

       controlMenu = menuBar()->addMenu(tr("&Control(C)"));
        QAction *Control =new QAction(tr("&KeyPressShow"),this);
        QAction *ValueShow =new QAction(tr("&ValueShow"),this);
        controlMenu->addAction(Control);
        controlMenu->addAction(ValueShow);
        connect(Control,SIGNAL(triggered()),this,SLOT(KeyPressShow()));

}


void MainWindow::about()
{
   QMessageBox::about(this, tr("About Us"),
            tr("This Part of Game Is Written By KiwiDc. ^_^\n\n"
               "GropMember:\nLuYuhe\nYangJiaqi\nLuoyou\nLiuChengxian\n"));
}

void MainWindow::Introduction()
{
    QMessageBox::about(this, tr("Introduction Of Game"),
             tr("  When Earthrealm was young, Raiden was its protector "
                "He fought the rogue Elder God Shinnok, who wished to"
                "overthrow his fellow gods, in a war that threatened to "
                "destroy Earthrealm itself. One of the casualties of the"
                "war was the Saurian civilization (of which Reptile is a"
                "descendant), forcing the remaining survivors to emigrate"
                "to another world, which they named Zaterra. With the aid"
                "of the Elder Gods, Raiden managed to defeat Shinnok, then"
                "banished him to the Netherealm and secured Shinnok's amulet"
                ));
}

void MainWindow::Screen()
{
   screenUI Dialog;
   Dialog.exec();
}

void MainWindow::Sound()
{
    soundUI Dialog;
    Dialog.exec();
}

void MainWindow::Difficulty()
{
    difficultyUI Dialog;
    Dialog.exec();
}

void MainWindow::Operation()
{
    operationUI Dialog;
    Dialog.exec();
}

void MainWindow::Graph()
{
    graphUI Dialog;
    Dialog.exec();
}

void MainWindow::KeyPressShow()
{
    KeyPress *keyPress = new KeyPress();
    keyPress->show();
}








