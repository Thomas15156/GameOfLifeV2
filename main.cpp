#include "M_Grid.h"
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>

#include "V_Display.h"
#include "File.h"
#include "V_Interface.h"


int main() {
    File file;
    Interface interface;
    file.Openfile();
    file.InitGrid();
    interface.ChooseMode();

    // Simulez la grille fournie par votre collègue
    //std::string get_display_mode = "graphics";




    Grid grid(file.temp_grid());
    // Créez une instance de View et affichez la grille
    Display* get_display = choose_display_mode(interface.get_display_mode(), grid);
    get_display -> run_display();

    for (int cycle = 0; cycle < 20; ++cycle) {
        grid.next_generation();
        if (grid.is_stable())
        {
            std::cout << "stable" << std::endl;
            return 0;
        }
        std::cout << "Next generation : " << cycle << " \n";
        get_display -> run_display();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }


    return 0;
}
