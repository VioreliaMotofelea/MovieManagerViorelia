#include <QApplication>

#include "src/gui/mainwindow.h"
#include "src/gui/Connecter.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Service service;

    mainWindow w(nullptr, service);
    Connecter c(&w);
    c.connectAll();

    w.show();

    return QApplication::exec();
}
