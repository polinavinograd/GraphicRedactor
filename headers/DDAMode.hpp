#pragma once

#include "Line.hpp"
#include "Mode.hpp"

#include <cmath>

class DDAMode : public Mode
{
  public:
  DDAMode(std::shared_ptr<Line> currentLine)
      : line(currentLine){};
  std::vector<QPoint> calculatePoints() override final;

  private:
  std::shared_ptr<Line> line;
};