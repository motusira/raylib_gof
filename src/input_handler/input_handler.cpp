#include "input_handler.hpp"
#include "../grid/grid.hpp"
#include "raymath.h"

void Input_handler::camera_input(Cam &camera, const int limit) {
  if (IsKeyPressed(KEY_MINUS)) {
    camera.zoom_out();
  }
  if (IsKeyPressed(KEY_EQUAL)) {
    camera.zoom_in();
  }

  if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) {
    Vector2 delta = GetMouseDelta();
    delta = Vector2Scale(delta, -1.0f / camera.get_zoom());

    camera.move_by_delta(delta, limit);
  }

  camera.set_move_vec_x(0.0f);
  camera.set_move_vec_y(0.0f);
  if (IsKeyDown(KEY_RIGHT)) {
    camera.set_move_vec_x(1.0f);
  }
  if (IsKeyDown(KEY_LEFT)) {
    camera.set_move_vec_x(-1.0f);
  }
  if (IsKeyDown(KEY_UP)) {
    camera.set_move_vec_y(-1.0f);
  }
  if (IsKeyDown(KEY_DOWN)) {
    camera.set_move_vec_y(1.0f);
  }
}

void Input_handler::grid_input(Grid &g, const Cam &camera) {
  bool mbl = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
  bool mbr = IsMouseButtonDown(MOUSE_BUTTON_RIGHT);

  if (mbl || mbr) {
    Vector2 mouse_pos = GetMousePosition();
    Vector2 world_pos = camera.screen_to_world(mouse_pos);

    int mx = static_cast<int>(world_pos.x / g.get_cell_size());
    int my = static_cast<int>(world_pos.y / g.get_cell_size());

    if (mx >= 0 && mx < g.get_grid_size() && my >= 0 &&
        my < g.get_grid_size()) {
      if (mbl) {
        g.set_cell_alive(mx, my);
      } else {
        g.set_cell_unalive(mx, my);
      }
    }
  }
}
