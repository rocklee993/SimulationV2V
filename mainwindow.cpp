#include "mainwindow.h"
#include <QPainter>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), numRows(20), numCols(30), radius(40) { // Adjust radius as needed
    generateHexagons();
    resize(1200, 800); // Set the desired width and height for the window
}

MainWindow::~MainWindow() {}

void MainWindow::generateHexagons() {
    float hexHeight = sqrt(3) * radius; // Calculate height based on radius

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            // Calculate x position
            float x = col * (1.5 * radius); // Space between columns

            // Calculate y position
            float y = row * hexHeight; // Base vertical position
            if (col % 2 != 0) {
                y += hexHeight / 2; // Offset for odd columns
            }

            hexagons.push_back(Hexagon(x, y, radius)); // Create the hexagon
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    for (const auto &hex : hexagons) {
        hex.draw(painter); // Draw each hexagon
    }
}
