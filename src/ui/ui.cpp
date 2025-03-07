#include "ui.hpp"
#include "../raygui.h"

void UI::init(const Vector2 &window_size) {
  viewport = {window_size.x * 2.0f / 3.0f, 0, window_size.x, window_size.y};
}

void UI::update(const Vector2 &window_size) {
  viewport = {window_size.x * 2.0f / 3.0f, 0, window_size.x, window_size.y};
}

void UI::draw(const Vector2 &window_size, Grid &g) {
  BeginScissorMode(viewport.x, viewport.y, viewport.width, viewport.height);
  DrawRectangle(viewport.x, viewport.y, viewport.width, viewport.height,
                LIGHTGRAY);
  DrawText("UI View", viewport.x + 10, viewport.y + 10, 20, BLACK);
  DrawFPS(viewport.x + 10, viewport.y + 30);
  float s = g.get_cell_size();
  GuiSliderBar((Rectangle){viewport.x + 10, viewport.y + 60, 140, 20}, NULL,
               NULL, &s, 1, 64);
  DrawText(TextFormat("Cell size: %.0f", s), viewport.x + 10, viewport.y + 90,
           20, BLACK);
  if (g.get_cell_size() != (int)s) {
    g.set_cell_size((int)s);
  }
  float d = g.get_grid_size();
  GuiSliderBar((Rectangle){viewport.x + 10, viewport.y + 110, 140, 20}, NULL,
               NULL, &d, 1, 256);
  DrawText(TextFormat("Grid size: %.0f", d), viewport.x + 10, viewport.y + 140,
           20, BLACK);
  if (g.get_cell_size() != (int)d) {
    g.set_grid_size((int)d);
  }
  EndScissorMode();
}