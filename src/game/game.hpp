#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "../cam/cam.hpp"
#include "../grid/grid.hpp"
#include "../input_handler/input_handler.hpp"
#include "../ui/ui.hpp"
#include "../window/window.hpp"

class Game {
public:
  void run(void);

private:
  Cam camera;
  Window win;
  Grid g;
  Input_handler input_handler;
  UI ui;
  bool pause = true;

private:
  void init(void);
  void draw(void);
  void handle_input(void);
  void update(void);
  void game_input(void);
};

#endif
