#include "game.hpp"
#include "raylib.h"

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
  BeginDrawing();
  EndDrawing();
}

void Game::update(void) {}
