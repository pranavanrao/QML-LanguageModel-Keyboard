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
    qDebug() << Q_FUNC_INFO << "Printing all rows : ";
    for (auto it = m_rows.constBegin(); it != m_rows.constEnd(); ++it) {
        qDebug() << Q_FUNC_INFO << it.key();
        it.value()->printKeyboardKeys();
    }
}

QMap<QString, KeyboardRow *> KeyboardLayer::rows() const
{
    return m_rows;
}

KeyboardRow *KeyboardLayer::getRow(const QString &rowName) const
{
    if (m_rows.contains(rowName)) {
        return m_rows[rowName];
    } else {
        qWarning() << Q_FUNC_INFO << "Row" << rowName << "not found";
        return nullptr;
    }
}

QVariantList KeyboardLayer::getRowKeys() const
{
    QVariantList rowKeysList;
    for (const auto& row : m_rows.keys()) {
        rowKeysList.append(row);
    }
    return rowKeysList;
}
