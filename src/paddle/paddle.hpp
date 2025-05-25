#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "hittable_object/hittable_object.hpp"
#include "raymath.h"

class Paddle : public HittableObject {
public:
  Vector2 pos;
  Vector2 size;
  Color color = BLUE;

public:
  Paddle() = default;

  Paddle(Vector2 p, Vector2 s) : pos(p), size(s) {}

  Rectangle getBounds(void) const override {
    return {pos.x, pos.y, size.x, size.y};
  }

  void onBallHit(void) override {}

  void draw(void) const override { DrawRectangleV(pos, size, color); }

  void update(float dt, int width);
  void setSize(float m) { size.x = Clamp(size.x * m, 100, 500); }
};

#endif
