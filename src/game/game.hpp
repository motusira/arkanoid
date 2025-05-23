#ifndef GAME_HPP
#define GAME_HPP

#include "../game_board/game_board.hpp"
#include "../window/window.hpp"
#include "../input_handler/input_handler.hpp"
#include "../ui/ui.hpp"

typedef enum {
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
