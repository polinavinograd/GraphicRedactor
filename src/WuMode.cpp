#include "../headers/WuMode.hpp"
#include "../headers/mainwindow.hpp"

int ipart(float x)
{
  return static_cast<int>(x);
}

float fpart(float x)
{
  return x - ipart(x);
}

std::vector<Point> WuMode::calculatePoints()
{
  std::vector<Point> result;

  float x1 = line->getStart()->x();
  float x2 = line->getEnd()->x();
  float y1 = line->getStart()->y();
  float y2 = line->getEnd()->y();

  bool inverted = false;

  if (std::abs(x1 - x2) < std::abs(y1 - y2))
  {
    inverted = true;
    std::swap(x1, y1);
    std::swap(x2, y2);
  }

  if (x2 < x1)
  {
    std::swap(x1, x2);
    std::swap(y1, y2);
  }

  float dx   = x2 - x1;
  float dy   = y2 - y1;
  float grad = dy / dx;

  int   xend = round(x1);
  int   yend = y1 + grad * (xend - x1);
  float xgap = 1 - fpart(x1 + 0.5);

  int xpxl1 = xend;
  int ypxl1 = ipart(yend);

  addPoint(result, xpxl1, ypxl1, inverted);

  float intery = yend + grad;

  xend = round(x2);
  yend = y2 + grad * (xend - x2);
  xgap = fpart(x2 + 0.5);

  int xpxl2 = xend;
  int ypxl2 = ipart(yend);

  addPoint(result, xpxl2, ypxl2, inverted);

  for (int x = xpxl1 + 1; x < xpxl2; x++)
  {
    addPoint(result, x, ipart(intery), inverted);
    addPoint(result, x, ipart(intery) + 1, inverted);
    intery += grad;
  }
  return result;
}

void WuMode::addPoint(std::vector<Point>& points,
                      int                 x,
                      int                 y,
                      bool                inverted) const
{
  if (inverted)
  {
    points.emplace_back(Point(y, x));
  }
  else
  {
    points.emplace_back(Point(x, y));
  }
}