#pragma once

#include "Mode.hpp"

#include <QPainter>
#include <memory>
#include <vector>

class DrawableObject
{
  public:
  DrawableObject() = default;
  void                   draw(QPainter& painter);
  virtual bool           tryFinish(Point point) = 0;
  void                   setMode(std::shared_ptr<Mode> mode);
  void                   setFinished();
  std::shared_ptr<Point> getStart();
  std::shared_ptr<Point> getEnd();

  protected:
  std::shared_ptr<Mode>  mode;
  std::vector<Point>     points;
  std::shared_ptr<Point> start    = nullptr;
  std::shared_ptr<Point> end      = nullptr;
  bool                   finished = false;
};
