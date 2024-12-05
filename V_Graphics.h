#ifndef V_GRAPHICS_H
#define V_GRAPHICS_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "V_Display.h"

class Graphics : public Display {
protected:
    Grid& display_grid;
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time last_update;
    int cell_size;
    int update_interval; // Ajouter un membre pour l'intervalle de mise à jour

public:
    Graphics(Grid& display_grid, int update_interval); // Modifier le constructeur
    void run_display() override;
    void render_grid();
    void initialize_grid();
    void backgound_grid();
    void run() override; // Redéfinition de la méthode run
};

#endif //V_GRAPHICS_H