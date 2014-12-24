#ifndef KEYPRESS_H
#define KEYPRESS_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QVBoxLayout>



class KeyPress : public QWidget
{
    Q_OBJECT
public:
    KeyPress(QWidget *parent = 0);


private:
    QLabel *up;
    QLabel *down;
    QLabel *left;
    QLabel *right;
    QLabel *fire;
    QLabel *bomb;

    QVBoxLayout *mainLayout;
};

#endif // KEYPRESS_H
