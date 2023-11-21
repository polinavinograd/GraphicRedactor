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
  Matrix hermiteGeometryVector = Matrix(
      { { double(points[pointNumber]->x()), double(points[pointNumber]->y()) },
        { double(points[pointNumber + 3]->x()),
          double(points[pointNumber + 3]->y()) },
        { std::abs(
              double(points[pointNumber + 1]->x() - points[pointNumber]->x())),
          std::abs(double(points[pointNumber + 1]->y() -
                          points[pointNumber]->y())) },
        { std::abs(double(points[pointNumber + 2]->x() -
                          points[pointNumber + 3]->x())),
          std::abs(double(points[pointNumber + 2]->y() -
                          points[pointNumber + 3]->y())) } });

  return hermiteGeometryVector;
}
