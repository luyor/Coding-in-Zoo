#ifndef VALUESHOW_H
#define VALUESHOW_H

#include <QDialog>

namespace Ui {
class valueshow;
}

class valueshow : public QDialog
{
    Q_OBJECT

public:
    explicit valueshow(QWidget *parent = 0);
    ~valueshow();

private:
    Ui::valueshow *ui;
};

#endif // VALUESHOW_H
