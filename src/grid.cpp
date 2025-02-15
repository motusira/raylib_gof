#include "grid.hpp"

#include "raylib.h"
#include <vector>

Grid::Grid() {
  cells.resize(width * height);
  std::fill(cells.begin(), cells.end(), Cell{4});
}

void Grid::draw() {
  std::vector<Color> colors = {{8, 28, 21, 255},
                               {82, 183, 136, 255},
                               {149, 213, 178, 255},
                               {183, 228, 199, 255},
                               {216, 243, 220, 255}};

  for (int i = 0; i < cells.size(); i++) {
    DrawRectangle((i % width) * cell_size, (i / width) * cell_size, cell_size,
                  cell_size, colors[cells[i].alive]);
  }
  for (int i = 0; i < (width + 1) * cell_size; i += cell_size) {
    DrawLine(i, 0, i, width * cell_size, LIGHTGRAY);
  }
  for (int j = 0; j < (height + 1) * cell_size; j += cell_size) {
    DrawLine(0, j, height * cell_size, j, LIGHTGRAY);
  }
}

bool Grid::is_alive(int pos) { return cells[pos].alive == 0; }

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
  std::vector<Cell> cc = cells;
  for (int i = 0; i < cells.size(); i++) {
    bool current_alive = (cells[i].alive == 0);
    int neib = check_neib(i);

    if (current_alive) {
      cc[i].alive = (neib == 2 || neib == 3)
                        ? 0
                        : (cc[i].alive < 4 ? cc[i].alive + 1 : 4);
    } else {
      cc[i].alive = (neib == 3) ? 0 : (cc[i].alive < 4 ? cc[i].alive + 1 : 4);
    }
  }
  cells = cc;
}