#pragma once

#include "DrawableObject.hpp"

#include <QPainter>
#include <QPoint>
#include <qpoint.h>
#include <vector>

class Line : public DrawableObject
{
public:
    Line() = default;
    bool    isFinished(QPoint point) override;
    void    draw(std::shared_ptr<QPainter> painter) override;
    QPoint* getStart();
    QPoint* getEnd();

private:
    QPoint* start = nullptr;
    QPoint* end   = nullptr;
};
