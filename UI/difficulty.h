#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <QDialog>

namespace Ui {
class Difficulty;
}

class Difficulty : public QDialog
{
    Q_OBJECT

public:
    explicit Difficulty(QWidget *parent = 0);
    ~Difficulty();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Difficulty *ui;
};

#endif // DIFFICULTY_H
