#include "window.hpp"
#include "raylib.h"

void Window::init(void) {
  InitWindow(width, height, "Arkanoid");
  SetTargetFPS(60);
}

int Window::getWidth(void) { return width; }

int Window::getHeight(void) { return height; }

Window::Window(void) {
  width = 1280;
  height = 720;
}

Window::~Window(void) { CloseWindow(); }
