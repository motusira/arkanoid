#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include <vector>

#include "../brick/brick.hpp"
#include "ball/ball.hpp"
#include "paddle/paddle.hpp"

class GameBoard {
public:
public:
  void update(void);
  void draw(void);
  void init(int winWidth, int winHeight);
  void update(float dt);
private:
  int width;
  int height;
  int topOffset;
  int score;
  std::vector<Brick> bricks;
  std::vector<Ball> balls;
  Paddle paddle;
private:
  void handleBallCollisions();
};

#endif
