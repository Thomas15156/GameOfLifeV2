#ifndef TEST_VIEW_H
#define TEST_VIEW_H
#include <vector>


class test_view {

public:
    test_view(const std::vector<std::vector<int>>& grid);
    void displayGrid() const;
    void updateGrid(const std::vector<std::vector<int>>& new_grid);

private:
    std::vector<std::vector<int>> grid;

};

#endif //TEST_VIEW_H