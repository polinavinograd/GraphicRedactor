#pragma once

#include "Line.hpp"
#include "Mode.hpp"

#include <cmath>

class MainWindow;

class Lines2Mode : public Mode
{
  public:
  Lines2Mode() = default;
  Lines2Mode(std::shared_ptr<Line>       currentLine,
             std::shared_ptr<MainWindow> newWindow)
      : line(currentLine)
      , window(newWindow){};

  protected:
  std::shared_ptr<MainWindow> window;
  std::shared_ptr<Line>       line;

  std::vector<QPoint> calculatePoints() override;

  virtual void initializeLine() = 0;

  virtual int countStartError()                           = 0;
  virtual int countHorizontalError(int x, int error)      = 0;
  virtual int countVerticalError(int y, int error)        = 0;
  virtual int countDiagonalError(int x, int y, int error) = 0;

  bool stopCondition(int x, int y);
};