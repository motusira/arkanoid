#include "game_board.hpp"
#include "brick/brick.hpp"


void GameBoard::update(void) {}

void GameBoard::draw(void) {
  for (const auto &brick : bricks) {
    if (brick.health == 0)
      continue;

    DrawRectangleRec({brick.pos.x, brick.pos.y, brick.size.x, brick.size.y},
                     brick.color);

    if (brick.type == BrickType::Armored) {
      DrawText(TextFormat("%d", brick.health),
               brick.pos.x + brick.size.x / 2 - 5, brick.pos.y + 2, 12, WHITE);
    }
  }
}

void GameBoard::init(int winWidth, int winHeight) {
  width = winWidth;
  topOffset = winHeight / 5;
  height = winHeight - topOffset;
  bricks = generateRandomBricks(5, 5, 15, 15, 3, 50, 50);
}
