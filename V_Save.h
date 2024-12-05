//
// Created by benjamin Bourlet on 05/12/2024.
//

#ifndef V_SAVE_H
#define V_SAVE_H
#include "V_Display.h"


class Save : public Display{
  private:
    Grid grid;
  public:
    Save(Grid& display_grid);
    void save_to_file(const std::string filename, int cycle);
    void run_display() override;
};



#endif //V_SAVE_H
