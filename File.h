#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>

class File {
public:
    File();
    void Openfile();
    void InitGrid();
    std::vector<std::vector<int>> temp_grid() const; // Méthode pour obtenir la grille
private:
    int row, col;
    std::string filename;
    std::vector<std::vector<int>> grid;
};

#endif // FILE_H