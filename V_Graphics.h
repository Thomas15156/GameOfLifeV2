#ifndef V_GRAPHICS_H
#define V_GRAPHICS_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "V_Display.h"
#include "M_Grid.h"

class Graphics : public Display {
protected:
    Grid& display_grid;
    sf::RenderWindow window;
    sf::Clock clock;
    int cell_size;
    int update_interval;

public:
    Graphics(Grid& display_grid, int update_interval);
    void run_display() override;
    void render_grid();
    void run() override;
};

#endif // V_GRAPHICS_H