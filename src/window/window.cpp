#include "window.hpp"
#include "raylib.h"

void Window::init(void) {
  InitWindow(width, height, "Arkanoid");
  SetTargetFPS(60);
}

Window::Window() {
  width = 1280;
  height = 720;
}

Window::~Window() {
  CloseWindow();
}
