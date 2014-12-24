#include "keypress.h"
#include <QApplication>
#include <QKeyEvent>
#include "control.h"
#include "res.h"
#include <iostream>

using namespace std;



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





