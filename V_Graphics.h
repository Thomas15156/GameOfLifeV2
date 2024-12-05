//
// Created by benjamin Bourlet on 04/12/2024.
//

#ifndef V_GRAPHICS_H
#define V_GRAPHICS_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "V_Display.h"


class Graphics : public Display{
protected:
    Grid& display_grid;
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time last_update;
    int cell_size;

public:
    Graphics(Grid& display_grid);
    void run_display() override;
    void initialize_grid();
    void render_grid();
    void backgound_grid();
};



#endif //V_GRAPHICS_H
