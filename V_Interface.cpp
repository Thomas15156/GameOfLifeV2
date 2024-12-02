#include "C_Openfile.h"
#include "V_Interface.h"
#include "V_Graphic.h"
#include "V_Console.h"

#include <iostream>

Interface::Interface() {}

bool Interface::ChooseFile() {
    Openfile openfile;
    return openfile.runopenfile();
}

bool Interface::ChooseMode() {
    int mode;
    std::cout << "Choose the mode:" << std::endl;
    std::cout << "1. Console Mode" << std::endl;
    std::cout << "2. Graphic Mode" << std::endl;
    std::cout << "Enter the number of the mode: ";
    std::cin >> mode;

    if (mode == 1) {
        Console console;
        console.runconsole();
        return true;
    } else if (mode == 2) {
        Graphic graphic;
        graphic.rungraphic();
        return true;
    } else {
        std::cerr << "Invalid mode selected." << std::endl;
        return false;
    }
}
