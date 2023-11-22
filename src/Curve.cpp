#include "../headers/Curve.hpp"
#include "../headers/VSplineMode.hpp"
#include <iostream>
#include <memory>

std::vector<std::shared_ptr<Point>> Curve::getInputPoints()
{
  return inputPoints;
}

void Curve::setPoints()
{
  start       = std::make_shared<Point>(139, 334);
  end         = std::make_shared<Point>(404, 358);
  inputPoints = { start,
                  std::make_shared<Point>(210, 185),
                  std::make_shared<Point>(373, 185),
                  end };
  points      = mode->calculatePoints();
  for (auto& point : points)
  {
    point = { point.x() + start->x(), start->y() - point.y() };
  }
  std::cout << points.size() << std::endl;
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