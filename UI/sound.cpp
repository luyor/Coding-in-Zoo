#include "sound.h"
#include "ui_sound.h"
#include <iostream>
#include "res.h"



using namespace std;

Sound::Sound(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sound)
{
    ui->setupUi(this);
}

Sound::~Sound()
{
    delete ui;
}

void Sound::on_pushButton_clicked()
{
    int a = ui->verticalSlider->value();
    int b = ui->verticalSlider_2->value();
    int c = ui->checkBox->isChecked();
    int d = ui->checkBox_2->isChecked();

    cout<<"BackgroundSound: "<<a<<endl;
    gamepara.backGroundSound = a;

    cout<<"BombSound: "<<b<<endl;
    gamepara.bombSound = b;

    cout<<"BGS exists?: "<< c <<endl;
    if(c == 0)
        gamepara.backGroundSound = 0;

    cout<<"BS  exists?: "<< d <<endl;
    if(d == 0)
        gamepara.bombSound = 0;

    this->close();
}

void Sound::on_pushButton_2_clicked()
{
    this->close();
}

void Sound::on_verticalSlider_sliderMoved(int position)
{
     gamepara.backGroundSound = position;
}

void Sound::on_verticalSlider_2_sliderMoved(int position)
{
     gamepara.bombSound = position;
}
