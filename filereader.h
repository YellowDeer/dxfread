#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFile>



class FileReader
{
public:
    FileReader();
    QStringList readedFile(QString fileAddr);
};

#endif // FILEREADER_H
