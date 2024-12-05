#include "File.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>


File::File() : row(0), col(0), filename("") {}

void File::Openfile() {
    std::cout << "Enter file name: ";
    std::getline(std::cin, filename);
    std::cout << "Vérification: " << filename << std::endl;
    std::cout << std::endl;

    // Vérification type de fichier
    if (filename.substr(filename.find_last_of(".") + 1) != "txt") {
        std::cerr << "Error: The file is not a .txt file." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // Vérification ouverture
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        std::exit(EXIT_FAILURE);
    } else {
        std::cout << "File opened successfully." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        file.close();
    }
}

void File::InitGrid() {

    std::ifstream file(filename);
    std::string line;
    if (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> row >> col;
        if (row <= 0 || col <= 0) {
            std::cerr << "Error: Row and column values must be greater than 0." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    // Redimensionner la grille
    grid.resize(row, std::vector<int>(col));

    // Lecture des données et insertion
    for (int i = 0; i < row; ++i) {
        if (std::getline(file, line)) {
            std::istringstream iss(line);
            for (int j = 0; j < col; ++j) {
                std::string value;
                iss >> value;

                // Vérification que la valeur est un chiffre
                if (!std::isdigit(value[0]) || value.size() > 1) {
                    std::cerr << "Error: Non-numeric value found." << std::endl;
                    std::exit(EXIT_FAILURE);
                }

                int num = std::stoi(value);

                // Vérification que la valeur est entre 0 et 3
                if (num < 0 || num > 3) {
                    std::cerr << "Error: Value out of range (0-3)." << std::endl;
                    std::exit(EXIT_FAILURE);
                }

                grid[i][j] = num;
            }
        }
    }

    file.close();
}

std::string File::get_filename() {return filename;}



std::vector<std::vector<int>> File::temp_grid() const {
    return grid;
}