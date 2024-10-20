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
    void generateHexagons();
    std::vector<Hexagon> hexagons;
    int numRows;
    int numCols;
    float radius;
};

#endif // MAINWINDOW_H
