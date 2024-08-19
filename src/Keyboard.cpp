#include "Keyboard.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

Keyboard::Keyboard(QObject *parent)
    : QObject{parent}
{
    setLanguage("english");
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

QVariantList Keyboard::parseKeyboardLayers() const
{
    QVariantList list;
    for (auto it = m_layers.constBegin(); it != m_layers.constEnd(); ++it) {
        list.append(it.key());
        qDebug() << "Layers : " << it.key();
    }
    return list;
}

QVariantList Keyboard::parseKeyboardRows() const
{
    QVariantList list;
    if (!m_currentLayer.isEmpty() && m_layers.contains(m_currentLayer)) {
        KeyboardLayer* layer = m_layers[m_currentLayer];
        for (auto it = layer->rows().constBegin(); it != layer->rows().constEnd(); ++it) {
            list.append(it.key());
            qDebug() << "Rows: " << it.key();
        }
    } else {
        qWarning() << "Current layer is null or not found";
    }
    return list;
}

QVariantList Keyboard::parseKeyboardKeys(int rowIndex) const {
    QVariantList list;
    if (!m_currentLayer.isEmpty() && m_layers.contains(m_currentLayer)) {
        KeyboardLayer* layer = m_layers[m_currentLayer];
        // Get the keys as a QList to use indexing
        QList<KeyboardRow*> rows = layer->rows().values();  // Get all rows as a QList

        if (rowIndex >= 0 && rowIndex < rows.size()) {
            KeyboardRow* row = rows.at(rowIndex);  // Use QList's at() method
            for (const KeyboardKey* key : row->keys()) {
                QVariantMap keyData;
                keyData["text"] = key->text();
                keyData["key"] = key->key();
                keyData["altUpperKey"] = key->alternativeUpperCaseKey();
                keyData["altLowerKey"] = key->alternativeLowerCaseKey();
                keyData["color"] = key->color();
                keyData["width"] = key->width();
                keyData["height"] = key->height();
                keyData["pressedColor"] = key->pressedColor();
                list.append(keyData);
            }
        } else {
            qWarning() << "Row index out of bounds";
        }
    } else {
        qWarning() << "Current layer or row is null or not found";
    }
    return list;
}

QVariantList Keyboard::parseKeyboardKeysRow1() {
    return parseKeyboardKeys(0);  // First row
}

QVariantList Keyboard::parseKeyboardKeysRow2() {
    return parseKeyboardKeys(1);  // Second row
}

QVariantList Keyboard::parseKeyboardKeysRow3() {
    return parseKeyboardKeys(2);  // Third row
}

QVariantList Keyboard::parseKeyboardKeysRow4() {
    return parseKeyboardKeys(3);  // Fourth row (if any)
}

void Keyboard::setLanguage(const QString &language)
{
    qDebug() << "Setting language to:" << language;  // Debugging line
    QString filename = ":/data/keyboard_data_" + language + ".json";
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open" << filename;
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(jsonData));
    QJsonObject jsonObject = doc.object();

    qDeleteAll(m_layers);
    m_layers.clear();

    initializeFromJson(jsonObject);

    if (!m_layers.isEmpty()) {
        m_currentLayer = m_layers.keys().first();
    } else {
        m_currentLayer.clear();
    }

    qDebug() << "Current layer after setting language:" << m_currentLayer;
    qDebug() << "Loaded layers:" << m_layers.keys();
}

void Keyboard::setLayer(const QString &layer)
{
    if (!layer.isEmpty() && m_layers.contains(layer)) {
        m_currentLayer = layer;
    } else {
        qWarning() << "Layer" << layer << "not found or layer name is empty";
    }
}
