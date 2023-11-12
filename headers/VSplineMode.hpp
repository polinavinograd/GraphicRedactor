#pragma once

#include "Curve.hpp"
#include "CurveMode.hpp"
#include "DrawableObject.hpp"
#include "Matrix.hpp"
#include "Point.hpp"
#include <memory>
#include <vector>

class MainWindow;

class VSplineMode : public CurveMode
{
  public:
  VSplineMode(std::shared_ptr<DrawableObject> currentLine);

  std::vector<std::shared_ptr<Point>> manageInputPoints() override final;

  Matrix setGeometryVector(
      int                                 pointNumber,
      std::vector<std::shared_ptr<Point>> points) override final;
};