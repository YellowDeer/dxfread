#ifndef CONTAINERELEM_H
#define CONTAINERELEM_H

#include <QVector>

#include "fabricelem.h"
#include "elements.h"
#include "filereader.h"

class ContainerElem
{
public:
    ContainerElem() = default;
    ContainerElem(const QString &fileaddr);
    void setScale(double s);
    const QVector<Elements*> getVect();
private:
    QStringList readedData_;
    QVector<Elements*> vect_elem_;


};

#endif // CONTAINERELEM_H
