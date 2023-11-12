#include "../headers/BezierMode.hpp"
#include <cmath>
#include <memory>
#include <vector>

const int POINT_MULTIPLICATOR = 10;

BezierMode::BezierMode(std::shared_ptr<DrawableObject> currentObject)
    : CurveMode(currentObject)
{
  mainMatrix = Matrix({ { -1., 3., -3., 1. },
                        { 3., -6., 3., 0. },
                        { -3., 3., 0., 0. },
                        { 1., 0., 0., 0. } });
}

std::vector<std::shared_ptr<Point>> BezierMode::manageInputPoints()
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

Matrix BezierMode::setGeometryVector(int pointNumber,
                                     std::vector<std::shared_ptr<Point>> points)
{
  Matrix bezierGeometryVector = Matrix(
      { { double(points[pointNumber]->x()), double(points[pointNumber]->y()) },
        { double(points[pointNumber + 1]->x()),
          double(points[pointNumber + 1]->y()) },
        { double(points[pointNumber + 2]->x()),
          double(points[pointNumber + 2]->y()) },
        { double(points[pointNumber + 3]->x()),
          double(points[pointNumber + 3]->y()) } });
  return bezierGeometryVector;
}
