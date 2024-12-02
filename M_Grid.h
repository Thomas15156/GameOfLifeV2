//
// Created by benjamin Bourlet on 02/12/2024.
//
#include <vector>

#ifndef M_GRID_H
#define M_GRID_H



class Grid {
private:
  std::vector<std::vector<int>> grid;
  std::vector<std::vector<int>> next_grid;
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
