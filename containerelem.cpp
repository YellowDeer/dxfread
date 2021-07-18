#include "containerelem.h"

void ContainerElem::readAddrAndStart(QString fileaddr){
    fileAddr_ = fileaddr;
    makeElements();
}

void ContainerElem::makeElements(){
    readedData_ = reader_.readedFile(fileAddr_);
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
