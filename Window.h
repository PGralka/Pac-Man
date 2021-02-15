#pragma once

#include "Board.h"
#include <QWindow>

class Window : public QWindow {
  private:
	Board board;

  public:
	Window();
	Window(int width, int height);
};
