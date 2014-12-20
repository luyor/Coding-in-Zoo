#include "difficultyui.h"


difficultyUI::difficultyUI()
{
    setupUi(this);
    connect(pushButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
}


