#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <raylib.h>
#include "grid.hpp"

class Game {

  int width{800};
  int height{450};
  Camera2D camera;
  Grid grid;
  bool pause{true};
  double prev_time;
  double update_interval{0.1};
  void init();
  void process_input();
  void draw();
  void update();
  void deinit();

public:
  void run();
};

#endif