#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QQmlContext>

#include "src/LanguageModel.h"
#include "src/Keyboard.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<LanguageModel>("VirtualKeyboard", 1, 0, "LanguageData");
    qmlRegisterType<Keyboard>("VirtualKeyboard", 1, 0, "KeyboardData");

    LanguageModel languageModel;
    Keyboard keyboard;
    KeyboardLayer keyboardLayer;

    // Printing the LanguageModel
    languageModel.printKeyboards();
    // Printing the Keyboard
    keyboard.printKeyBoardLayers();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
