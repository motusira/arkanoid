#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include <vector>

#include "../brick/brick.hpp"

class GameBoard {
public:
public:
  void update(void);
  void draw(void);
  void init(int winWidth, int winHeight);
private:
  int width;
  int height;
  int topOffset;
  std::vector<Brick> bricks;
private:
};

#endif
