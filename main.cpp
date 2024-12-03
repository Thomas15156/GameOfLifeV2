#include <iostream>

#include "V_Display.h"

int main()
{
    std::string get_display_mode = "graphics";
    std::vector<std::vector<int>> get_grid = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1}};

    Display* display = get_display(get_display_mode, get_grid);
    display -> show();

    delete display;
    return 0;
}
