#include "Car.h"
#include <QtMath>

// Constructor
Car::Car(int id, double speed, double frequence)
    : id(id), speed(speed), frequence(frequence) {

    position = QPointF(0, 0);

    carImg = QPixmap("car.png").scaledToWidth(30);
}


void Car::updatePosition(qreal elapsedTime, QVector<Car*> allCars) {

    qreal deltaX = speed * elapsedTime;
    qreal deltaY = speed * elapsedTime * qSin(45);

    position += QPointF(deltaX, deltaY);


    for (const Car* otherCar : allCars) {
        if (otherCar->getId() != this->getId()) {

            qreal distance = qSqrt(qPow(position.x() - otherCar->getPos().x(), 2) + qPow(position.y() - otherCar->getPos().y(), 2));
            if (distance < frequence + otherCar->getRadius()) {

            }
        }
    }
}

void Car::draw(QPainter& painter) const {

    painter.setBrush(Qt::blue);
    painter.drawEllipse(position, frequence, frequence);


    painter.drawPixmap(position.toPoint() - QPoint(carImg.width() / 2, carImg.height() / 2), carImg);
}


QString Car::toString() const {
    return QString("Car #%1: Position=(%2, %3), Speed=%4, Frequency=%5")
    .arg(id)
        .arg(position.x())
        .arg(position.y())
        .arg(speed)
        .arg(frequence);
}


QPointF Car::getPos() const {
    return position;
}

int Car::getRadius() const {
    return static_cast<int>(frequence);
}


void Car::resetPosition() {
    position = QPointF(0, 0);
}


double Car::getFrequence() const {
    return frequence;
}

int Car::getId() const {
    return id;
}
//doesnt work yet
