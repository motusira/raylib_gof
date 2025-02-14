#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <vector>

struct Cell {
  int alive;
};

class Grid {
public:
  int width{64};
  int height{64};
  int cell_size{16};
  std::vector<Cell> cells;

  Grid();

  void draw();

  bool is_alive(int pos);

  int get_new_pos(int dx, int dy, int pos);

  int check_neib(int pos);

  void simulate();
};

#endif