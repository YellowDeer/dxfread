#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class FileReader
{
public:
    FileReader(const string &fileAddr);
    vector<string> getList();
private:
    vector<string> readedFile_;
};

#endif // FILEREADER_H
