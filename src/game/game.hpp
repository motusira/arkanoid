#ifndef GAME_HPP
#define GAME_HPP

#include "../src/game_board/game_board.hpp"
#include "../src/window/window.hpp"
#include "../src/input_handler/input_handler.hpp"
#include "../src/ui/ui.hpp"

typedef enum {
    STATE_MENU,
    STATE_GAME,
    STATE_PAUSE
} State;

class Game {
public:
  void run(void);
private:
  GameBoard board;
  Window window;
  InputHandler input_handler;
  UI ui;
  State state;
private:
  void init(void);
  void draw(void);
  void handle_input(void);
  void update(void);
};

#endif
