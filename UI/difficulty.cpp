#include "difficulty.h"
#include "ui_difficulty.h"
#include <iostream>
#include "res.h"

using namespace std;

Difficulty::Difficulty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Difficulty)
{
    ui->setupUi(this);
}

Difficulty::~Difficulty()
{
    delete ui;
}

void Difficulty::on_pushButton_3_clicked()
{
    ui->buttonGroup->setId(ui->radioButton_5,1);
    ui->buttonGroup->setId(ui->radioButton_6,2);
    ui->buttonGroup->setId(ui->radioButton_7,3);
    ui->buttonGroup->setId(ui->radioButton_8,4);

    ui->buttonGroup_2->setId(ui->radioButton_9, 1);
    ui->buttonGroup_2->setId(ui->radioButton_10,2);
    ui->buttonGroup_2->setId(ui->radioButton_11,3);
    ui->buttonGroup_2->setId(ui->radioButton_12,4);

    ui->buttonGroup_3->setId(ui->radioButton_13,1);
    ui->buttonGroup_3->setId(ui->radioButton_14,2);

    int a = ui->buttonGroup->checkedId();
    int b = ui->buttonGroup_2->checkedId();
    int c = ui->buttonGroup_3->checkedId();

    gamepara.difficulty  = a;
    gamepara.rebornTime  = b;
    gamepara.initialBomb = c;


    this->close();
}

void Difficulty::on_pushButton_4_clicked()
{
    this->close();
}
