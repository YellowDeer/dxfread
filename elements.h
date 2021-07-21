#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <iostream>
#include <vector>

enum TypesEntities{
    LINE,
    CIRCLE,
    ARC,
};

using namespace std;

class Elements{
public:   
    virtual vector<double> getPoint() = 0;
    virtual vector<string>::iterator reading(vector<string>::iterator &it) = 0;
    virtual ~Elements() = default;
    void setScale(double scale);
protected:
    string strX1_ = " 10";
    string strX2_ = " 11";
    string strY1_ = " 20";
    string strY2_ = " 21";
    string strR_ = " 40";
    string strAng1_ = " 50";
    string strAng2_ = " 51";
    string strEnd_ = "  0";
    double scale_;
};

class Line : public Elements{
public:
    Line()  = default;
    Line(double x1, double y1, double x2, double y2);
    vector<double> getPoint();
//    void drawing(QPainter*);
    vector<string>::iterator reading(vector<string>::iterator &it);
private:
    double x1_, y1_;
    double x2_, y2_;
};

class Circle : public Elements{
public:
    Circle() = default;
    Circle(double x1, double y1, double r);
    vector<double> getPoint();
//    void drawing(QPainter*);
    vector<string>::iterator reading(vector<string>::iterator &it);
private:
    double x1_, y1_, r_;

};
class Arc : public Elements{
public:
    Arc() = default;
    Arc(double x1, double y1, double r, double ang1, double ang2);
    vector<double> getPoint();
//    void drawing(QPainter*);
    vector<string>::iterator reading(vector<string>::iterator &it);
private:
    double x1_, y1_, r_;
    double ang1_, ang2_;

};

#endif // ELEMENTS_H
