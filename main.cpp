#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "LanguageModel.h"
#include "Keyboard.h"
#include "KeyboardLayer.h"
#include "KeyboardRow.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    LanguageModel languageModel;
    Keyboard keyboard;
    KeyboardLayer keyboardLayers;
    KeyboardRow keyboardRows;

    languageModel.printKeyboards();
    keyboard.printKeyBoardLayers();
    keyboardLayers.printKeyboardRows();
    keyboardRows.printKeyboardKeys();

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
