#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include <vector>

#include "../brick/brick.hpp"
#include "ball/ball.hpp"
#include "bonus/bonus.hpp"
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
  bool stickedBall;
  bool temporaryBottom;
  std::vector<Brick> bricks;
  std::vector<Ball> balls;
  std::vector<Bonus> bonuses;
  Paddle paddle;

private:
  void handleBallCollisions();
  void applyBonusEffect(BonusType type);
  void spawnExtraBall();
};

#endif
