#include "../headers/Point.hpp"

Point::Point(int x, int y)
    : x_pos(x)
    , y_pos(y){};

Point::Point(QPoint point)
    : x_pos(point.x())
    , y_pos(point.y()){};

Point& Point::toScreenPoint(const Point& zeroPoint)
{
  x_pos += zeroPoint.x_pos;
  y_pos = zeroPoint.y_pos - y_pos;
  return *this;
}

int Point::x() const
{
  return x_pos;
}
int Point::y() const
{
  return y_pos;
}

Point Point::operator-(const Point& right)
{
  return { x_pos - right.x_pos, y_pos - right.y_pos };
}
