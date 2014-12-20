#include "keypress.h"
#include <QApplication>
#include <QKeyEvent>
#include "control.h"

KeyPress::KeyPress(QWidget *parent) :
    QWidget(parent)
{
     up      = new QLabel("Up");
     down    = new QLabel("Down");
     left    = new QLabel("Left");
     right   = new QLabel("Right");
     fire    = new QLabel("Fire");
     bomb    = new QLabel("Bomb");

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

void KeyPress::keyPressEvent(QKeyEvent *event)
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

void KeyPress::keyReleaseEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_W)
    {
        up->setText("You released Up");
    }

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

