#pragma once

#include "Line.hpp"
#include "Mode.hpp"
#include <cmath>
#include <memory>

class WuMode : public Mode
{
  public:
  WuMode(std::shared_ptr<Line> currentLine)
      : line(currentLine){};
  std::vector<QPoint> calculatePoints() override;
  void addPoint(std::vector<QPoint>& points, int x, int y, bool inverted) const;

  private:
  std::shared_ptr<Line> line;
};