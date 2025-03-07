#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "../window/window.hpp"
#include "../cam/cam.hpp"
#include "../grid/grid.hpp"
#include "../ui/ui.hpp"
#include "../input_handler/input_handler.hpp"

class Game {
  public:
  void run(void);
  private:
  Cam camera;
  Window win;
  Grid g;
  Input_handler input_handler;
  UI ui;
  private:
  void init(void);
  void draw(void);
  void handle_input(void);
  void update(void);

};

#endif