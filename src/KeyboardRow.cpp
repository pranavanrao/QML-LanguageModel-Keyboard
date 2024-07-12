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
        addKey(text, key, altUpperKey, altLowerKey);
    }
}

void KeyboardRow::addKey(const QString &text, const QString &key, const QString &altUpperKey, const QString &altLowerKey)
{
    m_key[text] = new KeyboardKey(text, key, altUpperKey, altLowerKey, this);
}

void KeyboardRow::printKeyboardKeys() const
{
    qDebug() << "Printing all keys :";
    for (auto it = m_key.constBegin(); it != m_key.constEnd(); ++it) {
        qDebug() << "Key text: "
                 << it.key()
                 << ", Key code: "
                 << it.value()->key()
                 << ", Upper Case: "
                 << it.value()->alternativeUpperCaseKey()
                 << ", Lower Case: "
                 << it.value()->alternativeLowerCaseKey();
    }
    qDebug() << Qt::endl;
}
