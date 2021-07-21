#include "filereader.h"

FileReader::FileReader(const string &fileAddr){
    ifstream _file;
    _file.open(fileAddr);
    if(_file){
        string str_ = "";
        while(getline(_file, str_)){
            readedFile_.push_back(str_);
        }
    }
}

vector<string> FileReader::getList(){
    return readedFile_;
}
