#include "containerelem.h"

ContainerElem::ContainerElem(const string &fileaddr)
{
    FabricElem fabric_;
    FileReader reader_(fileaddr);
    readedData_ = reader_.getList();
    vector<string>::iterator it = readedData_.begin();
    string entities_ = "ENTITIES";
    string line_ = "LINE";
    string circle_ = "CIRCLE";
    string arc_ = "ARC";
    string endsec_ = "ENDSEC";
    while ((it != readedData_.cend()) && (readedData_.size()>0)) {
        if (it->data() == entities_){
            do{
                if (it->data() == line_){
                    vect_elem_.push_back(fabric_.makeLine());
                    it = vect_elem_.back()->reading(it);
                }
                if (it->data() == circle_){
                    vect_elem_.push_back(fabric_.makeCircle());
                    it = vect_elem_.back()->reading(it);
                }
                if (it->data() == arc_){
                    vect_elem_.push_back(fabric_.makeArc());
                    it = vect_elem_.back()->reading(it);
                }
                ++it;
            }
            while(it->data() != endsec_);
        }
        ++it;
    }
}

void ContainerElem::setScale(double s)
{
    for (auto &&it:vect_elem_){
        it->setScale(s);
    }
}

const vector<Elements *> &ContainerElem::getVect(){
    return   vect_elem_;
}
