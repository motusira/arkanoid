#include "game_board.hpp"
#include "brick/brick.hpp"
#include "paddle/paddle.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>

void GameBoard::update(float dt) {
  paddle.update(dt, width);
  for (auto &ball : balls) {
    ball.update(dt);
  }
  handleBallCollisions();
  balls.erase(std::remove_if(
                  balls.begin(), balls.end(),
                  [&](const Ball &b) { return (b.pos.y - b.radius) > height && (score-=50); }),
              balls.end());
}

void GameBoard::draw(void) {
  for (const auto &brick : bricks) {
    if (brick.isDestroyed())
      continue;
    brick.draw();
  }
  for (auto &ball : balls) {
    ball.draw();
  }
  paddle.draw();

  DrawRectangle(0, 0, width, 50, DARKGRAY);

  DrawText(TextFormat("Score: %d", score), 20, 15, 20, WHITE);
  DrawText(TextFormat("Balls: %d", balls.size()), 280, 15, 20, WHITE);

  DrawLine(0, 50, width, 50, GRAY);
}

void GameBoard::init(int winWidth, int winHeight) {
  width = winWidth;
  topOffset = 50;
  height = winHeight;
  score = 0;
  bricks = generateRandomBricks(12, 25, BRICK_WIDTH, BRICK_HEIGHT, 5,
                                width / 2 - (25 * BRICK_WIDTH + 24 * 5) / 2,
                                topOffset + 100);
  paddle = Paddle(
      {static_cast<float>(height - 90), static_cast<float>(width / 2 - 30)},
      {180, 20});
  balls.emplace_back(Vector2{500, 600}, Vector2{200, -200});
  balls.emplace_back(Vector2{500, 500}, Vector2{200, -200});
  balls.emplace_back(Vector2{200, 600}, Vector2{200, -200});
  balls.emplace_back(Vector2{300, 500}, Vector2{200, -200});
  balls.emplace_back(Vector2{400, 600}, Vector2{200, -200});
  balls.emplace_back(Vector2{100, 500}, Vector2{300, -200});
}

void GameBoard::handleBallCollisions() {
  for (int i = 0; i < balls.size(); i++) {
    Ball &ball = balls[i];

    if (ball.pos.x - ball.radius <= 0) {
      ball.pos.x = ball.radius;
      ball.velocity.x *= -1;
    }
    if (ball.pos.x + ball.radius >= width) {
      ball.pos.x = width - ball.radius;
      ball.velocity.x *= -1;
    }
    if (ball.pos.y - ball.radius <= 50) {
      ball.pos.y = 50 + ball.radius;
      ball.velocity.y *= -1;
    }
    // if (ball.pos.y + ball.radius >= height) {
    //   ball.pos.y = height - ball.radius;
    //   ball.velocity.y *= -1;
    // }

    Rectangle paddleRect = paddle.getBounds();
    if (CheckCollisionCircleRec(ball.pos, ball.radius, paddleRect)) {
      float paddleCenterX = paddleRect.x + paddleRect.width * 0.5f;
      float diff = ball.pos.x - paddleCenterX;
      float speed = sqrt(ball.velocity.x * ball.velocity.x +
                         ball.velocity.y * ball.velocity.y);
      ball.velocity.x = diff;
      ball.velocity.y = -fabs(ball.velocity.y);
      float newSpeed = sqrt(ball.velocity.x * ball.velocity.x +
                            ball.velocity.y * ball.velocity.y);
      if (newSpeed != 0) {
        ball.velocity.x = ball.velocity.x / newSpeed * speed;
        ball.velocity.y = ball.velocity.y / newSpeed * speed;
      }
    }

    for (Brick &brick : bricks) {
      if (brick.isDestroyed())
        continue;
      Rectangle brickRect = {brick.pos.x, brick.pos.y, brick.size.x,
                             brick.size.y};
      if (!CheckCollisionCircleRec(ball.pos, ball.radius, brickRect))
        continue;

      float overlapLeft = ball.pos.x + ball.radius - brick.pos.x;
      float overlapRight =
          brick.pos.x + brick.size.x - (ball.pos.x - ball.radius);
      float overlapTop = ball.pos.y + ball.radius - brick.pos.y;
      float overlapBottom =
          brick.pos.y + brick.size.y - (ball.pos.y - ball.radius);

      bool bounceX = false, bounceY = false;
      if (overlapLeft < overlapRight && overlapLeft < overlapTop &&
          overlapLeft < overlapBottom) {
        ball.pos.x = brick.pos.x - ball.radius;
        bounceX = true;
      } else if (overlapRight < overlapLeft && overlapRight < overlapTop &&
                 overlapRight < overlapBottom) {
        ball.pos.x = brick.pos.x + brick.size.x + ball.radius;
        bounceX = true;
      } else if (overlapTop < overlapBottom && overlapTop < overlapLeft &&
                 overlapTop < overlapRight) {
        ball.pos.y = brick.pos.y - ball.radius;
        bounceY = true;
      } else {
        ball.pos.y = brick.pos.y + brick.size.y + ball.radius;
        bounceY = true;
      }
      if (bounceX)
        ball.velocity.x *= -1;
      if (bounceY)
        ball.velocity.y *= -1;

      brick.onBallHit();
      if (brick.isDestroyed()) {
        score += 10;
      }

      break;
    }
  }

  for (int i = 0; i < balls.size(); i++) {
    for (int j = i + 1; j < balls.size(); j++) {
      Ball &b1 = balls[i];
      Ball &b2 = balls[j];
      Vector2 d = {b2.pos.x - b1.pos.x, b2.pos.y - b1.pos.y};
      float dist2 = d.x * d.x + d.y * d.y;
      float radiusSum = b1.radius + b2.radius;
      if (dist2 <= radiusSum * radiusSum && dist2 > 0.0f) {
        float dist = sqrt(dist2);
        float overlap = radiusSum - dist;
        Vector2 normal = {d.x / dist, d.y / dist};
        b1.pos.x -= normal.x * (overlap * 0.5f);
        b1.pos.y -= normal.y * (overlap * 0.5f);
        b2.pos.x += normal.x * (overlap * 0.5f);
        b2.pos.y += normal.y * (overlap * 0.5f);

        Vector2 vrel = {b1.velocity.x - b2.velocity.x,
                        b1.velocity.y - b2.velocity.y};
        Vector2 dd = {b1.pos.x - b2.pos.x, b1.pos.y - b2.pos.y};
        float d2 = dd.x * dd.x + dd.y * dd.y;
        if (d2 <= 0.0f)
          continue;
        float dot = (vrel.x * dd.x + vrel.y * dd.y) / d2;
        b1.velocity.x -= dot * dd.x;
        b1.velocity.y -= dot * dd.y;
        b2.velocity.x += dot * dd.x;
        b2.velocity.y += dot * dd.y;
      }
    }
  }
}
