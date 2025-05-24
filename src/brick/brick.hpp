#ifndef BRICK_HPP
#define BRICK_HPP

#include "raylib.h"
#include <vector>

enum class BrickType { Normal, Armored, Indestructible };

struct Brick {
  Vector2 pos;
  Vector2 size;
  BrickType type;
  int health;
  bool hasBonus;
  Color color;
};

std::vector<Brick> GenerateRandomBricks(int rows, int cols, int width, int height, int spacing, int offsetX, int offsetY);

#endif
