#include "window.hpp"
#include "raylib.h"

void Window::init() {
  size.x = 1200;
  size.y = 800;

  InitWindow(size.x, size.y, "Game of life");
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  SetTargetFPS(60);
  SetWindowMinSize(800, 600);

  size.x = GetMonitorWidth(GetCurrentMonitor()) / 2;
  size.y = GetMonitorHeight(GetCurrentMonitor()) / 2;

  SetWindowSize(size.x, size.y);
}

void Window::update() {
  size = {static_cast<float>(GetScreenWidth()),
          static_cast<float>(GetScreenHeight())};
}

bool Window::is_resized() {
  return IsWindowResized();
}

void Window::draw_start() {
  BeginDrawing();
  ClearBackground(RAYWHITE);
}

void Window::draw_end() { EndDrawing(); }

Vector2 Window::get_size() { return size; }
