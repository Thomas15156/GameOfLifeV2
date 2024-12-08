#include "V_Graphic.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Graphic::Graphic(Grid& display_grid, int update_interval)
    : display_grid(display_grid), window(sf::VideoMode(display_grid.get_grid()[0].size() * 10,
        display_grid.get_grid().size() * 10), "Game of Life"), cell_size(10), update_interval(update_interval) {}

void Graphic::render_grid() {
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cell_size - 1.0f, cell_size - 1.0f));
    const auto& grid = display_grid.get_grid();
    for (size_t y = 0; y < grid.size(); ++y) {
        for (size_t x = 0; x < grid[0].size(); ++x) {
            switch (grid[y][x]) {
                case 1:
                    cell.setFillColor(sf::Color::Black);
                    break;
                case 2:
                    cell.setFillColor(sf::Color::Red);
                    break;
                case 3:
                    cell.setFillColor(sf::Color::Green);
                    break;
                default:
                    cell.setFillColor(sf::Color::White);
                    break;
            }
            cell.setPosition(x * cell_size, y * cell_size);
            window.draw(cell);
        }
    }
    window.display();
}

void Graphic::run_display() {
    render_grid();
}

void Graphic::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (clock.getElapsedTime().asMilliseconds() >= update_interval) {
            display_grid.next_generation();
            if (display_grid.is_stable()) {
                std::cout << "Grid is stable, closing window." << std::endl;
                window.close();
            }
            clock.restart();
        }

        run_display();
    }
}