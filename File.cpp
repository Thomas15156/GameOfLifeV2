#include "File.h"
#include <iostream>
#include <fstream>
#include <sstream>

File::File() : row(0), col(0), filename("") {}

void File::Openfile() {

    std::cout << "Enter file name:";

    while (true) {
        std::cin >> filename;
        // Vérifier si le fichier peut être ouvert
        std::ifstream file(filename);
        if (file.is_open()) {
            file.close();
            break;
        } else {
            std::cerr << "Unable to open file: " << filename << ". Please try again." << std::endl;
        }
    }
}

void File::InitGrid() {
    if (filename.empty()) {
        std::cerr << "No valid file name provided." << std::endl;
        return;
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    // Lire la première ligne pour obtenir les dimensions de la grille
    if (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> row >> col;
    }

    // Redimensionner la grille
    grid.resize(row, std::vector<int>(col));

    for (int i = 0; i < row; ++i) {
        if (std::getline(file, line)) {
            std::istringstream iss(line);
            for (int j = 0; j < col; ++j) {
                iss >> grid[i][j];
            }
        }
    }

    file.close();
}

std::vector<std::vector<int>> File::get_temp_grid() const {
    return grid;
}