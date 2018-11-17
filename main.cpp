#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Until/ringmem.h"
#include <iostream>

int main(int argc, char *argv[])
{
    /*
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
    */

    RingMem<int> ring(20);

    for (unsigned val=0; val<27; ++val) {
        ring.add(val);
    }

    std::cout << "Ring data: ";
    for (unsigned i=0; i<20; ++i) {
        std::cout << ring.at(i) << ", ";
    }
    std::cout << std::endl;
}
