#include "../headers/VSplineMode.hpp"
#include <cmath>
#include <memory>
#include <vector>

VSplineMode::VSplineMode(std::shared_ptr<DrawableObject> currentObject)
    : CurveMode(currentObject)
{
  mainMatrix = Matrix({ { -1., 3., -3., 1. },
                        { 3., -6., 3., 0. },
                        { -3., 0., 3., 0. },
                        { 1., 4., 1., 0. } }) *
               (1. / 6);
}

std::vector<std::shared_ptr<Point>> VSplineMode::manageInputPoints()
{
  std::shared_ptr<Curve> curve = std::dynamic_pointer_cast<Curve>(curveObject);
  std::vector<std::shared_ptr<Point>> points = curve->getInputPoints();

  Point startPoint = *points[0].get();

  for (int i = 0; i < points.size(); i++)
  {
    points[i] = std::make_shared<Point>(points[i]->x() - startPoint.x(),
                                        startPoint.y() - points[i]->y());
  }

  points.emplace_back(points[0]);
  points.emplace_back(points[1]);
  points.emplace_back(points[2]);
  return points;
}

Matrix VSplineMode::setGeometryVector(
    int pointNumber, std::vector<std::shared_ptr<Point>> points)
{
  Matrix geometryVector = Matrix(
      { { double(points[pointNumber]->x()), double(points[pointNumber]->y()) },
        { double(points[pointNumber + 1]->x()),
          double(points[pointNumber + 1]->y()) },
        { double(points[pointNumber + 2]->x()),
          double(points[pointNumber + 2]->y()) },
        { double(points[pointNumber + 3]->x()),
          double(points[pointNumber + 3]->y()) } });
  return geometryVector;
}
