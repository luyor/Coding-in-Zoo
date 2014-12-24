#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdafx.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cout<<"main window start"<<endl;
    ui->setupUi(this);
    my_thread=new MyThread(Game::SINGLE,4,NULL,NULL);
    my_thread->start();
}

MainWindow::~MainWindow()
{

    delete ui;
    my_thread->my_game->EndGame();
    my_thread->quit();
}
