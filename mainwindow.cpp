#include <QtWidgets>
#include "mainwindow.h"
#include "UI/keypress.h"
#include "UI/value.h"
#include "UI/difficulty.h"
#include "UI/ui_difficulty.h"
#include "UI/screen.h"
#include "UI/ui_screen.h"
#include "UI/sound.h"
#include "UI/ui_sound.h"
#include "UI/operation.h"
#include "UI/ui_operation.h"
#include "UI/valueshow.h"
#include "UI/ui_valueshow.h"
#include "res.h"

MainWindow::MainWindow()
{
    installEventFilter(this);
    centralwidget= new PaintWidget();
    setGeometry(100,100,500,520);
    this->setCentralWidget(centralwidget);
    createMenus();
    this->setFixedSize( this->width (),this->height ());
    my_thread=new MyThread();
    my_thread->start();

}

MainWindow::~MainWindow()
{
    game.EndGame();
    my_thread->quit();
}


void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Game(G)")); 
    QAction *setMode1 = new QAction(tr("&1 Player Mode"), this);
    fileMenu->addAction(setMode1);
    connect(setMode1,SIGNAL(triggered()),this,SLOT(Player1Mode()));
    QAction *setMode2 = new QAction(tr("&2 Player Mode"), this);
    fileMenu->addAction(setMode2);
    connect(setMode2,SIGNAL(triggered()),this,SLOT(Player2Mode()));

   /*
    QAction *setLevel1 = new QAction(tr("& Level 1"), this);
    fileMenu->addAction(setLevel1);
    QAction *setLevel2 = new QAction(tr("& Level 2"), this);
    fileMenu->addAction(setLevel2);
    QAction *setLevel3 = new QAction(tr("& Level 3"), this);
    fileMenu->addAction(setLevel3);
   */


    editMenu = menuBar()->addMenu(tr("&Option(O)"));
    /*
    QAction *Screen = new QAction(tr("&Screen"), this);
    editMenu->addAction(Screen);
    connect(Screen,SIGNAL(triggered()),this,SLOT(ScreenSetting()));
    */

    QAction *Sound = new QAction(tr("&Sound"), this);
    editMenu->addAction(Sound);
    connect(Sound,SIGNAL(triggered()),this,SLOT(SoundSetting()));
    QAction *Operation = new QAction(tr("&Operation"), this);
    editMenu->addAction(Operation);
    connect(Operation,SIGNAL(triggered()),this,SLOT(OperationSetting()));
    QAction *Difficulty = new QAction(tr("&Difficulty"), this);
    connect(Difficulty,SIGNAL(triggered()),this,SLOT(DifficultySetting()));
    editMenu->addAction(Difficulty);
    helpMenu = menuBar()->addMenu(tr("&Help(H)"));
    QAction *Introduction = new QAction(tr("&Introduction"), this);
    helpMenu->addAction(Introduction);
    connect(Introduction,SIGNAL(triggered()),this,SLOT(Introduction()));

    QAction *AboutUs = new QAction(tr("&About Us"), this);
    helpMenu->addAction(AboutUs);
    connect(AboutUs,SIGNAL(triggered()),this,SLOT(about()));

      /*  controlMenu = menuBar()->addMenu(tr("&Control(C)"));
        QAction *Control =new QAction(tr("&KeyPressShow"),this);
        QAction *ValueShow =new QAction(tr("&ValueShow"),this);
        controlMenu->addAction(Control);
        controlMenu->addAction(ValueShow);
        connect(Control,SIGNAL(triggered()),this,SLOT(KeyPressShow()));
        connect(ValueShow,SIGNAL(triggered()),this,SLOT(ValueShowWindow()));
     */
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if( watched == this )
    {
        //窗口停用，变为不活动的窗口
        if(QEvent::WindowDeactivate == event->type())
        {
            //
            //DEBUGP( "eventFilter" ) ;
            if (!game.IsPaused())
                control.PauseClicked = 1;  //或者关闭窗口,加入自己的操作.
            return true ;
        }
        else
        {
            return false ;
        }
    }
    return false ;
}


void MainWindow::about()
{
   QMessageBox::about(this, tr("About Us"),
            tr("This Game Is Written By Our Group Members. ^_^\n\n"
               "Group Member:\nLuYuhe\nYangJiaqi\nLuoyou\nLiuChengxian\n"));
}

void MainWindow::Introduction()
{
    QMessageBox::about(this, tr("Introduction Of Game"),
             tr("Don't ask who is Raiden! That 's a word I"
                " and the game 's characters use intentionally!"
                " What we only know is that he is SLAUGHTER"
                " who only want to kill more!"
                ));
}


void MainWindow::ScreenSetting()
{
   screen Dialog;
   Dialog.exec();
}

void MainWindow::SoundSetting()
{
    Sound MySound;
    connect(MySound.ui->pushButton,SIGNAL(clicked()),&(this->centralwidget->se),SLOT(ChangeVolume()));
    MySound.exec();
}

void MainWindow::DifficultySetting()
{
    Difficulty Dialog;

    Dialog.exec();
}

void MainWindow::OperationSetting()
{
    Operation Dialog;
    Dialog.exec();
}


void MainWindow::KeyPressShow()
{
    KeyPress *keyPress = new KeyPress();
    keyPress->show();
}

void MainWindow::ValueShowWindow()
{
    valueshow Dialog;
    Dialog.exec();
}

bool flag,flag2,flag3,flag4,flag5,flag6,flag7;
bool flag21,flag22,flag23,flag24,flag25,flag26;

Qt::Key upkey;
Qt::Key downkey;
Qt::Key leftkey;
Qt::Key rightkey;
Qt::Key firekey;
Qt::Key bombkey;

Qt::Key upkey2 = Qt::Key_Up;
Qt::Key downkey2 = Qt::Key_Down;
Qt::Key leftkey2 = Qt::Key_Left;
Qt::Key rightkey2 = Qt::Key_Right;
Qt::Key firekey2 = Qt::Key_BracketLeft;
Qt::Key bombkey2 = Qt::Key_BracketRight;



Qt::Key setting(Qt::Key key,char a);



void MainWindow::keyPressEvent(QKeyEvent *event)
{
    upkey =    setting(upkey,gamepara.up);
    downkey =  setting(downkey,gamepara.down);
    leftkey =  setting(leftkey,gamepara.left);
    rightkey = setting(rightkey,gamepara.right);
    firekey =  setting(firekey,gamepara.fire);
    bombkey =  setting(bombkey,gamepara.bomb);

    if((event->key() == upkey)&&!(event->isAutoRepeat()))
    {
        flag = 0;

        if( !flag )
        {
        control.UpPressed = 1;
        }
        flag = 1;
    }

    if((event->key() == downkey)&&!(event->isAutoRepeat()))
    {
        flag2 = 0;

        if( !flag2 )
        {
        control.DownPressed = 1;
        }
        flag2 = 1;
    }

    if((event->key() == leftkey)&&!(event->isAutoRepeat()))
    {
        flag3 = 0;

        if( !flag3 )
        {
        control.LeftPressed = 1;
        }
        flag3 = 1;
    }

    if((event->key() == rightkey)&&!(event->isAutoRepeat()))
    {
        flag4 = 0;

        if( !flag4 )
        {
        control.RightPressed = 1;
        }
        flag4 = 1;
    }

    if((event->key() == firekey)&&!(event->isAutoRepeat()))
    {
        flag5 = 0;

        if( !flag5 )
        {
        control.FirePressed = 1;
        }
        flag5 = 1;
    }

    if((event->key() == bombkey)&&!(event->isAutoRepeat()))
    {
        flag6 = 0;

        if( !flag6 )
        {
        control.BombClicked = 1;
        }
        flag6 = 1;
    }

    if((event->key() == Qt::Key_B)&&!(event->isAutoRepeat()))
    {
        flag7 = 0;

        if( !flag7 )
        {
        control.PauseClicked = 1;
        }
        flag7 = 1;
    }

    if((event->key() == Qt::Key_Backslash)&&!(event->isAutoRepeat()))
    {
        flag7 = 0;

        if( !flag7 )
        {
        control2.PauseClicked = 1;
        }
        flag7 = 1;
    }




    if((event->key() == upkey2)&&!(event->isAutoRepeat()))
    {
        flag21 = 0;

        if( !flag21 )
        {
        control2.UpPressed = 1;
        }
        flag21 = 1;
    }

    if((event->key() == downkey2)&&!(event->isAutoRepeat()))
    {
        flag22 = 0;

        if( !flag22 )
        {
        control2.DownPressed = 1;
        }
        flag22 = 1;
    }

    if((event->key() == leftkey2)&&!(event->isAutoRepeat()))
    {
        flag23 = 0;

        if( !flag23 )
        {
        control2.LeftPressed = 1;
        }
        flag23 = 1;
    }

    if((event->key() == rightkey2)&&!(event->isAutoRepeat()))
    {
        flag24 = 0;

        if( !flag24 )
        {
        control2.RightPressed = 1;
        }
        flag24 = 1;
    }

    if((event->key() == firekey2)&&!(event->isAutoRepeat()))
    {
        flag25 = 0;

        if( !flag25 )
        {
        control2.FirePressed = 1;
        }
        flag25 = 1;
    }

    if((event->key() == bombkey2)&&!(event->isAutoRepeat()))
    {
        flag26 = 0;

        if( !flag26 )
        {
        control2.BombClicked = 1;
        }
        flag26 = 1;
    }


}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{

    if((event->key() == upkey)&&!(event->isAutoRepeat())&&(control.UpPressed = 1))
    {

        if( flag )
        {
        control.UpPressed = 0;
        }
        flag = 0;

    }

    if((event->key() == downkey)&&!(event->isAutoRepeat())&&(control.DownPressed = 1))
    {

        if( flag2 )
        {
        control.DownPressed = 0;
        }
        flag2 = 0;
    }

    if((event->key() == leftkey)&&!(event->isAutoRepeat())&&(control.LeftPressed = 1))
    {

        if( flag3 )
        {
        control.LeftPressed = 0;
        }
        flag3 = 0;
    }

    if((event->key() == rightkey)&&!(event->isAutoRepeat())&&(control.RightPressed = 1))
    {

        if( flag4 )
        {
        control.RightPressed = 0;
        }
        flag4 = 0;
    }

    if((event->key() == firekey)&&!(event->isAutoRepeat())&&(control.FirePressed = 1))
    {

        if( flag5 )
        {
        control.FirePressed = 0;
        }
        flag5 = 0;
    }




    if((event->key() == upkey2)&&!(event->isAutoRepeat())&&(control2.UpPressed = 1))
    {

        if( flag21 )
        {
        control2.UpPressed = 0;
        }
        flag21 = 0;

    }

    if((event->key() == downkey2)&&!(event->isAutoRepeat())&&(control2.DownPressed = 1))
    {

        if( flag22 )
        {
        control2.DownPressed = 0;
        }
        flag22 = 0;
    }

    if((event->key() == leftkey2)&&!(event->isAutoRepeat())&&(control2.LeftPressed = 1))
    {

        if( flag23 )
        {
        control2.LeftPressed = 0;
        }
        flag23 = 0;
    }

    if((event->key() == rightkey2)&&!(event->isAutoRepeat())&&(control2.RightPressed = 1))
    {

        if( flag24 )
        {
        control2.RightPressed = 0;
        }
        flag24 = 0;
    }

    if((event->key() == firekey2)&&!(event->isAutoRepeat())&&(control2.FirePressed = 1))
    {

        if( flag25 )
        {
        control2.FirePressed = 0;
        }
        flag25 = 0;
    }


}

Qt::Key setting(Qt::Key key,char a)
{
         if(a == 'a'||a == 'A')
        key = Qt::Key_A;
    else if(a == 'b'||a == 'B')
        key = Qt::Key_B;
    else if(a == 'c'||a == 'C')
        key = Qt::Key_C;
    else if(a == 'd'||a == 'D')
        key = Qt::Key_D;
    else if(a == 'e'||a == 'E')
        key = Qt::Key_E;
    else if(a == 'f'||a == 'F')
        key = Qt::Key_F;
    else if(a == 'g'||a == 'G')
        key = Qt::Key_G;
    else if(a == 'h'||a == 'H')
        key = Qt::Key_H;
    else if(a == 'i'||a == 'I')
        key = Qt::Key_I;
    else if(a == 'j'||a == 'J')
        key = Qt::Key_J;
    else if(a == 'k'||a == 'K')
        key = Qt::Key_K;
    else if(a == 'l'||a == 'L')
        key = Qt::Key_L;
    else if(a == 'm'||a == 'M')
        key = Qt::Key_M;
    else if(a == 'n'||a == 'N')
        key = Qt::Key_N;
    else if(a == 'o'||a == 'O')
        key = Qt::Key_O;
    else if(a == 'p'||a == 'P')
        key = Qt::Key_P;
    else if(a == 'q'||a == 'Q')
        key = Qt::Key_Q;
    else if(a == 'r'||a == 'R')
        key = Qt::Key_R;
    else if(a == 's'||a == 'S')
        key = Qt::Key_S;
    else if(a == 't'||a == 'T')
        key = Qt::Key_T;
    else if(a == 'u'||a == 'U')
        key = Qt::Key_U;
    else if(a == 'v'||a == 'V')
        key = Qt::Key_V;
    else if(a == 'w'||a == 'W')
        key = Qt::Key_W;
    else if(a == 'x'||a == 'X')
        key = Qt::Key_X;
    else if(a == 'y'||a == 'Y')
        key = Qt::Key_Y;
    else if(a == 'z'||a == 'Z')
        key = Qt::Key_Z;
    else if(a == 44)
        key = Qt::Key_Comma;
    else if(a == 46)
        key = Qt::Key_Period;
     return key;
}

void  MainWindow::Player1Mode()
{
    my_thread->Single();
}

void MainWindow::Player2Mode()
{
    my_thread->COOP();
}

