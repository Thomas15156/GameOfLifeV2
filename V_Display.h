//
// Created by benjamin Bourlet on 03/12/2024.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>

class Display {
  public:
    virtual ~Display() = default;
    virtual void show() = 0;
};

Display* get_display(const std::string& display_mode, const std::vector<std::vector<int>>& get_grid);

#endif //DISPLAY_H
