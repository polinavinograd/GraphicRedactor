#pragma once

#include "Line.hpp"
#include "Mode.hpp"

#include <cmath>
#include <memory>

class MainWindow;

class DDAMode : public Mode
{
  public:
  DDAMode(std::shared_ptr<Line>       currentLine,
          std::shared_ptr<MainWindow> newWindow)
      : line(currentLine)
      , window(newWindow){};
  std::vector<QPoint> calculatePoints() override;

  private:
  std::shared_ptr<Line>       line;
  std::shared_ptr<MainWindow> window;
};