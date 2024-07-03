#include "KeyboardRow.h"

#include <QDebug>

KeyboardRow::KeyboardRow(QObject *parent)
    : QObject{parent}
{
    addKey("Q", "Qt.Key_Q", "Q", "q");
    addKey("W", "Qt.Key_W", "W", "w");
    addKey("E", "Qt.Key_E", "E", "e");
    addKey("R", "Qt.Key_R", "R", "r");
    addKey("T", "Qt.Key_T", "T", "t");
    addKey("Y", "Qt.Key_Y", "Y", "y");
    addKey("U", "Qt.Key_U", "U", "u");
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
