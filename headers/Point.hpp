#pragma once

#include <QPoint>
#include <memory>

class Point : public QPoint
{
  public:
  Point() = default;
  Point(int x, int y);
  Point(QPoint point);

  Point& toScreenPoint(const Point& zeroPoint);

  int x() const;
  int y() const;

  private:
  int    x_pos    = 0;
  int    y_pos    = 0;
  int    z_pos    = 0;
  double rotation = 0;
};
