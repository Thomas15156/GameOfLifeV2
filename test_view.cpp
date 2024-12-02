//
// Created by benjamin Bourlet on 02/12/2024.
//

#include "test_view.h"

#include <iostream>


test_view::test_view(const std::vector<std::vector<int>>& grid) : grid(grid) {}

void test_view::displayGrid() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << (cell ? '1' : '0') << " ";
        }
        std::cout << std::endl;
    }
}

void test_view::updateGrid(const std::vector<std::vector<int>>& new_grid) {
    grid = new_grid;
}


