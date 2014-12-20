#ifndef VALUE_H
#define VALUE_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QVBoxLayout>

class Value : public QWidget
{
    Q_OBJECT
public:
    Value(QWidget *parent = 0);


protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

private:
    QLabel *up;
    QLabel *down;
    QLabel *left;
    QLabel *right;
    QLabel *fire;
    QLabel *bomb;

    QVBoxLayout *mainLayout;
};

#endif // VALUE_H
