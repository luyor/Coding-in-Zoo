#include "screen.h"
#include "ui_screen.h"
#include "iostream"
#include "res.h"


using namespace std;

screen::screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::screen)
{
    ui->setupUi(this);

}

screen::~screen()
{
    delete ui;
}

void screen::on_pushButton_2_clicked()
{
    this->close();
}

void screen::on_pushButton_clicked()
{
    ui->buttonGroup->setId(ui->radioButton,1);
    ui->buttonGroup->setId(ui->radioButton_2,2);
    ui->buttonGroup->setId(ui->radioButton_3,3);
    ui->buttonGroup->setId(ui->radioButton_4,4);

    int a = ui->buttonGroup->checkedId();

    cout<<a<<endl;
    gamepara.screenMode = a;

    cout<<"The value of screenMode: "<<gamepara.screenMode<<endl;

    this->close();

}
