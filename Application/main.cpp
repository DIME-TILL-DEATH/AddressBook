#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "clientmanager.h"
#include "contactsmodel.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    net::ConnectionArgumentsParser parser{*QCoreApplication::instance()};
    ClientManager::instance().setConnectionSettings(parser);
    ContactsModel::registerMe("Contacts");

    engine.addImportPath(":/qml");  // добавляем базовую директорию в пути импорта

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
