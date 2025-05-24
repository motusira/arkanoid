#include "game_board.hpp"
#include "brick/brick.hpp"
#include "paddle/paddle.hpp"



void GameBoard::handle_input(float dt) {
  paddle.handle_input(dt, width);
}

void GameBoard::draw(void) {
  for (const auto &brick : bricks) {
    if (brick.isDestroyed())
      continue;
    brick.draw();
  }
  paddle.draw();
}

void GameBoard::init(int winWidth, int winHeight) {
  width = winWidth;
  topOffset = winHeight / 8;
  height = winHeight - topOffset;
  bricks = generateRandomBricks(12, 25, BRICK_WIDTH, BRICK_HEIGHT, 5, width / 2 - (25 * BRICK_WIDTH + 24 * 5) / 2, topOffset + 20);
  paddle = Paddle({static_cast<float>(height - 90), static_cast<float>(width / 2 - 30)}, {180, 20});
}
