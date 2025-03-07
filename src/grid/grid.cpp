#include "grid.hpp"

void Grid::init() {
  cells.resize(grid_size * grid_size);
  std::fill(cells.begin(), cells.end(), 0);
}

void Grid::draw() {
  for (int i = 0; i < cells.size(); i++) {
    DrawRectangle((i % grid_size) * cell_size, (i / grid_size) * cell_size, cell_size,
                  cell_size, {216, 243, 220, 255});
  }
  for (int i = 0; i < (grid_size + 1) * cell_size; i += cell_size) {
    DrawLine(i, 0, i, grid_size * cell_size, LIGHTGRAY);
    DrawLine(0, i, grid_size * cell_size, i, LIGHTGRAY);
  }
}

void Grid::resize_grid() {
  cells.resize(grid_size * grid_size);
  std::fill(cells.begin(), cells.end(), 0);
}

int Grid::get_cell_size() {
  return cell_size;
}

int Grid::get_grid_size() {
  return grid_size;
}

void Grid::set_grid_size(int n) {
  grid_size = n;
  resize_grid();
}

void Grid::set_cell_size(int n) {
  cell_size = n;
}