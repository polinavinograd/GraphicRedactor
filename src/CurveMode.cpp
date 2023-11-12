#include "../headers/CurveMode.hpp"

const int POINT_MULTIPLICATOR = 10;

Point CurveMode::getPoint(double time, Matrix multiplicateMatrix) const
{
  auto mulMatrix = Matrix({ std::pow(time, 3), std::pow(time, 2), time, 1 });
  auto result    = (mulMatrix * mainMatrix * multiplicateMatrix).getData()[0];
  return { (int)result[0], (int)result[1] };
}

std::vector<Point> CurveMode::calculatePoints()
{
  std::vector<std::shared_ptr<Point>> points = manageInputPoints();

  std::vector<Point> result;

  for (int i = 0; i < points.size() - 3; i++)
  {
    geometryVector = setGeometryVector(i, points);
    int maxTime    = std::max(std::abs(points[i]->x() - points[i + 3]->x()),
                           std::abs(points[i]->y() - points[i + 3]->y())) *
                      POINT_MULTIPLICATOR +
                  2000;

    for (int time = 0; time <= maxTime; time++)
    {
      result.emplace_back(getPoint((double)(time) / maxTime, geometryVector) -
                          points[i + 3].get()->toScreenPoint(*points[0].get()));
    }
  }
  return result;
}
