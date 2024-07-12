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

    QString keyboardEnglish = ":/data/languages_data.json";
    QString keyboardArabic = ":/data/keyboard_data_arabic.json";
    QString keyboardGerman = ":/data/keyboard_data_german.json";
    QString keyboardJapanese = ":/data/keyboard_data_japanese.json";

    QFile file(keyboardEnglish);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open languages_data.json";
        return -1;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(jsonData));
    QJsonObject jsonObject = doc.object();

    LanguageModel languageModel;
    Keyboard keyboard;
    KeyboardLayer keyboardLayer;

    // Printing the LanguageModel
    languageModel.initializeFromJson(jsonObject);
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
