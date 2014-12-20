#include "screenui.h"

screenUI::screenUI()
{
    setupUi(this);
    connect(pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
    connect(pushButton, SIGNAL(clicked()), this, SLOT(close()));
}
