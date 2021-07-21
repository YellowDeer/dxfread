#ifndef CONTAINERELEM_H
#define CONTAINERELEM_H

#include "fabricelem.h"
#include "elements.h"
#include "filereader.h"

using namespace std;

class ContainerElem
{
public:
    ContainerElem() = default;
    ContainerElem(const string &fileaddr);
    void setScale(double s);
    const vector<Elements*> &getVect();
private:
    vector<string> readedData_;
    vector<Elements*> vect_elem_;


};

#endif // CONTAINERELEM_H
