#include "KeyboardRow.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

KeyboardRow::KeyboardRow(QObject *parent)
    : QObject{parent}
{}

void KeyboardRow::initializeFromJson(const QJsonArray &json)
{
    for (const QJsonValue &value : json) {
        QJsonObject keyObject = value.toObject();
        QString text = keyObject["text"].toString();
        QString image = keyObject["image"].toString();
        QString key = keyObject["key"].toString();
        QString altUpperKey = keyObject["alternativeUpperCaseKey"].toString();
        QString altLowerKey = keyObject["alternativeLowerCaseKey"].toString();
        QString color = keyObject["color"].toString();
        QString width = keyObject["width"].toString();
        QString height = keyObject["height"].toString();
        QString pressedColor = keyObject["pressedColor"].toString();
        QList<QString> altKey;
        QJsonArray altKeyArray = keyObject["alternativeKeys"].toArray();
        for (const QJsonValue &altValue : altKeyArray) {
            altKey.append(altValue.toString());
        }
        addKey(text, image, key, altUpperKey, altLowerKey, color, width, height, pressedColor, altKey);
    }
}

void KeyboardRow::addKey(const QString &text, const QString &image, const QString &key, const QString &altUpperKey, const QString &altLowerKey, const QString &color, const QString width, const QString height, const QString pressedColor, const QList<QString> &altKey)
{
    m_keys.append(new KeyboardKey(text, image, key, altUpperKey, altLowerKey, color, width, height, pressedColor, altKey, this));
}

void KeyboardRow::printKeyboardKeys() const
{
    qDebug() << Q_FUNC_INFO << "Printing all keys :";
    for (const KeyboardKey* key : m_keys) { // Iterate over the list of keys
        qDebug() << Q_FUNC_INFO << "Key text: "
                 << key->text()
                 << "Key Image: "
                 << key->image()
                 << ", Key code: "
                 << key->key()
                 << ", Upper Case: "
                 << key->alternativeUpperCaseKey()
                 << ", Lower Case: "
                 << key->alternativeLowerCaseKey()
                 << ", Color: "
                 << key->color()
                 << ", Width: "
                 << key->width()
                 << ", Height: "
                 << key->height()
                 << ", PressedColor: "
                 << key->pressedColor()
                 << ", Alternative Key: "
                 << key->altKey();
    }
    qDebug() << Q_FUNC_INFO << Qt::endl;
}

QList<KeyboardKey *> KeyboardRow::keys() const
{
    return m_keys;
}

QVariantList KeyboardRow::getKeys() const
{
    QVariantList keysList;
    for (const auto& key : m_keys) {
        keysList.append(key->text());
    }
    return keysList;
}
