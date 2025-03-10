#include "game.hpp"

void Game::run() {
  init();
  while (!WindowShouldClose()) {
    handle_input();
    update();
    draw();
  }
}

void Game::init() {
  win.init();
  g.init();
  camera.init(win.get_size());
  ui.init(win.get_size());
}

void Game::draw() {
  win.draw_start();
  camera.start_cam_mode();
  g.draw();
  camera.end_cam_mode();
  ui.draw(g);
  win.draw_end();
}

void Game::handle_input() {
  input_handler.camera_input(camera, g.get_cell_size() * g.get_grid_size());
  input_handler.grid_input(g, camera);
  game_input();
}

void Game::update() {
  if (win.is_resized()) {
    win.update();
    camera.update_after_resize(win.get_size());
    ui.update(win.get_size());
  }
  camera.update(g.get_cell_size() * g.get_grid_size());
  if (!pause) {
    g.update();
  }
}

void Game::game_input() {
  if (IsKeyPressed(KEY_SPACE)) {
    pause = !pause;
  }
}
