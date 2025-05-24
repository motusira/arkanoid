#ifndef GAME_HPP
#define GAME_HPP

#include "brick/brick.hpp"
#include "game_board/game_board.hpp"
#include "ui/ui.hpp"
#include "window/window.hpp"

#include <vector>

enum class State { STATE_GAME, STATE_PAUSE };

class Game {
public:
  void run(void);

private:
  GameBoard board;
  Window window;
  UI ui;
  State state;
  std::vector<Brick> bricks;

private:
  void init(void);
  void drawStart(void);
  void drawEnd(void);
  void handle_input(void);
  void update(void);
};

#endif
