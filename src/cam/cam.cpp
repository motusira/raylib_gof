#include "cam.hpp"
#include "raylib.h"
#include <raymath.h>

void Cam::init(const Vector2 &window_size) {

  viewport = {0, 0, window_size.x * 2.0f / 3.0f, window_size.y};

  camera = {0};
  camera.target = Vector2{0.0f, 0.0f};
  camera.offset = Vector2{viewport.width / 2.0f, viewport.height / 2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 0.2f; 

  
}

void Cam::update_after_resize(const Vector2 &window_size) {
  viewport = {0, 0, window_size.x * 2.0f / 3.0f, window_size.y};
  camera.offset = Vector2{viewport.width / 2.0f, viewport.height / 2.0f};
}

void Cam::update(int grid_size) {
  if (!Vector2Equals(move_vec, Vector2Zero())) {
    Vector2 delta = Vector2Scale(move_vec, GetFrameTime() / camera.zoom * speed);
    camera.target.x = Clamp(camera.target.x + delta.x, 0, grid_size);
    camera.target.y = Clamp(camera.target.y + delta.y, 0, grid_size);
  }
}

void Cam::set_move_vec_x(float n) { move_vec.x = n; }

void Cam::set_move_vec_y(float n) { move_vec.y = n; }

void Cam::start_cam_mode() {
  BeginScissorMode(viewport.x, viewport.y, viewport.width, viewport.height);
  BeginMode2D(camera);
}

void Cam::end_cam_mode() {
  EndScissorMode();
  EndMode2D();
}

void Cam::zoom_in() {
  camera.zoom = Clamp(camera.zoom + 0.1f, 0.1f, 0.8f);
}

void Cam::zoom_out() {
  camera.zoom = Clamp(camera.zoom - 0.1f, 0.1f, 0.8f);
}

Vector2 Cam::screen_to_world(Vector2 &pos) const {
  return GetScreenToWorld2D(pos, camera);
}
