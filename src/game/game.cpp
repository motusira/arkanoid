#include "raylib.h"
#include "game.hpp"

void Game::run(void) {
  init();
  while (!WindowShouldClose()) {
    handle_input();
    update();
    draw();
  }
}

void Game::init(void) {
  window.init();
}

void Game::draw(void) {
  
}
void Game::handle_input(void) {
  BeginDrawing();
  EndDrawing();
}

void Game::update(void) {
  
}
