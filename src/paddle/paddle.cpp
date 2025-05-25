#include "paddle.hpp"

void Paddle::update(float dt, int width) {
  float speed = 400.0f;

  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    pos.x -= speed * dt;
  }
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    pos.x += speed * dt;
  }

  float screenWidth = static_cast<float>(width);
  if (pos.x < 0)
    pos.x = 0;
  if (pos.x + size.x > screenWidth)
    pos.x = screenWidth - size.x;
}
