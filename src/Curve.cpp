#include "../headers/Curve.hpp"
#include "../headers/VSplineMode.hpp"
#include <memory>

std::vector<std::shared_ptr<Point>> Curve::getInputPoints()
{
  return inputPoints;
}

bool Curve::tryFinish(Point point)
{
  if (!start)
  {
    start = std::make_shared<Point>(point);
    inputPoints.emplace_back(start);
    return false;
  }
  if (!end)
  {
    if (!std::dynamic_pointer_cast<VSplineMode>(mode) &&
        inputPoints.size() == 3)
    {

      finished = true;
    }
    if (finished)
    {
      end = std::make_shared<Point>(point);
      inputPoints.emplace_back(end);
      points = mode->calculatePoints();
    }
    else
    {
      inputPoints.emplace_back(std::make_shared<Point>(point));
      return false;
    }
  }
  return true;
}