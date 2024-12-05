#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>

class File {
public:
    File();
    void Openfile();
    void InitGrid();
    int CreateFolder();
    void ClearFolder(); // Nouvelle méthode pour vider le dossier
    int Savefile(int generation);
    std::string get_filename() const;
    std::vector<std::vector<int>> temp_grid() const;

private:
    int row, col;
    std::string filename;
    std::string foldername;
    std::vector<std::vector<int>> grid;
};

#endif // FILE_H