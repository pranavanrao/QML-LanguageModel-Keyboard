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
        QString key = keyObject["key"].toString();
        QString altUpperKey = keyObject["alternativeUpperCaseKey"].toString();
        QString altLowerKey = keyObject["alternativeLowerCaseKey"].toString();
        QString color = keyObject["color"].toString();
        QString width = keyObject["width"].toString();
        QString height = keyObject["height"].toString();
        QString pressedColor = keyObject["pressedColor"].toString();
        addKey(text, key, altUpperKey, altLowerKey, color, width, height, pressedColor);
    }
}

void KeyboardRow::addKey(const QString &text, const QString &key, const QString &altUpperKey, const QString &altLowerKey, const QString &color, const QString width, const QString height, const QString pressedColor)
{
    m_keys.append(new KeyboardKey(text, key, altUpperKey, altLowerKey, color, width, height, pressedColor, this));
}

void KeyboardRow::printKeyboardKeys() const
{
    qDebug() << "Printing all keys :";
    for (const KeyboardKey* key : m_keys) { // Iterate over the list of keys
        qDebug() << "Key text: "
                 << key->text()
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
                 << key->pressedColor();
    }
    qDebug() << Qt::endl;
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
