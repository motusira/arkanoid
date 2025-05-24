#include "brick.hpp"
#include "raylib.h"
#include <cstdlib>
#include <vector>

BrickType RandomBrickType() {
  int r = std::rand() % 100;
  if (r < 60)
    return BrickType::Normal;
  if (r < 90)
    return BrickType::Armored;
  return BrickType::Indestructible;
}

bool RandomBonusChance() { return (std::rand() % 100) < 10; }

Color BrickColorByType(BrickType type) {
  switch (type) {
  case BrickType::Normal:
    return GREEN;
  case BrickType::Armored:
    return BLUE;
  case BrickType::Indestructible:
    return GRAY;
  default:
    return BLACK;
  }
}

int HealthByType(BrickType type) {
  switch (type) {
  case BrickType::Normal:
    return 1;
  case BrickType::Armored:
    return 3;
  case BrickType::Indestructible:
    return -1;
  default:
    return 1;
  }
}

std::vector<Brick> generateRandomBricks(int rows, int cols, int width,
                                        int height, int spacing, int offsetX,
                                        int offsetY) {
  std::vector<Brick> bricks;

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      Vector2 pos = {static_cast<float>(offsetX + col * (width + spacing)),
                     static_cast<float>(offsetY + row * (height + spacing))};

      BrickType type = RandomBrickType();

      bricks.push_back(
          {.pos = pos,
           .size = {static_cast<float>(width), static_cast<float>(height)},
           .type = type,
           .health = HealthByType(type),
           .hasBonus = RandomBonusChance(),
           .color = BrickColorByType(type)});
    }
  }

  return bricks;
}
