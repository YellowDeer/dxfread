#include "drawerelem.h"

DrawerElem::DrawerElem(QObject *parent){
    scale_ = 1;
}

QRectF DrawerElem::boundingRect() const{
    return QRectF(-500, -500, 1000, 1000);
}

void DrawerElem::getFile(const QString &fileAddr){
    const std::string str = fileAddr.toStdString();
    container_ = QSharedPointer<ContainerElem>(new ContainerElem(str));
    container_->setScale(scale_);
    vect_ = container_->getVect();
}

void DrawerElem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    this->setPos(0, 0);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->rotate(180);
    painter->translate(0, 0);
    painter->setPen(Qt::black);
    for (auto &&it:vect_){
        std::vector<double> tmpVect_ = it->getPoint();
        if (tmpVect_.at(0) == TypesEntities::LINE){
                QPointF p1(-tmpVect_.at(1), tmpVect_.at(2));
                QPointF p2(-tmpVect_.at(3), tmpVect_.at(4));
                painter->drawLine(p1, p2);
        }
        if (tmpVect_.at(0) == TypesEntities::CIRCLE){
                QPointF p1(-tmpVect_.at(1), tmpVect_.at(2));
                painter->drawEllipse(p1, tmpVect_.at(3), tmpVect_.at(3));
        }
        if (tmpVect_.at(0) == TypesEntities::ARC){
                QRectF rect((-tmpVect_.at(1) + tmpVect_.at(3)), (tmpVect_.at(2)- tmpVect_.at(3)), -(tmpVect_.at(3) * 2), (tmpVect_.at(3) * 2));
                double a1, a2;
                if (tmpVect_.at(4) < tmpVect_.at(5)){
                    a1 = (tmpVect_.at(4) - 180) * angFactor();
                    a2 = qAbs(tmpVect_.at(5) - tmpVect_.at(4)) * angFactor();
                }
                else{
                    a1 = (tmpVect_.at(4) - 180) * angFactor();
                    a2 = qAbs(360  - tmpVect_.at(4) + tmpVect_.at(5)) * angFactor();
                }
                painter->drawArc(rect, a1, a2);
        }
    }
    painter->setPen(Qt::red);
    painter->drawEllipse(QPointF(0, 0), 50, 50);
}

void DrawerElem::scale(double scl){
    if (container_ == nullptr)
        return;
    scale_ = scl;
    container_->setScale(scl);
    this->update();
}
