#pragma once

#include "Curve.hpp"
#include "DrawableObject.hpp"
#include "Matrix.hpp"
#include "Mode.hpp"
#include "Point.hpp"

#include <cmath>
#include <memory>
#include <vector>

class MainWindow;

class CurveMode : public Mode
{
  public:
  CurveMode() = default;
  CurveMode(std::shared_ptr<DrawableObject> currentObject)
      : curveObject(currentObject){};

  Point              getPoint(double time, Matrix multiplicateMatrix) const;
  std::vector<Point> calculatePoints() override final;
  virtual std::vector<std::shared_ptr<Point>> manageInputPoints() = 0;
  virtual Matrix                              setGeometryVector(
                                   int pointNumber, std::vector<std::shared_ptr<Point>> points) = 0;

  protected:
  std::shared_ptr<DrawableObject> curveObject;
  Matrix                          mainMatrix;

  private:
  Matrix geometryVector;
};