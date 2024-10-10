#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);  // Initialiser l'application Qt
    MainWindow w;  // Créer la fenêtre principale
    w.show();  // Afficher la fenêtre
    return a.exec();  // Exécuter la boucle d'événements Qt
}
