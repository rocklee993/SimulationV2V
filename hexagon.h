#ifndef HEXAGON_H
#define HEXAGON_H

#include <QPainter>

class Hexagon {
public:
    Hexagon(float x, float y, float radius);
    void draw(QPainter &painter) const;

private:
    float x, y;
    float radius;
};

#endif // HEXAGON_H
