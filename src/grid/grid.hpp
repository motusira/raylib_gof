#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <raylib.h>
#include <vector>

class Grid {
public:
  void init(void);
  void draw(void);
  void resize_grid(void);
  void clear_grid(void);
  int get_grid_size(void);
  int get_cell_size(void);
  double get_update_interval(void);
  void set_grid_size(int n);
  void set_cell_size(int n);
  void set_update_interval(double n);
  bool is_alive(int pos);
  int get_new_pos(int dx, int dy, int pos);
  int count_neibs(int pos);
  void simulate(void);
  void update(void);
  void set_cell_alive(int x, int y);
  void set_cell_unalive(int x, int y);

private:
  int grid_size = 64;
  int cell_size = 32;
  std::vector<char> cells;
  double update_interval = 0.1;
  double prev_time;
};

#endif
