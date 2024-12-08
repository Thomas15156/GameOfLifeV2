#include "V_Interface.h"
#include <iostream>
#include <limits>

Interface::Interface() : display_mode("invalid"), is_toroidal(false), update_interval(1000) {}

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
        update_interval = ChooseUpdateInterval();
        break;
        default:
            std::cerr << "Invalid mode selected. Please enter 1 or 2." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return display_mode;
}

float Interface::ChooseUpdateInterval() {
    float interval;

    while (true) {
        std::cout << "Enter the update interval in milliseconds (positive integer): ";

        if (std::cin >> interval) {
            if (interval > 0 ) {
                break;
            } else {
                std::cerr << "The value must be a positive integer. Please try again." << std::endl;
            }
        } else {
            std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return interval;
}

bool Interface::ChooseToroidal() {
    char choice;
    std::cout << "Do you want to enable toroidal grid? (y/n): ";
    std::cin >> choice;

    is_toroidal = (choice == 'y' || choice == 'Y');
    return is_toroidal;
}

std::string Interface::get_display_mode() const {
    return display_mode;
}

int Interface::get_update_interval() const {
    return update_interval;
}