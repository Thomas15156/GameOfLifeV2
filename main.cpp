#include "M_Grid.h"
#include "V_Display.h"
#include "File.h"
#include "V_Interface.h"
#include <memory>
#include <iostream>

int main() {
    File file;
    Interface interface;
    file.Openfile();
    file.InitGrid();
    interface.ChooseMode();

    bool is_toroidal = interface.ChooseToroidal();
    int update_interval = (interface.get_display_mode() == "graphics") ? interface.get_update_interval() : 10;

    Grid grid(file.temp_grid(), is_toroidal);
    std::unique_ptr<Display> display = choose_display_mode(interface.get_display_mode(), grid, file, update_interval);

    display->run();

    return 0;
}