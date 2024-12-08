#include "File.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

File::File() : row(0), col(0), filename("") {}

void File::Openfile() {
    std::cout << "=============================\n";
    std::cout << "  Welcome to the Game of Life\n";
    std::cout << "=============================\n";
    std::cout << "Enter file name: ";
    std::getline(std::cin, filename);
    foldername = filename + "_out";
    std::cout << "=============================\n";
    std::cout << "Verification: " << filename << std::endl;

    if (filename.substr(filename.find_last_of(".") + 1) != "txt") {
        std::cerr << "Error: The file is not a .txt file." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        std::exit(EXIT_FAILURE);
    } else {
        std::cout << "File opened successfully." << std::endl;
        std::cout << "=============================\n";
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

    grid.resize(row, std::vector<int>(col));

    for (int i = 0; i < row; ++i) {
        if (std::getline(file, line)) {
            std::istringstream iss(line);
            for (int j = 0; j < col; ++j) {
                int num;
                if (!(iss >> num) || num < 0 || num > 3) {
                    std::cerr << "Error: Invalid value found." << std::endl;
                    std::exit(EXIT_FAILURE);
                }
                grid[i][j] = num;
            }
        }
    }
}

std::string File::get_filename() const {
    return filename;
}

std::vector<std::vector<int>> File::temp_grid() const {
    return grid;
}

int File::CreateFolder() {
    foldername = std::filesystem::path(filename).stem().string() + "_out";
    std::filesystem::path dir = foldername;
    try {
        if (std::filesystem::create_directory(dir)) {
            std::cout << "Folder successfully created: " << dir << std::endl;
        } else {
            std::cout << "The folder already exists or could not be created." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error while creating the folder: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}

int File::Savefile(int generation) {
    std::ostringstream filename;
    filename << foldername << "/gen_" << generation << ".txt";
    std::ofstream outfile(filename.str());

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create the file." << std::endl;
        return -1;
    }

    for (const auto& row : grid) {
        for (const auto& cell : row) {
            outfile << cell << " ";
        }
        outfile << "\n";
    }

    outfile.close();
    return 0;
}