#pragma once

#include "Mode.hpp"

#include <QPainter>
#include <vector>

// class MainWindow;

class DrawableObject
{
  public:
  DrawableObject()                     = default;
  virtual void draw(QPainter& painter) = 0;
  virtual bool tryFinish(QPoint point) = 0;
  void         setMode(std::shared_ptr<Mode> mode);

  protected:
  std::shared_ptr<Mode> mode;
  std::vector<QPoint>   points;
};
