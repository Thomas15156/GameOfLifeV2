#include "V_Interface.h"
#include <iostream>

Interface::Interface() : display_mode("invalid"), update_interval(1000) {} // Initialiser update_interval

std::string Interface::ChooseMode() {
    int mode;
    std::cout << "Choose the mode:" << std::endl;
    std::cout << "1. Console Mode" << std::endl;
    std::cout << "2. Graphic Mode" << std::endl;
    std::cout << "Enter the number of the mode: ";
    std::cin >> mode;

    switch (mode) {
        case 1:
            display_mode = "console";
        break;
        case 2:
            display_mode = "graphics";
        break;
        default:
            std::cerr << "Invalid mode selected." << std::endl;
        display_mode = "invalid";
        break;
    }
    return display_mode;
}

bool Interface::ChooseToroidal() {
    char choice;
    std::cout << "Do you want to enable toroidal grid? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        is_toroidal = true;
    } else {
        is_toroidal = false;
    }
    return is_toroidal;
}

int Interface::ChooseUpdateInterval() {
    std::cout << "Enter the update interval in milliseconds: ";
    std::cin >> update_interval;
    return update_interval;
}

std::string Interface::get_display_mode() const {
    return display_mode;
}