#ifndef BALL_HPP
#define BALL_HPP

#include "raylib.h"

class Ball {
public:
  Vector2 pos;
  Vector2 velocity;
  float radius = 12.0f;
  Color color = RED;
  bool stuckToPaddle;

  Ball(Vector2 pos, Vector2 vel, bool stuck)
      : pos(pos), velocity(vel), stuckToPaddle(stuck) {}

  void update(float dt) {
    pos.x += velocity.x * dt;
    pos.y += velocity.y * dt;
  }

  void draw() const { DrawCircleV(pos, radius, color); }

  Rectangle getBounds() const {
    return {pos.x - radius, pos.y - radius, radius * 2, radius * 2};
  }

  void reflectY() { velocity.y *= -1; }
  void reflectX() { velocity.x *= -1; }
  Vector2 getCenter() const { return {pos.x + radius, pos.y + radius}; }
};

#endif
