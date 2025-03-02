#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "screen.hpp"
#include "grid.hpp"
#include "ui.hpp"

class Game {
  Screen screen;
  Grid grid;
  UI ui;
  void init();
  void handle_input();
  void update();
  void draw();

public:
  void run();
};

#endif