//
// Created by benjamin Bourlet on 02/12/2024.
//

#include "M_Grid.h"

Grid::Grid(const std::vector<std::vector<int>>& get_temp_grid)
    : grid(get_temp_grid), next_grid(get_temp_grid), rows(get_temp_grid.size()), cols(get_temp_grid[0].size()) {}
// prends les parametres de la grille initialiser et les donnes au grilles crée et parametre des lignes et colonnes

void Grid::next_generation() {
  next_grid = grid;
  std::vector<std::vector<int>> new_grid = grid;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      int live_neighbors = count_live_neighbors(i, j);
      new_grid[i][j] = (grid[i][j] == 1 && (live_neighbors == 2 || live_neighbors == 3)) || (grid[i][j] == 0 && live_neighbors == 3) ? 1 : 0;
    }
  }
  grid = new_grid;
}

int Grid::count_live_neighbors(int row, int col) {
  int live_neighbors = 0;

  for( int i = -1; i <= 1; ++i) {
    for( int j = -1; j <= 1; ++j) {
      if( i == 0 && j == 0 ) continue;

      int new_row = row + i;
      int new_col = col + j;

      if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols) {
        live_neighbors += grid[new_row][new_col];
      }
    }
  }
  return live_neighbors;
}

const std::vector<std::vector<int>>& Grid::get_grid() const {
  return grid;
}

bool Grid::is_stable() const {
  return grid == next_grid;
}