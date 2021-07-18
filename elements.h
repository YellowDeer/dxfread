#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <QStringList>
#include <QPainter>
#include <QRectF>

class Elements{
public:
    inline int angFactor(){
        return 16; //factor to Qt degrees
    };
    double scale;
    virtual void drawing(QPainter*) = 0;
    virtual QStringList::iterator reading(QStringList::iterator &it) = 0;
    virtual ~Elements() = default;
};

class Line : public Elements{
public:
    Line()  = default;
    Line(double x1, double y1, double x2, double y2);
    double x1_, y1_;
    double x2_, y2_;
    void drawing(QPainter*);
    QStringList::iterator reading(QStringList::iterator &it);
};

class Circle : public Elements{
public:
    Circle() = default;
    Circle(double x1, double y1, double r);
    double x1_, y1_, r_;
    void drawing(QPainter*);
    QStringList::iterator reading(QStringList::iterator &it);
};
class Arc : public Elements{
public:
    Arc() = default;
    Arc(double x1, double y1, double r, double ang1, double ang2);
    double x1_, y1_, r_;
    double ang1_, ang2_;
    void drawing(QPainter*);
    QStringList::iterator reading(QStringList::iterator &it);
};
#endif // ELEMENTS_H
