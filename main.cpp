#include "M_Grid.h"
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>

#include "test_view.h"
#include "V_Display.h"
//#include "V_Graphics.h"


int main() {
    printf("je commennce le main");
    // Simulez la grille fournie par votre collègue
    std::string get_display_mode = "graphics";
    std::vector<std::vector<int>> get_temp_grid = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };




    Grid grid(get_temp_grid);

    // Créez une instance de View et affichez la grille
    test_view view(get_temp_grid);
    printf("avant display");
    Display* get_display = choose_display_mode(get_display_mode, grid);
    std::cout << "je vais dans run" << std::endl;
    get_display -> run_display();

    for (int cycle = 0; cycle < 10; ++cycle) {
        grid.next_generation();
        view.updateGrid(grid.get_grid());
        if (grid.is_stable())
        {
            std::cout << "stable" << std::endl;
            return 0;
        }
        std::cout << "Next generation : " << cycle << " \n";
        //view.displayGrid();
        get_display -> run_display();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }


    return 0;
}
