#include "game.hpp"
#include "raylib.h"
#include "utils/utils.hpp"

void Game::run(void) {
  init();
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    handle_input(dt);
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
void Game::handle_input(float dt) {
  board.handle_input(dt);
}

void Game::update(void) {}
