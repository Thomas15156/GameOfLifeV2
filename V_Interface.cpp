#include "File.h"
#include "V_Interface.h"

#include <string>
#include <iostream>

Interface::Interface() {}

int Interface::ChooseFile() {
    File File;
    File.Openfile();
    File.InitGrid();

}


std::string Interface::ChooseMode() {
    int mode;
    std::cout << "Choose the mode:" << std::endl;
    std::cout << "1. Console Mode" << std::endl;
    std::cout << "2. Graphic Mode" << std::endl;
    std::cout << "Enter the number of the mode: ";
    std::cin >> mode;

    if (mode == 1) {
        display_mode = "console";
        return display_mode;
    } else if (mode == 2) {
        display_mode = "graphics";
        return display_mode;
    } else {
        std::cerr << "Invalid mode selected." << std::endl;
    }
}

std::string Interface::get_display_mode()
{
    return display_mode;
}


