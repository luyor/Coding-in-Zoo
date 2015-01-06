#include "paintwidget.h"
#include "../res.h"

PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent)
{
   se.PlaySoundBGM();

   graphic_engine.back_ground = new QPixmap(":/images/Images/background_image/background.png");
   graphic_engine.title = new QPixmap(":/images/Images/background_image/Title.png");
   graphic_engine.bomb_atomic = new QPixmap(":/images/images/background_image/BombAtomic.png");
   graphic_engine.bomb_disperse = new QPixmap(":/images/images/background_image/BombAtomic.png");
   graphic_engine.life1 = new QPixmap(":/images/images/item_image/Life1.png"); //aiur
   graphic_engine.life2 = new QPixmap(":/images/images/item_image/Life2.png"); //aiur
   graphic_engine.bk_title = new QPixmap(":/images/images/background_image/Title_bk.png");
   graphic_engine.door1 = new QPixmap(":/images/images/background_image/Door1.png");
   graphic_engine.door2 = new QPixmap(":/images/images/background_image/Door2.png");

   connect(&graphic_engine,SIGNAL(Update()),this,SLOT(PaintFrame()));
   connect(&graphic_engine,SIGNAL(PlaySoundBGM()),&se,SLOT(PlaySoundBGM()));
   connect(&graphic_engine,SIGNAL(PlaySoundBulletYellow()),&se,SLOT(PlaySoundBulletYellow()));
   connect(&graphic_engine,SIGNAL(PlaySoundBulletBlue()),&se,SLOT(PlaySoundBulletBlue()));
   connect(&graphic_engine,SIGNAL(PlaySoundBulletPurple()),&se,SLOT(PlaySoundBulletPurple()));
   connect(&graphic_engine,SIGNAL(PlaySoundEnemyHit()),&se,SLOT(PlaySoundEnemyHit()));
   connect(&graphic_engine,SIGNAL(PlaySoundEnemyDestroy()),&se,SLOT(PlaySoundEnemyDestroy()));
   connect(&graphic_engine,SIGNAL(PlaySoundBombFall()),&se,SLOT(PlaySoundBombFall()));
   connect(&graphic_engine,SIGNAL(PlaySoundBombAtomic()),&se,SLOT(PlaySoundBombAtomic()));
   connect(&graphic_engine,SIGNAL(PlaySoundBombDisperse()),&se,SLOT(PlaySoundBombDisperse()));
   connect(&graphic_engine,SIGNAL(PlaySoundFighterDestroy()),&se,SLOT(PlaySoundFighterDestroy()));
}

void PaintWidget::paintEvent(QPaintEvent* event)
{
    extern Data data;
    graphic_engine.END_PAINT = false;
    QPainter painter(this);
    QPixmap* tmp;
    if(game.WELCOME == true)
    {
        bool converse = false;
        double xx = graphic_engine.title_time * data.TITLE_SPEED;
        while(xx>1000)xx-=1000;
        if(xx>500)converse = true;
        if(!converse)
            painter.drawPixmap(0,0,*graphic_engine.bk_title,
                               (int)xx,0,500+(int)xx,500);
        else
            painter.drawPixmap(0,0,*graphic_engine.bk_title,
                               1000-(int)xx,0,1500-(int)xx,500);
        painter.drawPixmap(0,0,*graphic_engine.title);
    }
    else{
        //paint background
        if(graphic_engine.back_ground != NULL)
        {
            int bky1,bky2;

            bky1 = (int)(graphic_engine.back_ground->height()-this->height()-graphic_engine.bk);
            if(bky1 <= 0) bky1 = 0;

            bky2 = (int)(graphic_engine.back_ground->height()-graphic_engine.bk);
            if(bky2 <= this->height()) bky2 = graphic_engine.back_ground->height();

            painter.drawPixmap(0,0,*graphic_engine.back_ground,
                               0,bky1,
                              this->width(),bky2);
        }

        //paint pics_to_show
        vector<PicNode>::iterator iter = graphic_engine.pics_to_show.begin();
        for(;iter != graphic_engine.pics_to_show.end();iter++)
        {
            painter.drawPixmap((int)(iter->position.x-iter->pixmap.width()/2),
                               (int)(this->height() - iter->position.y - iter->pixmap.height()/2), iter->pixmap);
        }
        //paint foreground
        //player1
        QFont font("AR ESSENCE",15,QFont::Bold,false);
        font.setPixelSize(20);
        painter.setFont(font);
        painter.setPen(QColor(Qt::white));
        painter.drawText(10,20,"1 UP:");
        painter.setPen(QColor(Qt::yellow));
        if(game.player0->START == false)
        {
            painter.drawText(this->width()-155,40,"PRESS START");

        }
        else{
            painter.drawText(10,40,QString::number((int)game.player0->score,10));
            //life1
            int l1 = game.player0->current_life;
            while(l1--)
            {
                tmp = graphic_engine.life1;
                painter.drawPixmap(10+(tmp->width()+5)*l1,50,*tmp);
            }
            //bomb1
            int bomb_num = 0;
            if(graphic_engine.f1 != NULL)
            {
                bomb_num = graphic_engine.f1->bomb_list.size();
                while(bomb_num--)
                {
                    if(graphic_engine.f1->bomb_list[bomb_num] == Fighter::ATOMIC)
                        tmp = graphic_engine.bomb_atomic;
                    else if(graphic_engine.f1->bomb_list[bomb_num] == Fighter::DISPERSE)
                        tmp = graphic_engine.bomb_disperse;
                    painter.drawPixmap((tmp->width()+10)*bomb_num,this->height() - 30,*tmp);
                }
            }
        }

        //player2
        painter.setPen(QColor(Qt::white));
        painter.drawText(this->width() - 100,20,"2 UP:");
        painter.setPen(QColor(Qt::yellow));
        if(game.player1->START == false)
        {
            painter.drawText(this->width()-155,40,"PRESS START");
        }
        else{
            painter.drawText(this->width() - 100,40,QString::number((int)game.player1->score,10));
            //life2
            int l2 = game.player1->current_life;
            while(l2--)
            {
                tmp = graphic_engine.life2;
                painter.drawPixmap(this->width()-10-(tmp->width()+5)*(l2+1),50,*tmp);
            }
            //bomb2
            int bomb_num = 0;
            if(graphic_engine.f2 != NULL)
            {
                bomb_num = graphic_engine.f2->bomb_list.size();
                while(bomb_num--)
                {
                    if(graphic_engine.f2->bomb_list[bomb_num] == Fighter::ATOMIC)
                        tmp = graphic_engine.bomb_atomic;
                    else if(graphic_engine.f2->bomb_list[bomb_num] == Fighter::DISPERSE)
                        tmp = graphic_engine.bomb_disperse;
                    painter.drawPixmap(this->width()-(tmp->width()+10)*(bomb_num+1),this->height() - 30,*tmp);
                }
            }
        }
        //pause
        if (game.IsPaused()){
            font.setPixelSize(50);
            painter.setFont(font);
            painter.setPen(QColor(Qt::red));
            painter.drawText(width()/2-140,height()/2,"- PAUSED -");
        }
        //paint all_dead
        if(game.ALLDEAD)
            if(game.status == Game::GAME_OVER)
            {
                //paint game over
                font.setPixelSize(50);
                painter.setFont(font);
                painter.setPen(QColor(Qt::red));
                painter.drawText(width()/2-160,height()/2,"GAME OVER");
            }
            else
            {
                //paint credit
                font.setPixelSize(50);
                painter.setFont(font);
                painter.setPen(QColor(Qt::red));
                painter.drawText(width()/2-140,height()/2-40,"CONTINUE?");
                painter.drawText(width()/2-10,height()/2+40,QString::number((int)(10-game.all_dead_time),10));

                font.setPixelSize(20);
                painter.setFont(font);
                painter.setPen(QColor(Qt::yellow));
                painter.drawText(width()/2-40,height()-20,"CREDIT "+QString::number(game.coins));
            }
    }
    //paint door close
    if(graphic_engine.door_close)
    {
        cout<<"close"<<endl;
        int y1,y2;
        y1 =-250 + (int)(data.DOOR_SPEED*graphic_engine.door_time);
        if(y1>0){
            y1 = 0;
            graphic_engine.door_close = false;
        }
        y2 = 500 - (int)(data.DOOR_SPEED*graphic_engine.door_time);
        if(y2<250){
            y2 = 250;
            graphic_engine.door_close = false;
        }
            painter.drawPixmap(0,y1,*graphic_engine.door1);
            painter.drawPixmap(0,y2,*graphic_engine.door2);
    }
    //paint door open
    if(graphic_engine.door_open)
    {
        int y1,y2;
        y1 = -(int)(data.DOOR_SPEED*graphic_engine.door_time);
        if(y1<-250){
            y1 = -250;
            graphic_engine.door_open = false;
        }
        y2 = 250 + (int)(data.DOOR_SPEED*graphic_engine.door_time);
        if(y2>500){
            y2 = 500;
            graphic_engine.door_open = false;
        }
            painter.drawPixmap(0,y1,*graphic_engine.door1);
            painter.drawPixmap(0,y2,*graphic_engine.door2);
    }
    graphic_engine.END_PAINT = true;
}

