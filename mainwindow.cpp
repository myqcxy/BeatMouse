#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <hander.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->score = 0;
    ui->setupUi(this);
    this->scene = new MyScene;
    this->ui->graphicsView->setScene(this->scene);
    connect(this->ui->btn_start,SIGNAL(clicked(bool)),this->scene,SLOT(startGame()));
    connect(this->ui->btn_pause,SIGNAL(clicked(bool)),this->scene,SLOT(pauseGame()));
    connect(this->ui->btn_stop,SIGNAL(clicked(bool)),this->scene,SLOT(stopGame()));
    hander *hand = hander::getInstance();
    connect(hand,SIGNAL(beatMouse()),this,SLOT(updateScore()));
    connect(this->ui->btn_stop,SIGNAL(clicked(bool)),this,SLOT(reinit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this,"确定","是否关闭游戏","是","否");
    if(ret ==1)
        event ->ignore();
}
void MainWindow::updateScore(){
    this->score += 10;
    this->ui->lcdNumber->display(this->score);
}
void MainWindow::reinit(){
    this->score = 0;
    this->ui->lcdNumber->display(this->score);
}
