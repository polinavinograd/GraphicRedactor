#pragma once

#include "Line.hpp"
#include "Mode.hpp"
#include <memory>

class BrazenhemLinesMode : public Mode
{
public:
    BrazenhemLinesMode(std::shared_ptr<Line> currentLine)
        : line(currentLine){};
    std::vector<QPoint> calculatePoints() override;

private:
    std::shared_ptr<Line> line;
};