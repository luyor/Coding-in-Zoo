#include "valueshow.h"
#include "ui_valueshow.h"
#include "res.h"
#include <iostream>

using namespace std;

valueshow::valueshow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::valueshow)
{
    ui->setupUi(this);


    if(gamepara.screenMode == 1)
        ui->lineEdit->setText("CurrentSetting");
    else if(gamepara.screenMode == 2)
        ui->lineEdit->setText("SmallScreenMode");
    else if(gamepara.screenMode == 3)
        ui->lineEdit->setText("BigScreenMode");
    else if(gamepara.screenMode == 4)
        ui->lineEdit->setText("FullScreenMode");

    int value = gamepara.backGroundSound;
    QString qstr = QString::number(value);
    ui->lineEdit_2->setText(qstr);


    value = gamepara.bombSound;
    qstr = QString::number(value);
    ui->lineEdit_3->setText(qstr);

    value = gamepara.KeybordOrJoypad;
    if(value == 0)
        ui->lineEdit_4->setText("Keyboard");
    else
        ui->lineEdit_4->setText("Joypad");

    value = int(gamepara.fire);
    qstr =QString::number(value);
    ui->lineEdit_5->setText(qstr);

    value = int(gamepara.bomb);
    qstr =QString::number(value);
    ui->lineEdit_6->setText(qstr);

    value = int(gamepara.start);
    qstr =QString::number(value);
    ui->lineEdit_8->setText(qstr);

    value = gamepara.LasterFire;
    qstr =QString::number(value);
    if(value == 0)
        ui->lineEdit_7->setText("NotLasterFire");
    else
        ui->lineEdit_7->setText("LasterFire");

    char ch = gamepara.up;
    qstr =QString(QLatin1Char(ch));
    ui->lineEdit_9->setText(qstr);

    ch = gamepara.down;
    qstr =QString(QLatin1Char(ch));
    ui->lineEdit_11->setText(qstr);


    ch = gamepara.left;
    qstr =QString(QLatin1Char(ch));
    ui->lineEdit_13->setText(qstr);

    ch = gamepara.right;
    qstr =QString(QLatin1Char(ch));
    ui->lineEdit_12->setText(qstr);

    if(gamepara.difficulty == 1)
        ui->lineEdit_10->setText("Easy");
    else if(gamepara.difficulty == 2)
        ui->lineEdit_10->setText("Ordinary");
    else if(gamepara.difficulty == 3)
        ui->lineEdit_10->setText("Difficult");
    else if(gamepara.difficulty == 4)
        ui->lineEdit_10->setText("Nightmare");

    if(gamepara.rebornTime == 1)
        ui->lineEdit_14->setText("3");
    else if(gamepara.rebornTime == 2)
        ui->lineEdit_14->setText("5");
    else if(gamepara.rebornTime == 3)
        ui->lineEdit_14->setText("7");
    else if(gamepara.rebornTime == 4)
        ui->lineEdit_14->setText("9");

    if(gamepara.initialBomb == 1)
        ui->lineEdit_15->setText("RedOne");
    else if(gamepara.initialBomb == 2)
        ui->lineEdit_15->setText("YellowOne");






}

valueshow::~valueshow()
{
    delete ui;
}
