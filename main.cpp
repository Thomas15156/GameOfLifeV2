#include "File.h"
#include "V_Interface.h"
#include "M_Grid.h"
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include "test_view.h"

int main() {
    File file;
    file.Openfile();
    file.InitGrid();

    // Récupérez la grille temporaire
    std::vector<std::vector<int>> temp_grid = file.temp_grid();

    Grid grid(temp_grid);

    // Créez une instance de View et affichez la grille
    test_view view(grid.get_grid());
    view.displayGrid();

    for (int cycle = 1; cycle < 10; ++cycle) {
        grid.next_generation();
        view.updateGrid(grid.get_grid());
        if (grid.is_stable())
        {
            std::cout << "stable" << std::endl;
            return 0;
        }
        std::cout << "Next generation : " << cycle << " \n";
        view.displayGrid();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}