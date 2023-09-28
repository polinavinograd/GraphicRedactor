#pragma once

#include "DrawableObject.hpp"

#include <QPainter>
#include <QPoint>
#include <vector>

class Line : public DrawableObject
{
  public:
  Line() = default;
  bool    tryFinish(QPoint point) override;
  void    draw(QPainter& painter) override;
  QPoint* getStart();
  QPoint* getEnd();

  private:
  QPoint* start = nullptr;
  QPoint* end   = nullptr;
};
