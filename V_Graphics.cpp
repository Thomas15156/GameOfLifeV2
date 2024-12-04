//
// Created by benjamin Bourlet on 04/12/2024.
//

#include "V_Graphics.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <ostream>

Graphics::Graphics(Grid& display_grid)
: display_grid(display_grid), window(sf::VideoMode(800, 600), "Conway's Game of Life"), last_update(sf::seconds(0.9f)) {}

void Graphics::run_display()
{
    int window_width = window.getSize().x;
    int window_height = window.getSize().y;
    int rows = display_grid.get_grid().size();
    int cols = display_grid.get_grid()[0].size();
    int cell_size = std::min(window_width / cols, window_height / rows);

    window.setSize(sf::Vector2u(cols * cell_size, rows * cell_size));


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
        int cell_size = window.getSize().x / display_grid.get_grid()[0].size();
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
