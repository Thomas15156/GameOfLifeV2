//
// Created by benjamin Bourlet on 04/12/2024.
//

#include "V_Graphics.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <ostream>

Graphics::Graphics(Grid& display_grid)
: display_grid(display_grid), window(sf::VideoMode(800, 600), "Conway's Game of Life"), last_update(sf::seconds(0.2f)) {}

void Graphics::run_display()
{
    int window_width = window.getSize().x;
    int window_height = window.getSize().y;
    int cell_size = 10;
    int new_rows = window_width / cell_size;
    int new_cols = window_height / cell_size;

    display_grid.resize(new_rows, new_cols);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        if (clock.getElapsedTime() >= last_update)
        {
            display_grid.next_generation();
            if (display_grid.is_stable()) {printf("je suis dans stable"); window.close();}
            clock.restart();
        }

        window.clear();
        for (size_t i = 0; i < display_grid.get_grid().size(); i++){
            for (size_t j = 0; j < display_grid.get_grid()[i].size(); j++){
                sf::RectangleShape cell(sf::Vector2f(cell_size,cell_size));
                cell.setPosition(j * cell_size,i* cell_size);
                cell.setFillColor(display_grid.get_grid()[i][j] == 0 ? sf::Color::Black : sf::Color::White);
                window.draw(cell);
            }
        }

        window.display();
    }


}
