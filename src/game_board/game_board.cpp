#include "game_board.hpp"
#include "brick/brick.hpp"


void GameBoard::update(void) {}

void GameBoard::draw(void) {
  for (const auto &brick : bricks) {
    if (brick.isDestroyed())
      continue;
    brick.draw();
  }
}

void GameBoard::init(int winWidth, int winHeight) {
  width = winWidth;
  topOffset = winHeight / 8;
  height = winHeight - topOffset;
  bricks = generateRandomBricks(12, 25, BRICK_WIDTH, BRICK_HEIGHT, 5, width / 2 - (25 * BRICK_WIDTH + 24 * 5) / 2, topOffset + 20);
}
