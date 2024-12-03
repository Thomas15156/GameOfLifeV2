//
// Created by benjamin Bourlet on 03/12/2024.
//

#ifndef V_CONSOLE_H
#define V_CONSOLE_H

#include "V_Display.h"
#include <vector>

class Console : public Display{
private:
    std::vector<std::vector<int>> get_grid;

public:
    Console(const std::vector<std::vector<int>>& grid);
    void show() override;
};



#endif //V_CONSOLE_H
