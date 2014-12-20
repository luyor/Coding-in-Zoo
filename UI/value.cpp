#include "value.h"
#include <QString>
#include <QApplication>
#include <QKeyEvent>
#include "control.h"

Value::Value(QWidget *parent) :
    QWidget(parent)
{


    QString str;
    char*  upState;
    char*  downState;
    char*  leftState;
    char*  rightState;
    char*  fireState;
    char*  bombState;


    Control control;
    QByteArray ba;

    control.UpPressed    = 1;
    control.DownPressed  = 1;
    control.LeftPressed  = 1;
    control.RightPressed = 1;
    control.FirePressed  = 1;
    control.BombClicked  =1;


    if(control.UpPressed == 1)
     str = QString("%1").arg("The value of UpPressed is 1");
    else if(control.UpPressed == 0)
     str = QString("%1").arg("The value of UpPressed is 0");
    ba = str.toLatin1();
    upState=ba.data();
    up      = new QLabel(upState);



    if(control.DownPressed == 1)
     str = QString("%1").arg("The value of DownPressed is 1");
    else if(control.DownPressed == 0)
     str = QString("%1").arg("The value of DownPressed is 0");
    ba = str.toLatin1();
    downState=ba.data();
    down    = new QLabel(downState);


    if(control.LeftPressed == 1)
     str = QString("%1").arg("The value of LeftPressed is 1");
    else if(control.LeftPressed == 0)
     str = QString("%1").arg("The value of LeftPressed is 0");
    ba = str.toLatin1();
    leftState=ba.data();
    left    = new QLabel(leftState);


    if(control.RightPressed == 1)
     str = QString("%1").arg("The value of RightPressed is 1");
    else if(control.RightPressed == 0)
     str = QString("%1").arg("The value of RightPressed is 0");
    ba = str.toLatin1();
    rightState=ba.data();
    right   = new QLabel(rightState);



    if(control.FirePressed == 1)
     str = QString("%1").arg("The value of FirePressed is 1");
    else if(control.FirePressed == 0)
     str = QString("%1").arg("The value of FirePressed is 0");
    ba = str.toLatin1();
    fireState=ba.data();
    fire    = new QLabel(fireState);


    if(control.BombClicked == 1)
     str = QString("%1").arg("The value of BombClicked is 1");
    else if(control.BombClicked == 0)
     str = QString("%1").arg("The value of BombClicked is 0");
    ba = str.toLatin1();
    bombState=ba.data();
    bomb    = new QLabel(bombState);


    mainLayout = new QVBoxLayout;

    setGeometry(300,300,600,600);

    mainLayout->addWidget(up);
    mainLayout->addWidget(down);
    mainLayout->addWidget(left);
    mainLayout->addWidget(right);
    mainLayout->addWidget(fire);
    mainLayout->addWidget(bomb);

    setLayout(mainLayout);
}



void Value::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {

        up->setText("You pressed Up");
    }

    if(event->key() == Qt::Key_S)
    {
        down->setText("You pressed Down");
    }

    if(event->key() == Qt::Key_A)
    {
        left->setText("You pressed Left");
    }

    if(event->key() == Qt::Key_D)
    {
        right->setText("You pressed Right");
    }

    if(event->key() == Qt::Key_Comma)
    {
        fire->setText("You pressed Fire");
    }

    if(event->key() == Qt::Key_Period)
    {
        bomb->setText("You pressed Bomb");
    }
}

void Value::keyReleaseEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_W)
    {
        up->setText("You released Up");


    if(event->key() == Qt::Key_S)
    {
        down->setText("You realeased Down");
    }

    if(event->key() == Qt::Key_A)
    {
        left->setText("You released Left");
    }

    if(event->key() == Qt::Key_D)
    {
        right->setText("You released Right");
    }

    if(event->key() == Qt::Key_Comma)
    {
        fire->setText("You released Fire");
    }

    if(event->key() == Qt::Key_Period)
    {
        bomb->setText("You released Bomb");
    }
 }
}
