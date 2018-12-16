#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Models/wormmodel.h"
#include "Controler/wormcontroler.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<WormModel>("Models", 1, 0, "WormModel");
    qmlRegisterType<WormControler>("Controler", 1, 0, "WormControler");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
