//
// Created by benjamin Bourlet on 03/12/2024.
//

#ifndef V_GRAPHICS_H
#define V_GRAPHICS_H

#include "V_Display.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>

class Graphics : public Display{
private:
    std::vector<std::vector<int>> get_grid;
    sf::RenderWindow window;

public:
    Graphics(const std::vector<std::vector<int>>& grid);
    void show() override;
};



#endif //V_GRAPHICS_H
