#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include <vector>

#include "../brick/brick.hpp"
#include "paddle/paddle.hpp"

class GameBoard {
public:
public:
  void update(void);
  void draw(void);
  void init(int winWidth, int winHeight);
  void handle_input(float dt);
private:
  int width;
  int height;
  int topOffset;
  std::vector<Brick> bricks;
  Paddle paddle;
private:
};

#endif
