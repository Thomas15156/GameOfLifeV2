//
// Created by benjamin Bourlet on 03/12/2024.
//

#include "V_Console.h"
#include <iostream>

Console::Console(const std::vector<std::vector<int>>& grid)
    : get_grid(grid) {}

void Console::show(){
    for (const auto& row : get_grid){
        for (const auto& col : row){
            std::cout << col << " ";
        }
    }
    std::cout << std::endl;
}
