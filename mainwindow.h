#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myscene.h"
#include <QCloseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent * event);

    private slots:
    void updateScore();
    void reinit();
private:
    Ui::MainWindow *ui;
    MyScene * scene;
    int score;
};


#endif // MAINWINDOW_H
