#ifndef SOUND_H
#define SOUND_H

#include <QDialog>

namespace Ui {
class Sound;
}

class Sound : public QDialog
{
    Q_OBJECT

public:
    explicit Sound(QWidget *parent = 0);
    ~Sound();

private slots:
    void on_pushButton_clicked();
    void on_verticalSlider_sliderMoved(int position);
    void on_verticalSlider_2_sliderMoved(int position);
    void on_pushButton_2_clicked();

public:
    Ui::Sound *ui;
};

#endif // SOUND_H
