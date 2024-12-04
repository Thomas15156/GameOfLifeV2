#include "M_Grid.h"
#include <iostream>

Grid::Grid(const std::vector<std::vector<int>>& get_temp_grid)
    :rows(get_temp_grid.size()), cols(get_temp_grid[0].size())
{
    grid.resize(rows, std::vector<Cell>(cols));
    next_grid.resize(rows, std::vector<Cell>(cols));
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
        {
            grid[i][j].set_state(get_temp_grid[i][j]);
            next_grid[i][j].set_state(get_temp_grid[i][j]);
        }
    }
}

void Grid::next_generation()
{
    next_grid = grid;
    std::vector<std::vector<Cell>> new_grid = grid;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            int live_neighbours = count_live_neighbors(i, j);
            new_grid[i][j].set_state(grid[i][j].next_state(live_neighbours));
        }
    }
    grid = new_grid;
}

int Grid::count_live_neighbors(int row, int col)
{
    int count_live = 0;

    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if (i == 0 && j == 0) continue;

            int new_row = (row + i + rows) % rows;
            int new_col = (col + j + cols) % cols;

            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols)
            {count_live += grid[new_row][new_col].get_state();}
        }
    }
    return count_live;
}

std::vector<std::vector<int>>& Grid::get_grid() const
{
    static std::vector<std::vector<int>> grid_state(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
        {
            grid_state[i][j] = grid[i][j].get_state();
        }
    }
    return grid_state;
}

void Grid::resize(int new_rows, int new_cols)
{
    std::vector<std::vector<Cell>> new_grid(new_rows, std::vector<Cell>(new_cols));

    for (int i = 0; i < std::min(rows, new_rows); i++)
    {
        for (int j = 0; j < std::min(cols, new_cols); j++)
        {
            new_grid[i][j].set_state(grid[i][j].get_state());
        }
    }
    rows = new_rows;
    cols = new_cols;
    grid = new_grid;
    next_grid = new_grid;
}



bool Grid::is_stable() const
{
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (grid[i][j].get_state() != next_grid[i][j].get_state())
            {
                return false;
            }
        }
    }
    return true;
}
