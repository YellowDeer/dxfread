#ifndef CONTAINERELEM_H
#define CONTAINERELEM_H

#include <QVector>

#include "fabricelem.h"
#include "elements.h"
#include "filereader.h"

class ContainerElem
{
public:
    QString fileAddr_;
    FileReader reader_;
    QStringList readedData_;
    QVector<Elements*> vect_elem_;
    FabricElem fabric_;
    void readAddrAndStart(QString fileaddr);
    void makeElements();
};

#endif // CONTAINERELEM_H
