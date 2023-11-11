#pragma once

#include "Curve.hpp"
#include "DrawableObject.hpp"
#include "Matrix.hpp"
#include "Mode.hpp"
#include "Point.hpp"
#include <memory>
#include <vector>

class MainWindow;

class HermiteMode : public Mode
{
  public:
  HermiteMode(std::shared_ptr<DrawableObject> currentLine);

  std::vector<Point> calculatePoints() override final;
  Point              getPoint(double time, Matrix multiplicateMatrix) const;

  private:
  std::shared_ptr<Curve> curveObject;
  Matrix                 hermiteMatrix = Matrix({ { 2., -2., 1., 1. },
                                                  { -3., 3., -2., -1. },
                                                  { 0., 0., 1., 0. },
                                                  { 1., 0., 0., 0. } });
  Matrix                 hermiteGeometryVector;
};