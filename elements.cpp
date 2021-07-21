#include "elements.h"

Line::Line(double x1, double y1, double x2, double y2){
    x1_ = x1;
    y1_ = y1;
    x2_ = x2;
    y2_ = y2;
    scale_ = 1;
}

vector<double> Line::getPoint(){
    vector<double> points_;
    points_.push_back(LINE);
    points_.push_back(x1_ * scale_);
    points_.push_back(y1_ * scale_);
    points_.push_back(x2_ * scale_);
    points_.push_back(y2_ * scale_);
    return points_;
}

vector<string>::iterator Line::reading(vector<string>::iterator &it){
    while(it->data() != strEnd_){
        if (strX1_ == it->data()){
            ++it;
            x1_ = stod(it->data());
        }
        if (it->data() == strY1_){
            ++it;
            y1_ = stod(it->data());
        }
        if (it->data() == strX2_){
            ++it;
            x2_ = stod(it->data());
        }
        if (it->data() == strY2_){
            ++it;
            y2_ = stod(it->data());
        }
        ++it;
    }
    return it;
}

Circle::Circle(double x1, double y1, double r){
    x1_ = x1;
    y1_ = y1;
    r_ = r;
    scale_ = 1;
}

vector<double> Circle::getPoint(){
    vector<double> points_;
    points_.push_back(CIRCLE);
    points_.push_back(x1_ * scale_);
    points_.push_back(y1_ * scale_);
    points_.push_back(r_ * scale_);
    return points_;
}

vector<string>::iterator Circle::reading(vector<string>::iterator &it){
    while(it->data() != strEnd_){
        if (it->data() == strX1_){
            ++it;
            x1_ = stod(it->data());
        }
        if (it->data() == strY1_){
            ++it;
            y1_ = stod(it->data());
        }
        if (it->data() == strR_){
            ++it;
            r_ = stod(it->data());
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
    scale_ = 1;
}

vector<double> Arc::getPoint(){
    vector<double> points_;
    points_.push_back(ARC);
    points_.push_back(x1_ * scale_);
    points_.push_back(y1_ * scale_);
    points_.push_back(r_ * scale_);
    points_.push_back(ang1_);
    points_.push_back(ang2_);
    return points_;
}

vector<string>::iterator Arc::reading(vector<string>::iterator &it){
    while(it->data() != strEnd_){
        if (it->data() == strX1_){
            ++it;
            x1_ = stod(it->data());
        }
        if (it->data() == strY1_){
            ++it;
            y1_ = stod(it->data());
        }
        if (it->data() == strR_){
            ++it;
            r_ = stod(it->data());
        }
        if (it->data() == strAng1_){
            ++it;
            ang1_ = stod(it->data());
        }
        if (it->data() == strAng2_){
            ++it;
            ang2_ = stod(it->data());
        }
        ++it;
    }
    return it;
}

void Elements::setScale(double scale)
{
    if(scale < 0)
        scale_ = 0;
    else
        scale_ = scale;
}
