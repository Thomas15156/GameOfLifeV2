//
// Created by benjamin Bourlet on 04/12/2024.
//
#include "V_Display.h"
#include "V_Console.h"
#include "V_Graphics.h"
#include <stdexcept>



Display* choose_display_mode(const std::string& display_mode, Grid& display_grid)
{
    if (display_mode == "console")
        {return new Console(display_grid);}
    else if (display_mode == "graphics")
        {return new Graphics(display_grid);}
    else
    {
        throw std::invalid_argument("Invalid display mode");
    }
    return nullptr;
}
