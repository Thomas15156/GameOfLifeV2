//
// Created by benjamin Bourlet on 04/12/2024.
//

#include "V_Graphics.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <ostream>

Graphics::Graphics(Grid& display_grid)
: display_grid(display_grid), window(sf::VideoMode(800, 600), "Conway's Game of Life") {}

void Graphics::run_display()
{
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();

        int cell_size = 10;
        for (size_t i = 0; i < display_grid.get_grid().size(); i++){
            for (size_t j = 0; j < display_grid.get_grid()[i].size(); j++){
                sf::RectangleShape cell(sf::Vector2f(cell_size,cell_size));
                cell.setPosition(i* cell_size,j* cell_size);
                cell.setFillColor(display_grid.get_grid()[i][j] == 0 ? sf::Color::Black : sf::Color::White);
                window.draw(cell);
            }
        }
        window.display();
    }


}
