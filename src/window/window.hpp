#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "raylib.h"

class Window {
public:
  void init(void);
  void update(void);
  bool is_resized(void);
  void draw_start(void);
  void draw_end(void);
  ~Window() { CloseWindow(); }
  Vector2 get_size(void);

private:
  Vector2 size;
};

#endif
