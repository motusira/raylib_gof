#ifndef __SCREEN_HPP__
#define __SCREEN_HPP__

#include "raylib.h"

class Screen {
public:
  Vector2 size;
  Camera2D camera;
  Vector2 camera_move_speed = {0.0f, 0.0f};
  const float base_camera_speed = 400.0f;
  void init();
  void handle_input(int width_limit, int height_limit);
  void update(int width_limit, int height_limit);
  void draw_start();
  void draw_end();
  void deinit();
};

#endif