#include "operationui.h"

operationUI::operationUI()
{
    setupUi(this);
    connect(pushButton_4, SIGNAL(clicked()), this, SLOT(close()));
    connect(pushButton_5, SIGNAL(clicked()), this, SLOT(close()));
}
