#include "../headers/HermiteMode.hpp"
#include <cmath>
#include <memory>
#include <vector>

const int POINT_MULTIPLICATOR = 10;

HermiteMode::HermiteMode(std::shared_ptr<DrawableObject> currentObject)
    : CurveMode(currentObject)
{
  mainMatrix = Matrix({ { 2., -2., 1., 1. },
                        { -3., 3., -2., -1. },
                        { 0., 0., 1., 0. },
                        { 1., 0., 0., 0. } });
}

std::vector<std::shared_ptr<Point>> HermiteMode::manageInputPoints()
{
  std::shared_ptr<Curve> curve = std::dynamic_pointer_cast<Curve>(curveObject);
  std::vector<std::shared_ptr<Point>> points     = curve->getInputPoints();
  Point                               startPoint = *points[0].get();

  for (int i = 0; i < points.size(); i++)
  {
    points[i] = std::make_shared<Point>(points[i]->x() - startPoint.x(),
                                        startPoint.y() - points[i]->y());
  }
  return points;
}

Matrix HermiteMode::setGeometryVector(
    int pointNumber, std::vector<std::shared_ptr<Point>> points)
{
  auto start       = *points[pointNumber];
  auto end         = *points[pointNumber + 3];
  auto startVector = *points[pointNumber + 1] - start;
  auto endVector   = *points[pointNumber + 2] - end;

  Matrix hermiteGeometryVector =
      Matrix({ { (double)start.x(), (double)start.y() },
               { (double)end.x(), (double)end.y() },
               { (double)startVector.x(), (double)startVector.y() },
               { (double)endVector.x(), (double)endVector.y() } });

  return hermiteGeometryVector;
}
