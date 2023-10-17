#pragma once

#include "Point.hpp"
#include <memory>
#include <vector>

class Mode
{
  public:
  virtual std::vector<Point> calculatePoints() = 0;
};