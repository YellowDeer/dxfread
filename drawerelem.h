#ifndef DRAWERELEM_H
#define DRAWERELEM_H

#include <QGraphicsObject>
#include "containerelem.h"

class DrawerElem : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit DrawerElem(QObject *parent = 0);
    QRectF boundingRect() const override;
    ContainerElem cont;
    void getVector(QString fileAddr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void scale(double scl);
};

#endif // DRAWERELEM_H
