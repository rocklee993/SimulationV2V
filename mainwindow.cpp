#include "mainwindow.h"
#include <QPainter>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), numRows(20), numCols(30), radius(40) {
    generateHexagons();
    resize(1200, 800);
}

MainWindow::~MainWindow() {}

void MainWindow::generateHexagons() {
    float hexHeight = sqrt(3) * radius;

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {

            float x = col * (1.5 * radius);


            float y = row * hexHeight;
            if (col % 2 != 0) {
                y += hexHeight / 2;
            }

            hexagons.push_back(Hexagon(x, y, radius));
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    for (const auto &hex : hexagons) {
        hex.draw(painter); // Draw each hexagon
    }
}
