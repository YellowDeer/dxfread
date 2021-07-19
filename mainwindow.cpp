#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slot_scaleImage()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_open()));
    d = new DrawerElem(this);
    d->getFile(":/Untitled1.dxf");
    scene  = new QGraphicsScene;
    scene->addItem(d);
    ui->graphicsView->setScene(scene);
}

void MainWindow::slot_scaleImage(){
    d->scale(ui->doubleSpinBox->value());
}

void MainWindow::slot_open(){
    QString str = QFileDialog::getOpenFileName(this, tr("Open File"), "..", tr("DXF ( *.DXF)"));
    delete d;
    d = new DrawerElem(this);
    d->getFile(str);
    scene->addItem(d);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow(){
    delete ui;
}

