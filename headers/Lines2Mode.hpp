#pragma once

#include "Line.hpp"
#include "Mode.hpp"
#include "Point.hpp"

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

  Point zero;

  std::vector<Point> calculatePoints() override;

  virtual void initializeLine() = 0;

  virtual int countStartError()                           = 0;
  virtual int countHorizontalError(int x, int error)      = 0;
  virtual int countVerticalError(int y, int error)        = 0;
  virtual int countDiagonalError(int x, int y, int error) = 0;

  virtual bool isDiagonalOrVertical(int error) const;
  virtual bool isDiagonalOrHorizontal(int error) const;

  virtual int deltaY() const;

  virtual int getStartX() = 0;
  virtual int getStartY() = 0;

  void         addPoint(std::vector<Point>& points, const Point& point) const;
  virtual void addPoints(std::vector<Point>& points, int x, int y) const;

  virtual bool stopCondition(int x, int y);
};