#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "hexagon.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void generateHexagons(); // Declaration of the function
    std::vector<Hexagon> hexagons; // Vector to store hexagons
    int numRows;
    int numCols;
    float radius; // Radius of the hexagons
};

#endif // MAINWINDOW_H
