#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include <QRect>
#include <QPainter>





class paint1 : public QWidget
{
    Q_OBJECT
public:
    paint1(QWidget *parent=0);
    void setText(QString s);
private:
    int k,h;
    QString myStr;
    QImage image;


    void paintEvent(QPaintEvent*);

};

#endif // PAINT_H
