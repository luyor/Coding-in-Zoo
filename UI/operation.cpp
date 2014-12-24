#include "operation.h"
#include "ui_operation.h"
#include "iostream"
#include "res.h"



using namespace std;

Operation::Operation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Operation)
{
    ui->setupUi(this);

    QString str = QString(gamepara.fire);

    ui->lineEdit_8->setText(str);

    str = QString(gamepara.bomb);
    ui->lineEdit_9->setText(str);

    ui->checkBox_3->setChecked(1);

    str = QString(gamepara.up);
    ui->lineEdit_4->setText(str);

    str = QString(gamepara.down);
    ui->lineEdit_11->setText(str);

    str = QString(gamepara.left);
    ui->lineEdit_13->setText(str);

    str = QString(gamepara.right);
    ui->lineEdit_12->setText(str);
}

Operation::~Operation()
{
    delete ui;
}

void Operation::on_pushButton_8_clicked()
{
    QString Qstr =ui->comboBox->currentText();
    string str = Qstr.toLatin1().data();
    cout<<"Operator "<<str<<endl;


    if(str.compare("Keyboard") == 0)
        gamepara.KeybordOrJoypad = 0;
    else
        gamepara.KeybordOrJoypad = 1;

    int a = ui->checkBox_3->isChecked();
    gamepara.LasterFire = a;

    Qstr=ui->lineEdit_8->text();
    str = Qstr.toLatin1().data();
    cout<<"Fire "<<str<<endl;
    char c = str.at(0);
    gamepara.fire = int(c);

    Qstr=ui->lineEdit_9->text();
    str = Qstr.toLatin1().data();
    cout<<"Bomb "<<str<<endl;
    c = str.at(0);
    gamepara.bomb = int(c);

    Qstr=ui->lineEdit_10->text();
    str = Qstr.toLatin1().data();
    cout<<"Start "<<str<<endl;
    if(str.compare("Enter")==0)
    gamepara.start = 32;
    else
    {
        c = str.at(0);
        gamepara.start = int (c);
    }

    Qstr=ui->lineEdit_4->text();
    str = Qstr.toLatin1().data();
    cout<<"Up "<<str<<endl;
    c = str.at(0);
    gamepara.up = int(c);

    Qstr=ui->lineEdit_11->text();
    str = Qstr.toLatin1().data();
    cout<<"Down "<<str<<endl;
    c = str.at(0);
    gamepara.down = int(c);

    Qstr=ui->lineEdit_13->text();
    str = Qstr.toLatin1().data();
    cout<<"Left "<<str<<endl;
    c = str.at(0);
    gamepara.left = int(c);

    Qstr=ui->lineEdit_12->text();
    str = Qstr.toLatin1().data();
    cout<<"Right "<<str<<endl;
    c = str.at(0);
    gamepara.right = int(c);

    this->close();
}


void Operation::on_pushButton_9_clicked()
{
    this->close();
}


void Operation::on_pushButton_3_clicked()
{
    QString str = QString(QLatin1String(&gamepara.fire));
    ui->lineEdit_8->setText(",");

    str = QString(QLatin1String(&gamepara.bomb));
    ui->lineEdit_9->setText(".");


    ui->checkBox_3->setChecked(1);

    str = QString(QLatin1String(&gamepara.up));
    ui->lineEdit_4->setText("W");

    str = QString(QLatin1String(&gamepara.down));
    ui->lineEdit_11->setText("S");

    str = QString(QLatin1String(&gamepara.left));
    ui->lineEdit_13->setText("A");

    str = QString(QLatin1String(&gamepara.right));
    ui->lineEdit_12->setText("D");
}
