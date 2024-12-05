#include "V_Graphics.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

Graphics::Graphics(Grid& display_grid, int update_interval)
: display_grid(display_grid), window(sf::VideoMode(800, 600), "Game of Life"), last_update(sf::milliseconds(update_interval)), cell_size(10), update_interval(update_interval) {}

void Graphics::backgound_grid(){
    sf::Color gridColor(200, 200, 200); // Light grey color for the grid lines
    for (int x = 0; x <= window.getSize().x; x += cell_size) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, 0), gridColor),
            sf::Vertex(sf::Vector2f(x, window.getSize().y), gridColor)
        };
        window.draw(line, 2, sf::Lines);
    }
    for (int y = 0; y <= window.getSize().y; y += cell_size) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0, y), gridColor),
            sf::Vertex(sf::Vector2f(window.getSize().x, y), gridColor)
        };
        window.draw(line, 2, sf::Lines);
    }
}

void Graphics::initialize_grid() {
    std::srand(std::time(0));
    for (int y = 0; y < display_grid.get_grid().size(); ++y) {
        for (int x = 0; x < display_grid.get_grid()[0].size(); ++x) {
            display_grid.get_grid()[y][x] = std::rand() % 2;  // Randomly initialize cells as alive or dead
        }
    }
}

void Graphics::render_grid(){
    window.clear();
    backgound_grid();
    sf::RectangleShape cell(sf::Vector2f(cell_size - 1.0f, cell_size - 1.0f));
    for (int y = 0; y < display_grid.get_grid().size(); ++y) {
        for (int x = 0; x < display_grid.get_grid()[0].size(); ++x) {
            if (display_grid.get_grid()[y][x] == 1) {
                cell.setFillColor(sf::Color::Black);
            } else if (display_grid.get_grid()[y][x] == 2) {
                cell.setFillColor(sf::Color::Red); // Obstacle mort
            } else if (display_grid.get_grid()[y][x] == 3) {
                cell.setFillColor(sf::Color::Green); // Obstacle vivant
            } else {
                cell.setFillColor(sf::Color::White);
            }
            cell.setPosition(x * cell_size, y * cell_size);
            window.draw(cell);
        }
    }
    window.display();
}

void Graphics::run_display() {
    render_grid();
}

void Graphics::run() {
    int window_width = window.getSize().x;
    int window_height = window.getSize().y;
    int new_rows = window_height / cell_size;
    int new_cols = window_width / cell_size;

    display_grid.resize(new_rows, new_cols);
    initialize_grid();

    sf::Clock clock; // Déclarez le clock ici pour mesurer le temps écoulé

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (clock.getElapsedTime().asMilliseconds() >= update_interval) { // Utiliser l'intervalle de mise à jour
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