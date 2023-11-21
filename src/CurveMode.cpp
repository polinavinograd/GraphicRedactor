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

  // for (int i = 0; i < points.size() - 3; i++)
  // {
  //   geometryVector = setGeometryVector(i, points);
  //   int maxTime    = std::max(std::abs(points[i]->x() - points[i + 3]->x()),
  //                          std::abs(points[i]->y() - points[i + 3]->y())) *
  //                     POINT_MULTIPLICATOR +
  //                 2000;

  //   for (int time = 0; time <= maxTime; time++)
  //   {
  //     result.emplace_back(getPoint((double)(time) / maxTime, geometryVector)
  //     -
  //                         points[i +
  //                         3].get()->toScreenPoint(*points[0].get()));
  //   }
  // }

  // std::shared_ptr<Curve> curve =
  // std::dynamic_pointer_cast<Curve>(curveObject);
  // std::vector<std::shared_ptr<Point>> points = curve->getInputPoints();

  geometryVector = setGeometryVector(0, points);

  Matrix polynom = (mainMatrix * geometryVector).transpose();
  std::vector<std::vector<double>> data = polynom.getData();

  for (double t = points[0]->x(); t <= points[3]->x(); t += 0.001)
  {
    std::vector<double> interpolationRow;
    for (int i = 0; i < data.size(); i++)
    {
      double res         = 0;
      double multiplying = 1;

      for (int j = data[i].size() - 1; j > -1; j--)
      {
        res += multiplying * data[i][j];
        multiplying *= t;
      }
      interpolationRow.emplace_back(static_cast<int>(res));
    }
    result.emplace_back(Point(interpolationRow[0], interpolationRow[1]));
  }

  return result;
}
