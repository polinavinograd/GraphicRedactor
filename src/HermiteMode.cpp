#include "../headers/HermiteMode.hpp"
#include <cmath>
#include <memory>
#include <vector>

const int POINT_MULTIPLICATOR = 10;

HermiteMode::HermiteMode(std::shared_ptr<DrawableObject> currentObject)
    : curveObject(std::dynamic_pointer_cast<Curve>(currentObject))
{
}

Point HermiteMode::getPoint(double time, Matrix multiplicateMatrix) const
{
  auto mulMatrix = Matrix({ std::pow(time, 3), std::pow(time, 2), time, 1 });
  auto result = (mulMatrix * hermiteMatrix * multiplicateMatrix).getData()[0];
  return { (int)result[0], (int)result[1] };
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
  Matrix polynom = (hermiteMatrix * hermiteGeometryVector).transpose();
  std::vector<std::vector<double>> data = polynom.getData();

  int maxTime = std::max(std::abs(points[0]->x() - points[3]->x()),
                         std::abs(points[0]->y() - points[3]->y())) *
                    POINT_MULTIPLICATOR +
                2000;

  for (int time = 0; time <= maxTime; time++)
  {
    result.emplace_back(
        getPoint((double)(time) / maxTime, hermiteGeometryVector) -
        points[3].get()->toScreenPoint(startPoint));
  }

  // for (double t = points[0]->x(); t <= points[3]->x(); t += 0.001)
  // {
  //   std::vector<double> interpolationRow;
  //   for (int i = 0; i < data.size(); i++)
  //   {
  //     double res         = 0;
  //     double multiplying = 1;

  //     for (int j = data[i].size(); j > -1; j--)
  //     {
  //       res += multiplying * data[i][j];
  //       multiplying *= t;
  //     }
  //     interpolationRow.emplace_back(static_cast<int>(res));
  //   }
  //   result.emplace_back(Point(interpolationRow[0], interpolationRow[1]));
  // }

  return result;
}