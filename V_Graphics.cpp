//
// Created by benjamin Bourlet on 03/12/2024.
//

#include "V_Graphics.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Graphics::Graphics(const std::vector<std::vector<int>>& grid)
    : get_grid(grid), window(sf::VideoMode(800,600), "Conway's Game of Life") {}

void Graphics::show()
{
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::White);

        int cell_size = 10;
        for (size_t i = 0; i < get_grid.size(); i++){
            for (size_t j = 0; j < get_grid[i].size(); j++)
            {
                sf::RectangleShape cell(sf::Vector2f(cell_size,cell_size));
                cell.setPosition(j * cell_size, i * cell_size);
                cell.setFillColor(get_grid[i][j] == 0 ? sf::Color::White : sf::Color::Black);
                window.draw(cell);
            }
        }
        window.display();
    }
}

