#ifndef BRICK_HPP
#define BRICK_HPP

#include "hittable_object/hittable_object.hpp"
#include "raylib.h"
#include <vector>

#define BRICK_WIDTH 30
#define BRICK_HEIGHT 20

enum class BrickType { Normal, Armored, SpeedBoost, Indestructible };

class Brick : public HittableObject {
public:
  Vector2 pos;
  Vector2 size;
  BrickType type;
  int health = 1;
  bool hasBonus = false;
  Color color = GREEN;

  Brick(Vector2 p, Vector2 s, BrickType t, int h, bool b, Color c)
      : pos(p), size(s), type(t), health(h), hasBonus(b), color(c) {}

  Rectangle getBounds() const override {
    return {pos.x, pos.y, size.x, size.y};
  }

  void onBallHit() override {
    if (type == BrickType::Indestructible)
      return;
    health--;
  }

  bool isDestroyed() const override {
    return (type != BrickType::Indestructible && health <= 0);
  }

  void draw() const override { DrawRectangleV(pos, size, color); }
};

std::vector<Brick> generateRandomBricks(int rows, int cols, int width,
                                        int height, int spacing, int offsetX,
                                        int offsetY);

#endif
