#include "paint1.h"
#include <QRect>
#include <QImage>
#include "mainwindow.h"
#include <QDebug>

#define START 1
#define STOP 0

extern int myleft;
extern int myrigth;
extern QColor color;
extern QFont font1;
int my_x = 200;
int my_y = 120;
paint1::paint1(QWidget *parent)
    : QWidget(parent)
{
    k=128*4;
    h=64*4;
    myStr = "123";

    this->setMaximumSize(k,h);
    this->setMinimumSize(k,h);

}
void paint1::paintEvent(QPaintEvent *)
{

    QPainter *paint=new QPainter();
    paint->begin(this);
    paint->setPen(QPen(Qt::darkRed,1,Qt::SolidLine));
    paint->setBrush(QBrush(Qt::gray,Qt::SolidPattern));
    int x = parentWidget()->width()/2;
    int y =parentWidget()->height()/2;
    QRect ff(parentWidget()->width()/2-k/2,parentWidget()->height()/2-h/2,k,h);
//    paint->drawRect(ff);

    for(int i = 0; i<h;)
    {
         paint->setPen(QPen(Qt::black,Qt::SolidLine));
        paint->drawLine(x-k/2,y-h/2+i,x+k/2,y-h/2+i);
        i=i+4;
    }
    for(int j = 0; j<k;)
    {
        paint->setPen(QPen(Qt::black,Qt::SolidLine));
        paint->drawLine(x-k/2+j,y-h/2,x-k/2+j,y+h/2);
        j=j+4;
    }
//    QSize size(200,200); //指定图片大小;
//    QImage image(size,QImage::Format_ARGB32);
//    paint->drawText(image.rect(),Qt::AlignCenter,myStr);


     QImage image(512, 256, QImage::Format_Mono);

     QPainter painter (&image); //选入绘图设备中。
      QRgb backColor = qRgb(255,255,255);
      image.fill(backColor); //将位图背景设置为白色
     QFont font;
     font.setFamily("SimSun"); //设置字体，宋体
     font.setPixelSize(64); //设置字号32,以像素为单位
     font.setWeight (50 ); //设置字型,不加粗
     font. setItalic(false); //设置字型,不倾斜
     font.setUnderline(false); //设置字型,无下划线
     painter.setFont(font);


     int flats = Qt::AlignCenter | Qt::AlignTop;
     painter.drawText (image.rect(), flats,myStr);

     // painter.drawImage(ff, image,image.rect());
      for(int i=0;i<512;i++)
     {

          for(int j=0; j<256; j++)
      {

       int m_nCount = 0;
       unsigned char m_nbyte = 0x80;
       unsigned char m_ncurrentByte = *(image.bits()+i*64+j);
      // printf("m_ncurrentByte : %0x/n", m_ncurrentByte);

       while(m_nCount < 8)
       {

        m_nbyte = 0x80;
        m_nbyte >>= m_nCount%8;
        //printf("m_nbyte        : %0x/n", m_nbyte);
        if((!(m_ncurrentByte & m_nbyte)))
         paint->drawPoint(j*8+m_nCount, i);
        m_nCount+=2;
       }

      }

     }

    if(myleft == START)
    {

        paint->setFont(font1);
        paint->setPen(QColor(color));
        paint->setBrush(QBrush(Qt::Dense7Pattern));
       // paint->drawRect(ff);
        my_x-=2;
        paint->drawText(my_x,my_y,myStr);

    }else if(myrigth == START)
    {

        paint->setFont(font1);
        paint->setPen(QColor(color));
        paint->setBrush(QBrush(Qt::Dense7Pattern));
       // paint->drawRect(ff);
        my_x+=2;
        paint->drawText(my_x,my_y,myStr);

    }else
    {

    paint->setFont(font1);
    paint->setPen(QColor(color));
    paint->setBrush(QBrush(Qt::Dense7Pattern));
   // paint->drawRect(ff);
    int my_x = 200;
    paint->drawText(my_x,my_y,myStr);



   }
}



void paint1::setText(QString s)
{
    myStr = s;
}
