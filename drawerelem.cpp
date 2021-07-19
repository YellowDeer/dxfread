#include "drawerelem.h"

DrawerElem::DrawerElem(QObject *parent){//неявно вызывался конструктор

}

QRectF DrawerElem::boundingRect() const{
    return QRectF(-500, -500, 1000, 1000);
}

void DrawerElem::getFile(const QString &fileAddr){
    cont = new ContainerElem(fileAddr);//поменять на const QString &
    cont->setScale(1);
    vect = cont->getVect();
}

void DrawerElem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    this->setPos(0, 0);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->rotate(180);
    painter->translate(0, 0);
    painter->setPen(Qt::black);
    for (auto &&it:vect){
        it->drawing(painter);
    }
    painter->setPen(Qt::red);
    painter->drawEllipse(0, 0, 50, 50);
}

void DrawerElem::scale(double scl){
    cont->setScale(scl);
    this->update();
}
