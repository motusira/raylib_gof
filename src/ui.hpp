#ifndef __UI_HPP__
#define __UI_HPP__

#include "grid.hpp"
#define RAYGUI_IMPLEMENTATION

class UI {
public:
  void init();
  void draw(Grid &g);
};

#endif