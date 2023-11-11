#pragma once

#include "DrawableObject.hpp"
#include "Mode.hpp"
#include "Point.hpp"
#include <memory>

class MainWindow;

class BrazenhemLinesMode : public Mode
{
  public:
  BrazenhemLinesMode(std::shared_ptr<DrawableObject> currentLine,
                     std::shared_ptr<MainWindow>     newWindow)
      : line(currentLine)
      , window(newWindow){};
  std::vector<Point> calculatePoints() override final;

  private:
  std::shared_ptr<DrawableObject> line;
  std::shared_ptr<MainWindow>     window;
};