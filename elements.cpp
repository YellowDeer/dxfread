#include "elements.h"

Line::Line(double x1, double y1, double x2, double y2){
    x1_ = x1;
    y1_ = y1;
    x2_ = x2;
    y2_ = y2;
}


void Line::drawing(QPainter * painter){
    painter->save();
    QPointF p1(-x1_ * scale, y1_ * scale);
    QPointF p2(-x2_ * scale, y2_ * scale);
    painter->drawLine(p1, p2);
    painter->restore();
}

QStringList::iterator Line::reading(QStringList::iterator &it){
    while(!it->contains("  0")){
        if (it->contains(" 10")){
            ++it;
            x1_ = it->toDouble();
        }
        if (it->contains(" 20")){
            ++it;
            y1_ = it->toDouble();
        }
        if (it->contains(" 11")){
            ++it;
            x2_ = it->toDouble();
        }
        if (it->contains(" 21")){
            ++it;
            y2_ = it->toDouble();
        }
        ++it;
    }
    return it;
}

Circle::Circle(double x1, double y1, double r){
    x1_ = x1;
    y1_ = y1;
    r_ = r;
}

void Circle::drawing(QPainter * painter){
    painter->save();
    painter->drawEllipse(-x1_ * scale, y1_ * scale, r_ * scale, r_ * scale);
    painter->restore();
}

QStringList::iterator Circle::reading(QStringList::iterator &it){
    while(!it->contains("  0")){
        if (it->contains(" 10")){
            ++it;
            x1_ = it->toDouble();
        }
        if (it->contains(" 20")){
            ++it;
            y1_ = it->toDouble();
        }
        if (it->contains(" 40")){
            ++it;
            r_ = it->toDouble();
        }
        ++it;
    }
    return it;
}

Arc::Arc(double x1, double y1, double r, double ang1, double ang2){
    x1_ = x1;
    y1_ = y1;
    r_ = r;
    ang1_ = ang1;
    ang2_ = ang2;
}

void Arc::drawing(QPainter * painter){
    painter->save();
    QRectF rect((-x1_ - r_) * scale, (y1_- r_) * scale, -(r_ * 2) * scale, (r_ * 2) * scale);
    double a1, a2;
    if (ang1_ < ang2_)
    {
        a1 = (ang1_ - 180) * angFactor();
        a2 = qAbs(ang2_ - ang1_) * angFactor();
    }
    else
    {
        a1 = (ang1_ - 180) * angFactor();
        a2 = qAbs(ang2_ - ang1_) * angFactor();
    }
    painter->drawArc(rect, a1, a2);
    painter->restore();
}

QStringList::iterator Arc::reading(QStringList::iterator &it){
    while(!it->contains("  0")){
        if (it->contains(" 10")){
            ++it;
            x1_ = it->toDouble();
        }
        if (it->contains(" 20")){
            ++it;
            y1_ = it->toDouble();
        }
        if (it->contains(" 40")){
            ++it;
            r_ = it->toDouble();
        }
        if (it->contains(" 50")){
            ++it;
            ang1_ = it->toDouble();
        }
        if (it->contains(" 51")){
            ++it;
            ang2_ = it->toDouble();
        }
        ++it;
    }
    return it;
}
