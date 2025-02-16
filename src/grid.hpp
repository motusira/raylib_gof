#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <vector>
#include <raylib.h>

class Grid {
public:
  int width = 64;
  int height = 64;
  int cell_size = 32;
  double prev_time = GetTime();
  double update_interval = 0.1;
  bool pause = false;
  std::vector<int> cells;
  Grid();

  void draw();
  int get_new_pos(int dx, int dy, int pos);

  int get_width();
  int get_height();

  int check_neib(int pos);
  bool is_alive(int pos);
  void simulate();

  void update();

  void handle_input(Camera2D &camera);
};

#endif