#include "filereader.h"

FileReader::FileReader(const QString &fileAddr){
    QFile file(fileAddr);
    if((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while (!file.atEnd()) {
            readedFile_.append(file.readLine());
        }
    }
}

QStringList FileReader::getList(){
    return readedFile_;
}


