#pragma once

#include "DrawableObject.hpp"
#include "Point.hpp"
#include <memory>
#include <vector>

class Curve : public DrawableObject
{
  public:
  Curve() = default;
  bool                                tryFinish(Point point) override;
  std::vector<std::shared_ptr<Point>> getInputPoints();
  void                                setPoints() override final;

  protected:
  std::vector<std::shared_ptr<Point>> inputPoints;
};