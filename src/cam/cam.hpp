#ifndef __CAM_HPP__
#define __CAM_HPP__

#include "raylib.h"

class Cam {
  public:
  void init(const Vector2 &window_size);
  void update_after_resize(const Vector2 &window_size);
  void update(int grid_size);
  void set_move_vec_x(float n);
  void set_move_vec_y(float n);
  void start_cam_mode(void);
  void end_cam_mode(void);
  void zoom_in(void);
  void zoom_out(void);
  Vector2 screen_to_world(Vector2 &pos) const;
  private:
  Camera2D camera;
  Rectangle viewport;
  Vector2 move_vec = {0.0f, 0.0f};
  float speed = 800.0;
};

#endif
