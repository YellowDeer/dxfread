#ifndef FABRICELEM_H
#define FABRICELEM_H

#include "elements.h"

class FabricElem
{
public:
    Elements* makeLine();
    Elements* makeLine(double x1, double  y1, double  x2, double y2);

    Elements* makeCircle();
    Elements* makeCircle(double x1, double y1, double r);

    Elements* makeArc();
    Elements* makeArc(double x1, double y1, double r, double ang1 , double ang2);
};

#endif // FABRICELEM_H
