#include "hexagon.h"
#include <QPainter>
#include <cmath>

Hexagon::Hexagon(float x, float y, float radius) : x(x), y(y), radius(radius) {}

void Hexagon::draw(QPainter &painter) const {
    painter.setBrush(Qt::lightGray);
    painter.setPen(Qt::black);


    QPointF points[6];
    for (int i = 0; i < 6; ++i) {
        double angle = M_PI / 3 * i;
        points[i] = QPointF(x + radius * cos(angle), y + radius * sin(angle));
    }

    painter.drawPolygon(points, 6); // Draw the hexagon
}

