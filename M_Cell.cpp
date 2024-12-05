#include "M_Cell.h"

Cell::Cell(int state) : state(state) {}

int Cell::get_state() const {return state;}

void Cell::set_state(int state) {this -> state = state;}

int Cell::next_state(int live_neighbours) const
{
  if (state == 1 && (live_neighbours == 2 || live_neighbours == 3))
  {return 1;} // survie de la cellule
  else if (state == 0 && live_neighbours == 3)
  {return 1;}
  else {return 0;}
}