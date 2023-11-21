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
  std::vector<std::shared_ptr<Point>> points = curveObject->getInputPoints();

  Point startPoint = *points[0].get();

  for (int i = 0; i < points.size(); i++)
  {
      points[i] = std::make_shared<Point>(points[i]->x() - startPoint.x(),
                                          startPoint.y() - points[i]->y());
  }

  hermiteGeometryVector =
      Matrix({ { double(points[0]->x()), double(points[0]->y()) },
              { double(points[3]->x()), double(points[3]->y()) },
              { double(points[1]->x() - points[0]->x()),
               double(points[1]->y() - points[0]->y()) },
              { double(points[3]->x() - points[2]->x()),
               double(points[3]->y() - points[2]->y()) } });

  std::vector<Point> result;
  Matrix polynom = (hermiteMatrix * hermiteGeometryVector);
  std::vector<std::vector<double>> data = polynom.getData();

   for (double t = points[0]->x(); t <= points[3]->x(); t += 0.001)
   {
     std::vector<double> interpolationRow;
     for (int i = 0; i < data.size(); i++)
     {
       double res         = 0;
       double multiplying = 1;

      for (int j = data[i].size(); j > -1; j--)
      {
        res += multiplying * data[i][j];
        multiplying *= t;
      }

      interpolationRow.emplace_back(static_cast<int>(res));
    }

    result.emplace_back(Point(interpolationRow[0], interpolationRow[1]).toScreenPoint(startPoint));
  }

  return result;
}
