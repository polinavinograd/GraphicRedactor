#pragma once

#include "Curve.hpp"
#include "CurveMode.hpp"
#include "DrawableObject.hpp"
#include "Matrix.hpp"
#include "Point.hpp"

#include <memory>
#include <vector>

class MainWindow;

class BezierMode : public CurveMode
{
  public:
  BezierMode(std::shared_ptr<DrawableObject> currentLine);
  std::vector<std::shared_ptr<Point>> manageInputPoints() override final;

  Matrix setGeometryVector(
      int                                 pointNumber,
      std::vector<std::shared_ptr<Point>> points) override final;
};