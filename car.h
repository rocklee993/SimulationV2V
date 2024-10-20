#ifndef CAR_H
#define CAR_H

//
// Created by Rocklee
//

#pragma once
#include <qdebug.h>
#include <QPainter>
#include <QPointF>
#include <QPlainTextEdit>

#include <QPixmap>
#include<QRandomGenerator>
#include<cmath>

class Car {
public:
    Car(int id=0,
        double speed = 100.0,
        const QPixmap& car=QPixmap("car.png"),
        double frequence=QRandomGenerator::global()->bounded(10, 300)
        );

    void updatePosition(qreal elapsedTime,QVector<Car*> allCars);
    void draw(QPainter& painter) const;
    void logMessage(const QString &message, QPlainTextEdit *debugOutput )const;
    QString toString()const;
    QPointF getPosition()const;


    int getRadius()const;
    void resetPosition();

    double getFrequence() const;


    int getId() const;

private:
    QPointF position;
    qreal speed;
    const PathNode* destinationPathHead;
    PathNode* nextDestinationNode;
    QPixmap carImage;
    double frequence;
    QVector<Car*> connectedCars;
    int id;
public:
    const QVector<Car *> &getConnectedCars() const;



public:
};




#endif // CAR_H
