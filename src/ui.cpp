#include "ui.hpp"
#include "raygui.h"

void UI::init() {
  
}

void UI::draw(Grid &g) {
  float s = g.get_cell_size();
  GuiSliderBar((Rectangle){ 640, 40, 105, 20 }, "Width", TextFormat("%.0f", s), &s, 0, 64);
  g.set_cell_size((int) s);
  float h = g.get_height();
  float w = g.get_width();
  GuiSliderBar((Rectangle){ 640, 80, 105, 20 }, "Width", TextFormat("%.0f", h), &h, 0, 256);
  GuiSliderBar((Rectangle){ 640, 120, 105, 20 }, "Width", TextFormat("%.0f", w), &w, 0, 256);
}