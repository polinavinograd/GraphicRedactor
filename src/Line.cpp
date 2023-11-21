#include "../headers/Line.hpp"
#include <memory>

bool Line::tryFinish(Point point)
{
  if (!start)
  {
    start = std::make_shared<Point>(point);
    return false;
  }
  if (!end)
  {
    end      = std::make_shared<Point>(point);
    points   = mode->calculatePoints();
    finished = true;
  }
  return true;
}

void Line::setPoints() {}
