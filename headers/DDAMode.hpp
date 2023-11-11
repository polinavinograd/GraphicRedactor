#pragma once

#include "DrawableObject.hpp"
#include "Mode.hpp"

#include <cmath>
#include <memory>

class MainWindow;

class DDAMode : public Mode
{
  public:
  DDAMode(std::shared_ptr<DrawableObject> currentLine,
          std::shared_ptr<MainWindow>     newWindow)
      : line(currentLine)
      , window(newWindow){};
  std::vector<Point> calculatePoints() override;

  private:
  std::shared_ptr<DrawableObject> line;
  std::shared_ptr<MainWindow>     window;
};