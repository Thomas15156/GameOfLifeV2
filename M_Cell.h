#ifndef M_CELL_H
#define M_CELL_H

class Cell {
public:
  Cell(int state = 0);
  int get_state() const;
  void set_state(int state);
  int next_state(int live_neighbors) const;

private:
  int state;
};



#endif //M_CELL_H
