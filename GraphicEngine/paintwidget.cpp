#include "paintwidget.h"
#include "../res.h"

PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent)
{
   graphic_engine.back_ground = new QPixmap(":/images/Images/background_image/background.png");
   graphic_engine.title = new QPixmap(":/images/Images/background_image/Title.png");
   connect(&graphic_engine,SIGNAL(Update()),this,SLOT(PaintFrame()));
   connect(&graphic_engine,SIGNAL(PlayBGM()),&se,SLOT(PlaySoundBGM()));
   connect(&graphic_engine,SIGNAL(PlaySoundBulletYellow()),&se,SLOT(PlaySoundBulletYellow()));
   connect(&graphic_engine,SIGNAL(PlaySoundBulletBlue()),&se,SLOT(PlaySoundBulletBlue()));
   connect(&graphic_engine,SIGNAL(PlaySoundBulletPurple()),&se,SLOT(PlaySoundBulletPurple()));
}

void PaintWidget::paintEvent(QPaintEvent* event)
{
    extern Data data;
    QPainter painter(this);
    if(game.WELCOME == true)
    {
        painter.drawPixmap(0,0,*graphic_engine.title);
    }
    else{
        //paint background
        if(graphic_engine.back_ground != NULL)
        {
            int bky1,bky2;

            bky1 = (int)(graphic_engine.back_ground->height()-this->height()-graphic_engine.bk_time * data.BACKGROUND_SPEED);
            if(bky1 <= 0) bky1 = 0;

            bky2 = (int)(graphic_engine.back_ground->height()-graphic_engine.bk_time * data.BACKGROUND_SPEED);
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
        graphic_engine.pics_to_show.clear();
        //paint foreground
        //player1
        QFont font("Time New Roma",15,QFont::Bold,false);
        painter.setFont(font);
        painter.setPen(QColor(Qt::white));
        painter.drawText(10,20,"1 UP:");
        painter.setPen(QColor(Qt::yellow));
        if(game.player0->START == false)
        {
            painter.drawText(this->width()-155,40,"PRESS START");
        }
        else painter.drawText(10,40,QString::number((int)game.player0->score,10));
        //bomb1
        int bomb_num = 0;
        if(graphic_engine.f1 != NULL)
        {
            bomb_num = graphic_engine.f1->bomb_list.size();
            while(bomb_num--)
            {
                QPixmap tmp;
                if(graphic_engine.f1->bomb_list[bomb_num] = Fighter::ATOMIC)
                    tmp = tmp.fromImage(QImage(":/images/Images/item_image/ItemBombAtomic.png"));
                else if(graphic_engine.f1->bomb_list[bomb_num] = Fighter::DISPERSE)
                    tmp = tmp.fromImage(QImage(":/images/Images/item_image/ItemBombDisperse.png"));
                painter.drawPixmap((tmp.width()+10)*bomb_num,this->height() - 30,tmp);
            }
        }
        //player2
        painter.setPen(QColor(Qt::white));
        painter.drawText(this->width() - 65,20,"2 UP:");
        painter.setPen(QColor(Qt::yellow));
        if(game.player1->START == false)
        {
            painter.drawText(this->width()-155,40,"PRESS START");
        }
        else painter.drawText(10,40,QString::number((int)game.player1->score,10));
        //bomb2
        if(graphic_engine.f2 != NULL)
        {
            bomb_num = graphic_engine.f2->bomb_list.size();
            while(bomb_num--)
            {
                QPixmap tmp;
                if(graphic_engine.f2->bomb_list[bomb_num] = Fighter::ATOMIC)
                    tmp = tmp.fromImage(QImage(":/images/Images/item_image/ItemBombAtomic.png"));
                else if(graphic_engine.f2->bomb_list[bomb_num] = Fighter::DISPERSE)
                    tmp = tmp.fromImage(QImage(":/images/Images/item_image/ItemBombDisperse.png"));
                painter.drawPixmap(this->width()-(tmp.width()+10)*(bomb_num+1),this->height() - 30,tmp);
            }
        }
    }
}

