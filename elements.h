#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <QStringList>
#include <QPainter>
#include <QRectF>

class Elements{
public:   
//    get();
//    set();
    virtual void drawing(QPainter*) = 0;
    virtual QStringList::iterator reading(QStringList::iterator &it) = 0;
    virtual ~Elements() = default;
    void setScale(double scale);
protected:
    inline int angFactor(){
        return 16; //factor to Qt degrees
    };
    double scale_;
};

class Line : public Elements{
public:
    Line()  = default;
    Line(double x1, double y1, double x2, double y2);
    void drawing(QPainter*);
    QStringList::iterator reading(QStringList::iterator &it);
private:
    double x1_, y1_;
    double x2_, y2_;
};

class Circle : public Elements{
public:
    Circle() = default;
    Circle(double x1, double y1, double r);
    void drawing(QPainter*);
    QStringList::iterator reading(QStringList::iterator &it);
private:
    double x1_, y1_, r_;

};
class Arc : public Elements{
public:
    Arc() = default;
    Arc(double x1, double y1, double r, double ang1, double ang2);
    void drawing(QPainter*);
    QStringList::iterator reading(QStringList::iterator &it);
private:
    double x1_, y1_, r_;
    double ang1_, ang2_;

};

#endif // ELEMENTS_H
