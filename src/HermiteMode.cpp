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

Point hermite(float t, Point P1, Point P2, Point R1, Point R2)
{
  float h1 = 2 * pow(t, 3) - 3 * pow(t, 2) + 1;
  float h2 = -2 * pow(t, 3) + 3 * pow(t, 2);
  float h3 = pow(t, 3) - 2 * pow(t, 2) + t;
  float h4 = pow(t, 3) - pow(t, 2);

  int x = h1 * P1.x() + h2 * P2.x() + h3 * R1.x() + h4 * R2.x();
  int y = h1 * P1.y() + h2 * P2.y() + h3 * R1.y() + h4 * R2.y();

  return Point(x, y);
}

std::vector<Point> HermiteMode::calculatePoints()
{
  auto data = curveObject->getInputPoints();

  Point P1 = *data[0].get();
  Point P2 = *data[3].get();
  Point R1 = *data[1].get();
  Point R2 = *data[2].get();

  std::vector<Point> result;
  for (float t = 0; t <= 1; t += 0.001)
  {
      Point p = hermite(t, P1, P2, R1, R2);
      result.emplace_back(p);
  }

  return result;
}
