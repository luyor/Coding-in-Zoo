#ifndef OPERATION_H
#define OPERATION_H

#include <QDialog>

namespace Ui {
class Operation;
}

class Operation : public QDialog
{
    Q_OBJECT

public:
    explicit Operation(QWidget *parent = 0);
    ~Operation();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Operation *ui;
};

#endif // OPERATION_H
