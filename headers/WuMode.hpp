#pragma once

#include "Line.hpp"
#include "Mode.hpp"
#include <cmath>
#include <memory>

class MainWindow;

class WuMode : public Mode
{
  public:
  WuMode(std::shared_ptr<Line>       currentLine,
         std::shared_ptr<MainWindow> newWindow)
      : line(currentLine)
      , window(newWindow){};
  std::vector<Point> calculatePoints() override final;
  void addPoint(std::vector<Point>& points, int x, int y, bool inverted) const;

  private:
  std::shared_ptr<Line>       line;
  std::shared_ptr<MainWindow> window;
};