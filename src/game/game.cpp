#include "game.hpp"
#include "raylib.h"
#include "utils/utils.hpp"

void Game::run(void) {
  init();
  while (!WindowShouldClose()) {
    handle_input();
    update();
    drawStart();
    board.draw();
    drawEnd();
  }
}

void Game::init(void) {
  initRandom();
  window.init();
  board.init(window.getWidth(), window.getHeight());
}

void Game::drawStart(void) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
}

void Game::drawEnd(void) {
  EndDrawing();
}
void Game::handle_input(void) {
}

void Game::update(void) {}
