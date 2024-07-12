#include "KeyboardLayer.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

KeyboardLayer::KeyboardLayer(QObject *parent)
    : QObject{parent}
{}

void KeyboardLayer::initializeFromJson(const QJsonObject &json)
{
    for (const QString &rowName : json.keys()) {
        QJsonArray rowArray = json[rowName].toArray();
        m_rows[rowName] = new KeyboardRow(this);
        m_rows[rowName]->initializeFromJson(rowArray);
    }
}

void KeyboardLayer::printKeyboardRows() const
{
    qDebug() << "Printing all rows : ";
    for (auto it = m_rows.constBegin(); it != m_rows.constEnd(); ++it) {
        qDebug() << it.key();
        it.value()->printKeyboardKeys();
    }
    qDebug() << Qt::endl;
}
