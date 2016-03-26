#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include "paint1.h"
#include <QMessageBox>
#include <Qtimer>
#include <QDateTime>

#define START 1
#define STOP 0

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:


    void on_fontAction_triggered();
    void on_colorAction_triggered();

    void on_pingcanAction_triggered();

    void on_textEdit_textChanged();
    void my_timer_out();
    void on_radioButton_clicked();

    void on_radioButton_3_clicked();
    void on_radioButton_2_clicked();

    void on_action_QT_triggered();

    void on_action_triggered();

private:
    Ui::MainWindow *ui;
    int k,h;
    QTimer my_timer;

    paint1 *p;


};

#endif // MAINWINDOW_H
