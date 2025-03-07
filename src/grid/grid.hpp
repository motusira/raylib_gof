#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <raylib.h>
#include <vector>

class Grid {
public:
  void init(void);
  void draw(void);
  void resize_grid(void);
  int get_grid_size(void);
  int get_cell_size(void);
  void set_grid_size(int n);
  void set_cell_size(int n);

private:
  int grid_size = 64;
  int cell_size = 32;
  std::vector<char> cells;
  double update_interval = 0.1;
  double prev_time;

  int res;
  int state_texture;
};

#endif