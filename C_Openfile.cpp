#include "C_Openfile.h"
#include <iostream>

Openfile::Openfile() {}

bool Openfile::runopenfile() {

    std::cout << "Enter your file name:";
    std::cin >> filename;

    filestream.open(filename);
    if (!filestream.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }else {
        std::cout << "Open sucess :" << filename << std::endl;
        return true;
    }
}


