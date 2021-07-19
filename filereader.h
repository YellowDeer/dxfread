#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFile>

class FileReader
{
public:
    FileReader(const QString &fileAddr);
    //QStringList readedFile(QString fileAddr);// убрать в конструктор и сделать get
    QStringList getList();
private:
    QStringList readedFile_;
};

#endif // FILEREADER_H
