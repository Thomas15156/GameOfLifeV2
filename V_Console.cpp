#include "V_Console.h"
#include <iostream>
#include <thread>
#include <chrono>

Console::Console(Grid& display_grid, File& file) : display_grid(display_grid), file(file), generation(0) {}

void Console::run_display() {
    const auto& grid = display_grid.get_grid();
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << (cell ? '1' : '0') << " ";
        }
        std::cout << std::endl;
    }
    file.Savefile(++generation);
}

void Console::run() {
    file.CreateFolder();

    for (int cycle = 1; cycle <= 100; ++cycle) {
        display_grid.next_generation();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (display_grid.is_stable()) {
            std::cout << "Stable" << std::endl;
            std::cout << "=============================\n";
            std::cout << "End of the Program" << std::endl;
            std::cout << "=============================\n";
            break;
        } else {
            std::cout << "=============================\n";
            std::cout << "Next generation: " << cycle << std::endl;
            std::cout << "=============================\n";
            run_display();
        }

        if (cycle == 100) {
            std::cout << "=============================\n";
            std::cout << "100 generations completed.\n";
            std::cout << "=============================\n";
        }
    }
}