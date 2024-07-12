#include "Keyboard.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

Keyboard::Keyboard(QObject *parent)
    : QObject{parent}
{
    QString filename = ":/data/keyboard_data_english.json";
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open" << filename;
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(jsonData));
    QJsonObject jsonObject = doc.object();

    initializeFromJson(jsonObject);
}

void Keyboard::initializeFromJson(const QJsonObject &json)
{
    QJsonObject layersObject = json["layers"].toObject();
    for (const QString &layerName : layersObject.keys()) {
        QJsonObject layerObject = layersObject[layerName].toObject();
        m_layers[layerName] = new KeyboardLayer(this);
        m_layers[layerName]->initializeFromJson(layerObject);
    }
}

void Keyboard::printKeyBoardLayers() const
{
    qDebug() << "Printing all the layers :";
    for (auto it = m_layers.constBegin(); it != m_layers.constEnd(); ++it) {
        qDebug() << it.key();
        it.value()->printKeyboardRows();
    }
    qDebug() << Qt::endl;
}
