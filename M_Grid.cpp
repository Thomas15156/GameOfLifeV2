#include "M_Grid.h"
#include <algorithm>

Grid::Grid(const std::vector<std::vector<int>>& initial_grid, bool is_toroidal)
    : rows(initial_grid.size()), cols(initial_grid[0].size()), is_toroidal(is_toroidal) {
    grid.resize(rows, std::vector<Cell>(cols));
    next_grid.resize(rows, std::vector<Cell>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j].set_state(initial_grid[i][j]);
            next_grid[i][j].set_state(initial_grid[i][j]);
        }
    }
}

void Grid::next_generation() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j].get_state() == 2 || grid[i][j].get_state() == 3) {
                next_grid[i][j].set_state(grid[i][j].get_state());
            } else {
                int live_neighbors = count_live_neighbors(i, j);
                next_grid[i][j].set_state(grid[i][j].next_state(live_neighbors));
            }
        }
    }
    grid.swap(next_grid);
}

int Grid::count_live_neighbors(int row, int col) const {
    int count_live = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int new_row = row + i;
            int new_col = col + j;

            if (is_toroidal) {
                new_row = (new_row + rows) % rows;
                new_col = (new_col + cols) % cols;
            } else {
                if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols) continue;
            }

            int state = grid[new_row][new_col].get_state();
            if (state == 1 || state == 3) {
                count_live += 1;
            }
        }
    }
    return count_live;
}

std::vector<std::vector<int>> Grid::get_grid() const {
    std::vector<std::vector<int>> grid_state(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid_state[i][j] = grid[i][j].get_state();
        }
    }
    return grid_state;
}

bool Grid::is_stable() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j].get_state() != next_grid[i][j].get_state()) {
                return false;
            }
        }
    }
    return true;
}