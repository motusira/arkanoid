#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

class GameBoard {
public:
public:
  GameBoard(int winWidth, int winHeight);
  void update(void);
  void draw(void);
private:
  int width;
  int height;
  int offsetX;
  int offsetY;
private:
};

#endif
