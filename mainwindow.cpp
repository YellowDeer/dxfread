#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slot_scaleImage()));
    d = new DrawerElem(this);
    d->getFile(":/Untitled1.dxf");
    QGraphicsScene *scene  = new QGraphicsScene;
    scene->addItem(d);
    ui->graphicsView->setScene(scene);
}

void MainWindow::slot_scaleImage(){
    d->scale(ui->doubleSpinBox->value());
}

MainWindow::~MainWindow(){
    delete ui;
}

