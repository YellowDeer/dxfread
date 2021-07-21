#ifndef DRAWERELEM_H
#define DRAWERELEM_H

#include <QGraphicsObject>
#include <QPainter>
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
    QSharedPointer<ContainerElem> container_;
    std::vector<Elements*> vect_;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    inline int angFactor(){
        return 16; //factor to Qt degrees
    };

};

#endif // DRAWERELEM_H
