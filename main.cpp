#include "M_Grid.h"
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>

#include "test_view.h"

int main() {
    // Simulez la grille fournie par votre collègue
    std::vector<std::vector<int>> get_temp_grid = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    Grid grid(get_temp_grid);

    // Créez une instance de View et affichez la grille
    test_view view(grid.get_grid());
    view.displayGrid();

    for (int cycle = 1; cycle < 10; ++cycle) {
        grid.next_generation();
        view.updateGrid(grid.get_grid());
        std::cout << "Next generation : " << cycle << " \n";
        view.displayGrid();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
