#include "../headers/BrazenhemLinesMode.hpp"

std::vector<QPoint> BrazenhemLinesMode::calculatePoints()
{
    std::vector<QPoint> result;

    int x = line->getStart()->x();
    int y = line->getStart()->y();

    int dx = line->getEnd()->x() - x;
    int dy = line->getEnd()->y() - y;

    float error = 2 * dy - dx;

    for (int i = 1; i <= dx; i++)
    {
        if (error >= 0)
        {
            y -= 1;
            error -= 2 * dx;
        }
        x += 1;
        error += 2 * dy;
        result.emplace_back(QPoint(x, y));
    }

    return result;
}