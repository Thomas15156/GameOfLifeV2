//
// Created by benjamin Bourlet on 03/12/2024.
//

#include "V_Display.h"
#include "V_Console.h"
#include "V_Graphics.h"
#include <stdexcept>

Display* get_display(const std::string& display_mode, const std::vector<std::vector<int>>& get_grid)
{
    if (display_mode == "console")
    {return new Console(get_grid);}
    else if (display_mode == "graphics")
    {return new Graphics(get_grid);}
    else {throw std::invalid_argument("Invalid display mode");}
}