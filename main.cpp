#include "M_Grid.h"
#include <thread>
#include <chrono>
#include <iostream>

#include "V_Display.h"
#include "File.h"
#include "V_Interface.h"
#include "V_Console.h"
#include "V_Graphics.h"

int main() {
    File file;
    Interface interface;
    file.Openfile();
    file.InitGrid();
    file.CreateFolder();
    interface.ChooseMode();
    bool is_toroidal = interface.ChooseToroidal();
    int update_interval = interface.ChooseUpdateInterval(); // Obtenir l'intervalle de mise à jour

    Grid grid(file.temp_grid(), is_toroidal);
    std::unique_ptr<Display> display = choose_display_mode(interface.get_display_mode(), grid, file, update_interval); // Passer l'intervalle de mise à jour

    display->run();

    return 0;
}