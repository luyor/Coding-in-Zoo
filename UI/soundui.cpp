#include "soundui.h"
#include "../GraphicEngine/paintwidget.h"


soundUI::soundUI()
{
    setupUi(this);
    connect(pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}
