#include "filereader.h"
FileReader::FileReader(){

}

QStringList FileReader::readedFile(QString fileAddr){
    QFile file(fileAddr);
    QStringList readedFile;
    if((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while (!file.atEnd()) {
            readedFile.append(file.readLine());
        }
    }
    return readedFile;
}
