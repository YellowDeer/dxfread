#include "drawerelem.h"

DrawerElem::DrawerElem(QObject *parent){

}

QRectF DrawerElem::boundingRect() const{
    return QRectF(-500, -500, 1000, 1000);
}

void DrawerElem::getVector(QString fileAddr){
    cont.readAddrAndStart(fileAddr);
    for (auto &&it:cont.vect_elem_){
        it->scale = 1;
    }
}

void DrawerElem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    this->setPos(0, 0);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->rotate(180);
    painter->translate(0, 0);
    painter->setPen(Qt::black);
    for (auto &&it:cont.vect_elem_){
        it->drawing(painter);
    }
    painter->setPen(Qt::red);
    painter->drawEllipse(0, 0, 50, 50);
}

void DrawerElem::scale(double scl){
    for (auto &&it:cont.vect_elem_){
           it->scale = scl;
    }
    this->update();
}
