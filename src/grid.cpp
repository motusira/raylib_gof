#include "grid.hpp"

#include "raylib.h"
#include <vector>

Grid::Grid() {
  cells.resize(width * height);
  std::fill(cells.begin(), cells.end(), 4);
}

void Grid::draw() {
  std::vector<Color> colors = {{8, 28, 21, 255},
                               {82, 183, 136, 255},
                               {149, 213, 178, 255},
                               {183, 228, 199, 255},
                               {216, 243, 220, 255}};

  for (int i = 0; i < cells.size(); i++) {
    DrawRectangle((i % width) * cell_size, (i / width) * cell_size, cell_size,
                  cell_size, colors[cells[i]]);
  }
  for (int i = 0; i < (width + 1) * cell_size; i += cell_size) {
    DrawLine(i, 0, i, width * cell_size, LIGHTGRAY);
  }
  for (int j = 0; j < (height + 1) * cell_size; j += cell_size) {
    DrawLine(0, j, height * cell_size, j, LIGHTGRAY);
  }
}

bool Grid::is_alive(int pos) { return cells[pos] == 0; }

int Grid::get_new_pos(int dx, int dy, int pos) {
  int new_x = (pos % width + dx) % width;
  int new_y = (pos / width + dy) % height;

  if (new_x < 0)
    new_x += width;
  if (new_y < 0)
    new_y += height;

  return new_y * width + new_x;
}

int Grid::check_neib(int pos) {
  int live_neib = 0;
  int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

  for (int i = 0; i < 8; i++) {
    live_neib += is_alive(get_new_pos(dx[i], dy[i], pos));
  }
  return live_neib;
}

void Grid::simulate() {
  std::vector<int> cc = cells;
  for (int i = 0; i < cells.size(); i++) {
    bool current_alive = (cells[i] == 0);
    int neib = check_neib(i);

    if (current_alive) {
      cc[i] = (neib == 2 || neib == 3)
                        ? 0
                        : (cc[i] < 4 ? cc[i] + 1 : 4);
    } else {
      cc[i] = (neib == 3) ? 0 : (cc[i] < 4 ? cc[i] + 1 : 4);
    }
  }
  cells = cc;
}

int Grid::get_width() {
  return width * cell_size;
}

int Grid::get_height() {
  return height * cell_size;
}

void Grid::handle_input(Camera2D &camera) {
  if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) ||
      IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
    Vector2 mouse_pos = GetMousePosition();
    Vector2 world_pos = GetScreenToWorld2D(mouse_pos, camera);

    int mx = static_cast<int>(world_pos.x / cell_size);
    int my = static_cast<int>(world_pos.y / cell_size);

    if (mx >= 0 && mx < width && my >= 0 && my < height) {
      int index = my * width + mx;
      cells[index] = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? 0 : 4;
    }
  }

  if (IsKeyPressed(KEY_SPACE)) {
    pause = !pause;
  }
}

void Grid::update() {
  if (!pause && GetTime() - prev_time >= update_interval) {
    this->simulate();
    prev_time = GetTime();
  }
}

int Grid::get_cell_size() {
  return cell_size;
}

void Grid::set_cell_size(int n) {
  cell_size = n;
}