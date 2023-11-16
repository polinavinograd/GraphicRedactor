#include "../headers/HermiteMode.hpp"
#include <cmath>
#include <memory>
#include <vector>

const int POINT_MULTIPLICATOR = 10;

HermiteMode::HermiteMode(std::shared_ptr<DrawableObject> currentObject)
    : curveObject(std::dynamic_pointer_cast<Curve>(currentObject))
{
}

void HermiteMode::setPoints(const Point &newStartPoint, const Point &newEndPoint, const Point& newStartPointTangent, const Point& newEndPointTangent)
{
    auto startPointTangent = newStartPointTangent - newStartPoint;
    auto endPointTangent = newEndPointTangent - newEndPoint;

    multiplicateMatrix = Matrix(
        {
            {static_cast<double>(newStartPoint.x()),     static_cast<double>(newStartPoint.y())},
            {static_cast<double>(newEndPoint.x()),       static_cast<double>(newEndPoint.y())},
            {static_cast<double>(startPointTangent.x()), static_cast<double>(startPointTangent.y())},
            {static_cast<double>(endPointTangent.x()),   static_cast<double>(endPointTangent.y())}
        });
}

Point HermiteMode::getPoint(double time) const
{
  auto mulMatrix = Matrix({ std::pow(time, 3), std::pow(time, 2), time, 1 });
  auto result = (mulMatrix * hermiteMatrix * multiplicateMatrix).getData()[0];
  return Point(result[0], result[1]);
}

std::vector<Point> HermiteMode::calculatePoints()
{
  std::vector<Point> points;
  auto refPoints = curveObject->getInputPoints();
  Point startPoint = *refPoints[0].get();

  for (int i = 0; i < refPoints.size(); ++i)
  {
      points.emplace_back(refPoints[i]->x() - startPoint.x(), startPoint.y() - refPoints[i]->y());
  }

  // Actual method
  setPoints(points[0], points[1], points[2], points[3]);

  std::vector<Point> result;

  auto delta = points[0] - points[1];
  int maxTime = std::max(std::abs(delta.x()), std::abs(delta.y())) * POINT_MULTIPLICATOR + 1000;

  for (int time = 0; time <= maxTime; time++)
  {
      result.emplace_back((getPoint((double)(time)/maxTime) - points[3]).toScreenPoint(*refPoints[0].get()));
  }

  return result;
}
