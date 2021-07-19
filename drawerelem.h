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
    void getFile(const QString &fileAddr);
    void scale(double scl);
private:
    ContainerElem *cont;
    QVector<Elements*> vect;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};

#endif // DRAWERELEM_H
