#ifndef C_OPENFILE_H
#define C_OPENFILE_H
#include <fstream>

class Openfile {
public:
    Openfile();
    bool runopenfile();
    std::string filename;
    private:
    std::ifstream filestream;




};

#endif