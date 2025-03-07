#include "input_handler.hpp"
#include <iostream>

void Input_handler::camera_input(Cam &camera) {
  // if (IsKeyPressed(KEY_MINUS)) {
  //   camera.zoom = Clamp(camera.zoom - 0.1f, 0.1f, 0.8f);
  // }
  // if (IsKeyPressed(KEY_EQUAL)) {
  //   camera.zoom = Clamp(camera.zoom + 0.1f, 0.1f, 0.8f);
  // }

  camera.set_move_vec_x(0.0f);
  camera.set_move_vec_y(0.0f);
  if (IsKeyDown(KEY_RIGHT)) {
    camera.set_move_vec_x(1.0f);
    // std::cout << "movemove" << std::endl;
  }
  if (IsKeyDown(KEY_LEFT)) {
    camera.set_move_vec_x(-1.0f);
    // std::cout << "movemove" << std::endl;
  }
  if (IsKeyDown(KEY_UP)) {
    camera.set_move_vec_y(-1.0f);
    // std::cout << "movemove" << std::endl;
  }
  if (IsKeyDown(KEY_DOWN)) {
    camera.set_move_vec_y(1.0f);
    // std::cout << "movemove" << std::endl;
  }
}