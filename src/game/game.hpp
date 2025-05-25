#ifndef GAME_HPP
#define GAME_HPP

#include "game_board/game_board.hpp"
#include "window/window.hpp"

enum class State { STATE_GAME, STATE_PAUSE };

class Game {
public:
  void run(void);

private:
  GameBoard board;
  Window window;
  State state;

private:
  void init(void);
  void drawStart(void);
  void drawEnd(void);
  void handle_input(float dt);
  void update(void);
};

#endif
