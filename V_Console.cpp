#include "V_Console.h"
#include <iostream>
#include <ostream>
#include <thread>
#include <chrono>

Console::Console(Grid& display_grid, File& file) : display_grid(display_grid), file(file), generation(0) {}

void Console::run_display() {
    for (const auto& row : display_grid.get_grid()) {
        for (const auto& cell : row) {
            std::cout << (cell ? '1' : '0') << " ";
        }
        std::cout << std::endl;
    }
    file.Savefile(++generation); // Sauvegarde de la génération actuelle
}

void Console::run() {
    for (int cycle = 0;; ++cycle) {
        display_grid.next_generation();
        if (display_grid.is_stable()) {
            std::cout << "Stable" << std::endl;
            std::cout << "=============================\n";
            std::cout << "Fin du Programme" << std::endl;
            std::cout << "=============================\n";
            break;
        } else {
            std::cout << "=============================\n";
            std::cout << "Next generation: " << cycle << std::endl;
            std::cout << "=============================\n";
            run_display();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}
