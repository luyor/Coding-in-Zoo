#include "soundui.h"


soundUI::soundUI()
{
    setupUi(this);
    connect(pushButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
}
