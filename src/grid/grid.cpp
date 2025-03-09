#include "grid.hpp"

void Grid::init() {
  cells.resize(grid_size * grid_size);
  std::fill(cells.begin(), cells.end(), 4);
}

void Grid::draw() {
  std::vector<Color> colors = {{8, 28, 21, 255},
                               {82, 183, 136, 255},
                               {149, 213, 178, 255},
                               {183, 228, 199, 255},
                               {216, 243, 220, 255}};

  for (int i = 0; i < cells.size(); i++) {
    DrawRectangle((i % grid_size) * cell_size, (i / grid_size) * cell_size, cell_size,
                  cell_size, colors[cells[i]]);
  }
  for (int i = 0; i < (grid_size + 1) * cell_size; i += cell_size) {
    DrawLine(i, 0, i, grid_size * cell_size, LIGHTGRAY);
    DrawLine(0, i, grid_size * cell_size, i, LIGHTGRAY);
  }
}

void Grid::resize_grid() {
  cells.resize(grid_size * grid_size);
  std::fill(cells.begin(), cells.end(), 4);
}

int Grid::get_cell_size() { return cell_size; }

int Grid::get_grid_size() { return grid_size; }

void Grid::set_grid_size(int n) {
  grid_size = n;
  resize_grid();
}

void Grid::set_cell_size(int n) { cell_size = n; }

bool Grid::is_alive(int pos) { return cells[pos] == 0; }

int Grid::get_new_pos(int dx, int dy, int pos) {
  int new_x = (pos % grid_size + dx) % grid_size;
  int new_y = (pos / grid_size + dy) % grid_size;

  if (new_x < 0)
    new_x += grid_size;
  if (new_y < 0)
    new_y += grid_size;

  return new_y * grid_size + new_x;
}

int Grid::count_neibs(int pos) {
  int live_neib = 0;
  int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

  for (int i = 0; i < 8; i++) {
    live_neib += is_alive(get_new_pos(dx[i], dy[i], pos));
  }
  return live_neib;
}

void Grid::simulate() {
  std::vector<char> cc = cells;
  for (int i = 0; i < cells.size(); i++) {
    bool current_alive = (cells[i] == 0);
    int neib = count_neibs(i);

    if (current_alive) {
      cc[i] = (neib == 2 || neib == 3) ? 0 : (cc[i] < 4 ? cc[i] + 1 : 4);
    } else {
      cc[i] = (neib == 3) ? 0 : (cc[i] < 4 ? cc[i] + 1 : 4);
    }
  }
  cells = cc;
}

void Grid::update() {
  if (GetTime() - prev_time >= update_interval) {
    simulate();
    prev_time = GetTime();
  }
}

void Grid::invert_cell_state(int x, int y) {
    cells[x + y * grid_size] = 0;
}
