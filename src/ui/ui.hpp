#ifndef __UI_HPP__
#define __UI_HPP__

#include "../grid/grid.hpp"
#define RAYGUI_IMPLEMENTATION

class UI {
public:
  void init(const Vector2 &window_size);
  void update(const Vector2 &window_size);
  void draw(const Vector2 &window_size, Grid &g);

private:
  Rectangle viewport;
};

#endif
