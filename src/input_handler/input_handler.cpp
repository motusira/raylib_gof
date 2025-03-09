#include "input_handler.hpp"
#include "../grid/grid.hpp"

void Input_handler::camera_input(Cam &camera) {
  if (IsKeyPressed(KEY_MINUS)) {
    camera.zoom_out();
  }
  if (IsKeyPressed(KEY_EQUAL)) {
    camera.zoom_in();
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
  if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) ||
      IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
    Vector2 mouse_pos = GetMousePosition();
    Vector2 world_pos = camera.screen_to_world(mouse_pos);

    int mx = static_cast<int>(world_pos.x / g.get_cell_size());
    int my = static_cast<int>(world_pos.y / g.get_cell_size());

    if (mx >= 0 && mx < g.get_grid_size() && my >= 0 &&
        my < g.get_grid_size()) {
      g.invert_cell_state(mx, my);
    }
  }
}
