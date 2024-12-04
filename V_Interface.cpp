#include "File.h"
#include "V_Interface.h"

#include <string>
#include <iostream>

Interface::Interface() {}

int Interface::ChooseFile() {
    File myFile;
    myFile.Openfile();
    myFile.InitGrid();

    //Utiliser la méthode get_temp_grid pour obtenir la grille
    std::vector<std::vector<int>> get_temp_grid = myFile.get_temp_grid();
    for (const auto& row : get_temp_grid) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


std::string Interface::ChooseMode() {
    int mode;
    std::cout << "Choose the mode:" << std::endl;
    std::cout << "1. Console Mode" << std::endl;
    std::cout << "2. Graphic Mode" << std::endl;
    std::cout << "Enter the number of the mode: ";
    std::cin >> mode;

    if (mode == 1) {
        get_display_mode = "console";
        return get_display_mode;
    } else if (mode == 2) {
        get_display_mode = "graphics";
        return get_display_mode;
    } else {
        std::cerr << "Invalid mode selected." << std::endl;
    }
}