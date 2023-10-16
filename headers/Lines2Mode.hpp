#pragma once

#include "Line.hpp"
#include "Mode.hpp"

#include <cmath>

class Lines2Mode : public Mode
{
  protected:
  std::vector<QPoint> calculatePoints() override;

  virtual void initializeLine() = 0;

  virtual int countStartError()                           = 0;
  virtual int countHorizontalError(int x, int error)      = 0;
  virtual int countVerticalError(int y, int error)        = 0;
  virtual int countDiagonalError(int x, int y, int error) = 0;

  private:
  std::shared_ptr<Line> line;
};