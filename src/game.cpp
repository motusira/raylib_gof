#include "game.hpp"
#include "screen.hpp"
#include "grid.hpp"
#include "ui.hpp"

void Game::init() {
  screen.init();
}

void Game::handle_input() {
  screen.handle_input(grid.get_width(), grid.get_height());
  grid.handle_input(screen.share_camera());
}

void Game::draw() {
  screen.draw_start();
  screen.start_cam_mode();
  grid.draw();
  screen.end_cam_mode();
  ui.draw(grid);
  screen.draw_end();
}

void Game::update() {
  screen.update(grid.get_width(), grid.get_height());
  grid.update();
}

void Game::run() {
  init();
  while (!WindowShouldClose()) {
    handle_input();
    update();
    draw();
  }
  screen.deinit();
}
