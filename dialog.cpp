#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
int Dialog::getHeight()
{
    return ui->lineEdit_2->text().toInt();

}
int Dialog::getWidth()
{
   return ui->lineEdit->text().toInt();

}

Dialog::~Dialog()
{
    delete ui;
}
