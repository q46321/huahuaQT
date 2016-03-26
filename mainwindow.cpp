#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "dialog.h"
int myleft;
int myrigth;
QColor color;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    myleft = STOP;
    myrigth = STOP;
    color = Qt::red;
      connect(&my_timer, SIGNAL(timeout()), this, SLOT(my_timer_out()));

    ui->setupUi(this);
    p = new paint1(ui->widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::my_timer_out()
{


        p->update();
}



QFont font1("Arial",40,QFont::Normal,false);
void MainWindow::on_fontAction_triggered()
{
    bool ok;

    font1=QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->textEdit->setFont(font1);
    }


}

void MainWindow::on_colorAction_triggered()
{
    color=QColorDialog::getColor(Qt::red,this);
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
     p->update();
}


void MainWindow::on_pingcanAction_triggered()
{
    Dialog dlg;
    if(dlg.exec() == QDialog::Accepted)
    {
    int width = dlg.getWidth()*4;
    int height = dlg.getHeight()*4;


}
}

void MainWindow::on_textEdit_textChanged()
{

    QString str = ui->textEdit->toPlainText();
    p->setText(str);
    p->update();
}

void MainWindow::on_radioButton_clicked()
{
      my_timer.stop();
    if(myrigth == START)
        myrigth = STOP;
    if(myleft == STOP)
        myleft = START;
    my_timer.start(100);
}

void MainWindow::on_radioButton_3_clicked()
{
    if(myleft == START)
        myleft = STOP;
    if(myrigth == START)
        myrigth = STOP;
    my_timer.stop();
    p->update();
}

void MainWindow::on_radioButton_2_clicked()
{
      my_timer.stop();
    if(myleft == START)
        myleft = STOP;
    if(myrigth == STOP)
        myrigth = START;
    my_timer.start(100);

}

void MainWindow::on_action_QT_triggered()
{
    QMessageBox::information(this,tr("关于QT"),tr("Qt是一个多平台的C++图形用户界面应用程序框架。它提供给应用程序开发者建立 艺术级的图形用户界面所需的所用功能。Qt是完全面向对象的很容易扩展，并且 允许真正地组件编程。"));
}

void MainWindow::on_action_triggered()
{
    QDateTime current=QDateTime::currentDateTime();
    QString time=current.toString("yyyy-M-dd hh:mm:ss");
    ui->textEdit->setText(time);
}
