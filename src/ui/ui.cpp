#include "ui.hpp"
#include "../raygui.h"

void UI::init(const Vector2 &window_size) {
  viewport = {window_size.x * 2.0f / 3.0f, 0, window_size.x, window_size.y};
}

void UI::update(const Vector2 &window_size) {
  viewport = {window_size.x * 2.0f / 3.0f, 0, window_size.x / 3.0f, window_size.y};
}

static void draw_slide_bar(const float x, const float y, const float width,
                    const float height, float &val, const char *text, const float min, const float max) {
  GuiSliderBar((Rectangle){x, y, width, height}, NULL, NULL, &val, min, max);
  DrawText(TextFormat(text, val), x + 10, y + height + 10, 20, BLACK);
}

void UI::draw(const Vector2 &window_size, Grid &g) {

  float x = viewport.x + 10;
  float y = viewport.y + 10;
  float width = viewport.width / 3 * 2;
  float height = viewport.height / 20;

  BeginScissorMode(viewport.x, viewport.y, viewport.width, viewport.height);

  DrawRectangle(viewport.x, viewport.y, viewport.width, viewport.height,
                LIGHTGRAY);
  DrawFPS(x, y);

  y += 30;

  float s = g.get_cell_size();
  draw_slide_bar(x, y, width, height, s, "Cell size: %.0f", 1, 64);
  y += 3 * height;
  if (g.get_cell_size() != (int)s) {
    g.set_cell_size((int)s);
  }

  float d = g.get_grid_size();
  draw_slide_bar(x, y, width, height, d, "Grid size: %.0f", 1, 256);
  y += 3 * height;
  if (g.get_grid_size() != (int)d) {
    g.set_grid_size((int)d);
  }

  float u = g.get_update_interval();
  draw_slide_bar(x, y, width, height, u, "Update interval: %.2f", 0.01, 0.5);
  y += 3 * height;
  if (g.get_update_interval() != u) {
    g.set_update_interval(u);
  }

  EndScissorMode();
}
