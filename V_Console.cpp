//
// Created by benjamin Bourlet on 03/12/2024.
//

#include "V_Console.h"

#include <iostream>
#include <ostream>

Console::Console(Grid& display_grid) : display_grid(display_grid) {}


void Console::run_display()
{
    std::cout << "je suis dans run" << std::endl;
    for (const auto& row : display_grid.get_grid()) {
        for (const auto& cell : row) {
            std::cout << (cell ? '1' : '0') << " ";
        }
        std::cout << std::endl;
    }
}





