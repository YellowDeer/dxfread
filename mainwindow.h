#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "drawerelem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    DrawerElem *d;
    QGraphicsScene *scene;
public slots:
//    void slotScaleImage(double s);
    void slotOpen();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
