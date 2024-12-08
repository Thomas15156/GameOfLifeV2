#ifndef V_CONSOLE_H
#define V_CONSOLE_H
#include "V_Display.h"
#include "File.h"

class Console : public Display {
protected:
    Grid& display_grid;
    File& file;
    int generation;

public:
    Console(Grid& display_grid, File& file);
    void run_display() override;
    void run() override;
};

#endif //V_CONSOLE_H