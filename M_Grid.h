#ifndef M_GRID_H
#define M_GRID_H

#include "M_Cell.h"
#include <vector>

class Grid {
private:
    std::vector<std::vector<Cell>> grid;
    std::vector<std::vector<Cell>> next_grid;
    int rows;
    int cols;

public:
    Grid(const std::vector<std::vector<int>>& get_temp_grid );
    void next_generation();
    int count_live_neighbors(int row, int col);
    const std::vector<std::vector<int>>& get_grid() const;
    bool is_stable() const;
};

#endif //M_GRID_H