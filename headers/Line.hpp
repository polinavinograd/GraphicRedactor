#pragma once

#include "DrawableObject.hpp"

#include "Point.hpp"
#include <QPainter>
#include <memory>
#include <vector>

class Line : public DrawableObject
{
  public:
  Line() = default;
  bool tryFinish(Point point) override;
  // void draw(QPainter& painter) override;
};
