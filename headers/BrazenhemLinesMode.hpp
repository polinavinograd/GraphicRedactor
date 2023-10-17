#pragma once

#include "Line.hpp"
#include "Mode.hpp"
#include <memory>

class MainWindow;

class BrazenhemLinesMode : public Mode
{
  public:
  BrazenhemLinesMode(std::shared_ptr<Line>       currentLine,
                     std::shared_ptr<MainWindow> newWindow)
      : line(currentLine)
      , window(newWindow){};
  std::vector<QPoint> calculatePoints() override final;

  private:
  std::shared_ptr<Line>       line;
  std::shared_ptr<MainWindow> window;
};