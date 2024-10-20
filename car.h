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
    Car(int id=0,double speed = 100.0,double frequence=QRandomGenerator::global()->bounded(10, 300));

    void updatePosition(qreal elapsedTime,QVector<Car*> allCars);
    void draw(QPainter& painter) const;
    QString toString()const;
    QPointF getPos()const;

    int getRadius()const;
    void resetPosition();

    double getFrequence() const;

    int getId() const;

private:
    QPointF position;
    qreal speed;
    QPixmap carImg;
    double frequence;
    int id;

public:
};


#endif // CAR_H
