#include "fabricelem.h"

Elements* FabricElem::makeLine(){
    Elements* line  = new Line();
    return line;
}

Elements *FabricElem::makeLine(double x1, double y1, double x2, double y2){
    Elements* line  = new Line(x1, y1, x2, y2);
    return line;
}

Elements* FabricElem::makeCircle(){
    Elements* circle  = new Circle();
    return circle;
}

Elements *FabricElem::makeCircle(double x1, double y1, double r){
    Elements* circle  = new Circle(x1, y1, r);
    return circle;
}

Elements* FabricElem::makeArc(){
    Elements* arc  = new Arc();
    return arc;
}

Elements *FabricElem::makeArc(double x1, double y1, double r, double ang1, double ang2){
    Elements* arc  = new Arc(x1, y1, r, ang1, ang2);
    return arc;
}

