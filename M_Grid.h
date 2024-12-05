#include "M_Cell.h"
#include <vector>

#ifndef M_GRID_H
#define M_GRID_H



class Grid {
private:
    std::vector<std::vector<Cell>> grid;
    std::vector<std::vector<Cell>> next_grid;
    int rows;
    int cols;
    bool is_toroidal;


public:
    Grid(const std::vector<std::vector<int>>& get_temp_grid, bool is_toroidal = false);
    void next_generation();
    int count_live_neighbors(int row, int col) const;
    void resize(int new_rows, int new_cols);
    std::vector<std::vector<int>>& get_grid() const;
    bool is_stable() const;
};



#endif //M_GRID_H