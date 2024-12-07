#include "M_Cell.h"

Cell::Cell(int state) : state(state) {}

int Cell::get_state() const {
  return state;
}

void Cell::set_state(int state) {
  this->state = state;
}

int Cell::next_state(int live_neighbors) const {
  if (state == 2 || state == 3) {
    return state;
  } else if (state == 1) {
    if (live_neighbors == 2 || live_neighbors == 3) {
      return 1;
    } else {
      return 0;
    }
  } else if (state == 0) {
    if (live_neighbors == 3) {
      return 1;
    } else {
      return 0;
    }
  }
  return state;
}