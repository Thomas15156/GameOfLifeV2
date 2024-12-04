//
// Created by benjamin Bourlet on 03/12/2024.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include "M_Grid.h"


class Display {
public:
    virtual ~Display() = default;
    virtual void run_display() = 0;

};

Display* choose_display_mode(const std::string& display_mode, Grid& display_grid);

#endif //DISPLAY_H
