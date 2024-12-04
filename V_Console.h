//
// Created by benjamin Bourlet on 03/12/2024.
//

#ifndef V_CONSOLE_H
#define V_CONSOLE_H
#include "V_Display.h"


class Console : public Display {
protected:
    Grid& display_grid;

public:
    Console(Grid& display_grid);
    void run_display() override;

};

#endif //CONTROLE_H