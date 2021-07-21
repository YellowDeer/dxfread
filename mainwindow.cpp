#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->doubleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double s){if(d != nullptr) d->scale(s);});
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::slotOpen);
    scene  = new QGraphicsScene;
    scene->addItem(d);
    ui->graphicsView->setScene(scene);
}

void MainWindow::slotOpen(){
    QString str = QFileDialog::getOpenFileName(this, tr("Open File"), "..", tr("DXF ( *.DXF)"));
    if (d != nullptr)
        delete d;
    d = new DrawerElem(this);
    d->scale_ = ui->doubleSpinBox->value();
    d->getFile(str);
    scene->addItem(d);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow(){
    delete ui;
}

