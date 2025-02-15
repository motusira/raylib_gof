#include "game.hpp"
#include "raymath.h"

void Game::init() {
  InitWindow(width, height, "Game of life");

  camera = {0};
  camera.target = Vector2{0.0f, 0.0f};
  camera.offset = Vector2{width / 2.0f, height / 2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 0.5f;

  prev_time = GetTime();
}

void Game::process_input() {
  if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
    Vector2 mouse_pos = GetMousePosition();
    Vector2 world_pos = GetScreenToWorld2D(mouse_pos, camera);

    int mx = static_cast<int>(world_pos.x / grid.cell_size);
    int my = static_cast<int>(world_pos.y / grid.cell_size);

    if (mx >= 0 && mx < grid.width && my >= 0 && my < grid.height) {
      int index = my * grid.width + mx;
      grid.cells[index].alive = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? 0 : 4;
    }
  }

  if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) {
    Vector2 delta = GetMouseDelta();
    delta = Vector2Scale(delta, -1.0f / camera.zoom);
    camera.target = Vector2Add(camera.target, delta);

    float grid_width = grid.width * grid.cell_size;
    float grid_height = grid.height * grid.cell_size;
    camera.target.x = Clamp(camera.target.x, 0, grid_width);
    camera.target.y = Clamp(camera.target.y, 0, grid_height);
  }

  if (IsKeyPressed(KEY_MINUS))
    camera.zoom = Clamp(camera.zoom - 0.1f, 0.1f, 0.8f);
  if (IsKeyPressed(KEY_EQUAL))
    camera.zoom = Clamp(camera.zoom + 0.1f, 0.1f, 0.8f);

  if (IsKeyPressed(KEY_SPACE))
    pause = !pause;
}

void Game::draw() {
  BeginDrawing();
  ClearBackground(RAYWHITE);

  BeginMode2D(camera);
  grid.draw();
  EndMode2D();

  EndDrawing();
}

void Game::update() {
  if (!pause && GetTime() - prev_time >= update_interval) {
    grid.simulate();
    prev_time = GetTime();
  }
}

void Game::deinit() { CloseWindow(); }

void Game::run() {
  init();
  while (!WindowShouldClose()) {
    process_input();
    update();
    draw();
  }
  deinit();
}