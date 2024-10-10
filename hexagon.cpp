#include "hexagon.h"
#include <QPainter>
#include <cmath>

Hexagon::Hexagon(float x, float y, float radius) : x(x), y(y), radius(radius) {}

void Hexagon::draw(QPainter &painter) const { // Add const here
    painter.setBrush(Qt::lightGray); // Fill color
    painter.setPen(Qt::black); // Outline color

    // Calculate the points of the hexagon
    QPointF points[6];
    for (int i = 0; i < 6; ++i) {
        double angle = M_PI / 3 * i; // 60 degrees in radians
        points[i] = QPointF(x + radius * cos(angle), y + radius * sin(angle)); // Adjust the size
    }

    painter.drawPolygon(points, 6); // Draw the hexagon
}

