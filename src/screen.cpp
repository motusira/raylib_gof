#include "screen.hpp"
#include "raylib.h"
#include <raymath.h>

void Screen::init() {
  size.x = 800 * 2;
  size.y = 600 * 2;
  InitWindow(size.x, size.y, "Game of life");
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  SetTargetFPS(60);

  camera = {0};
  camera.target = Vector2{0.0f, 0.0f};
  camera.offset = Vector2{size.x / 2.0f, size.y / 2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 0.5f;
}

void Screen::handle_input(int width_limit, int height_limit) {
  if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) {
    Vector2 delta = GetMouseDelta();
    delta = Vector2Scale(delta, -1.0f / camera.zoom);

    camera.target.x = Clamp(camera.target.x + delta.x, 0, width_limit);

    camera.target.y = Clamp(camera.target.y + delta.y, 0, height_limit);
  }

  camera_move_speed = Vector2Zero();

  if (IsKeyDown(KEY_RIGHT)) {
    camera_move_speed.x += 1.0f;
  }
  if (IsKeyDown(KEY_LEFT)) {
    camera_move_speed.x -= 1.0f;
  }
  if (IsKeyDown(KEY_UP)) {
    camera_move_speed.y -= 1.0f;
  }
  if (IsKeyDown(KEY_DOWN)) {
    camera_move_speed.y += 1.0f;
  }

  if (Vector2Length(camera_move_speed) > 0) {
    camera_move_speed = Vector2Normalize(camera_move_speed);
    camera_move_speed = Vector2Scale(camera_move_speed, base_camera_speed);
  }

  if (IsKeyPressed(KEY_MINUS)) {
    camera.zoom = Clamp(camera.zoom - 0.1f, 0.1f, 0.8f);
  }
  if (IsKeyPressed(KEY_EQUAL)) {
    camera.zoom = Clamp(camera.zoom + 0.1f, 0.1f, 0.8f);
  }
}

void Screen::update(int width_limit, int height_limit) {
  if (!Vector2Equals(camera_move_speed, Vector2Zero())) {
    Vector2 delta =
        Vector2Scale(camera_move_speed, GetFrameTime() / camera.zoom);

    camera.target.x = Clamp(camera.target.x + delta.x, 0, width_limit);

    camera.target.y = Clamp(camera.target.y + delta.y, 0, height_limit);
  }

  if (IsWindowResized()) {
    size = {static_cast<float>(GetScreenWidth()),
            static_cast<float>(GetScreenHeight())};
    camera.offset.x = size.x / 2;
    camera.offset.y = size.y / 2;

    camera.target.x = Clamp(camera.target.x, 0, width_limit);
    camera.target.y = Clamp(camera.target.y, 0, height_limit);
  }
}

void Screen::draw_start() {
  BeginDrawing();
  ClearBackground(RAYWHITE);
}

void Screen::start_cam_mode() {
  BeginMode2D(camera);
}

void Screen::end_cam_mode() {
  EndMode2D();
}

void Screen::draw_end() {
  EndDrawing();
}

Camera2D &Screen::share_camera() {
  return camera;
}

void Screen::deinit() { CloseWindow(); }
