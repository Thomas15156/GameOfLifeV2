#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <memory>
#include "M_Grid.h"
#include "File.h"

class Display {
public:
    virtual ~Display() = default;
    virtual void run_display() = 0;
    virtual void run() = 0; //Méthode virtuelle pure run
};

std::unique_ptr<Display> choose_display_mode(const std::string& display_mode, Grid& display_grid, File& file, int update_interval); // Ajouter update_interval

#endif //DISPLAY_H