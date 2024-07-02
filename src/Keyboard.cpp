#include "Keyboard.h"

#include <QDebug>

Keyboard::Keyboard(QObject *parent)
    : QObject{parent}
{
    m_layers["layer1"] = new KeyboardLayer(this);
}

void Keyboard::printKeyBoardLayers() const
{
    qDebug() << "Printing all the layers :";
    for (auto it = m_layers.constBegin(); it != m_layers.constEnd(); ++it) {
        qDebug() << it.key();
    }
    qDebug() << Qt::endl;
}
