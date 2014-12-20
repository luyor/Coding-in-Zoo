#include "graphUI.h"

graphUI::graphUI()
{
    setupUi(this);
    connect(pushButton_3, SIGNAL(clicked()), this, SLOT(close()));
    connect(pushButton_4, SIGNAL(clicked()), this, SLOT(close()));
}


