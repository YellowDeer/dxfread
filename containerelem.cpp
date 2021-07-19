#include "containerelem.h"

ContainerElem::ContainerElem(const QString &fileaddr)
{
    FabricElem fabric_;
    FileReader reader_(fileaddr);
    readedData_ = reader_.getList();
    QStringList::iterator it = readedData_.begin();
    while (it != readedData_.end()) {
        if (it->contains("ENTITIES")){
            do{
                if (it->contains("LINE")){
                    vect_elem_.append(fabric_.makeLine());
                    it = vect_elem_.back()->reading(it);
                }
                if (it->contains("CIRCLE")){
                    vect_elem_.append(fabric_.makeCircle());
                    it = vect_elem_.back()->reading(it);
                }
                if (it->contains("ARC")){
                    vect_elem_.append(fabric_.makeArc());
                    it = vect_elem_.back()->reading(it);
                }
                ++it;
            }
            while(!it->contains("ENDSEC"));
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

const QVector<Elements *> ContainerElem::getVect()
{
    return vect_elem_;
}
