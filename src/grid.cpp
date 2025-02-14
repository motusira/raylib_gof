#include "grid.hpp"

#include "raylib.h"
#include <vector>

Grid::Grid() {
  cells.resize(width * height);
  std::fill(cells.begin(), cells.end(), Cell{4});
}

void Grid::draw() {
  std::vector<Color> colors = {{5, 102, 141, 255},
                               {2, 128, 144, 255},
                               {0, 168, 150, 255},
                               {2, 195, 154, 255},
                               {240, 243, 189, 255}};

  for (int i = 0; i < cells.size(); i++) {
    DrawRectangle((i % width) * cell_size, (i / width) * cell_size, cell_size,
                  cell_size, colors[cells[i].alive]);
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
      cc[i].alive = (neib == 2 || neib == 3) ? 0 : 4;
    } else {
      cc[i].alive = (neib == 3) ? 0 : 4;
    }
  }
  cells = cc;
}