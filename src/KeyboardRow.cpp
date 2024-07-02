#include "KeyboardRow.h"

#include <QDebug>

KeyboardRow::KeyboardRow(QObject *parent)
    : QObject{parent}
{
    m_key["Q"] = new KeyboardKey(this);
    m_key["W"] = new KeyboardKey(this);
    m_key["E"] = new KeyboardKey(this);
    m_key["R"] = new KeyboardKey(this);
    m_key["T"] = new KeyboardKey(this);
    m_key["Y"] = new KeyboardKey(this);
    m_key["U"] = new KeyboardKey(this);
}

void KeyboardRow::printKeyboardKeys() const
{
    qDebug() << "Printing all keys :";
    for (auto it = m_key.constBegin(); it != m_key.constEnd(); ++it) {
        qDebug() << it.key();
    }
    qDebug() << Qt::endl;
}
