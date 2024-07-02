#include "KeyboardLayer.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

KeyboardLayer::KeyboardLayer(QObject *parent)
    : QObject{parent}
{
    m_rows["row1"] = new KeyboardRow(this);
    m_rows["row2"] = new KeyboardRow(this);
    m_rows["row3"] = new KeyboardRow(this);
    m_rows["row4"] = new KeyboardRow(this);
    m_rows["row5"] = new KeyboardRow(this);
    m_rows["row6"] = new KeyboardRow(this);
}

void KeyboardLayer::initializeFromJson(const QJsonObject &json)
{
    // QStringList rows = json.keys();
    // for (const QString& rowName : rows) {
    //     KeyboardRow* row = new KeyboardRow(this);
    //     QJsonArray keysArray = json[rowName].toArray();
    //     for (const QJsonValue& value : keysArray) {
    //         QJsonObject keyObject = value.toObject();
    //         Keys key;
    //         key.text = keyObject["text"].toString();
    //         key.key = keyObject["key"].toString();
    //         key.alternativeUpperCaseKey = keyObject.value("alternativeUpperCaseKey").toString();
    //         key.alternativeLowerCaseKey = keyObject.value("alternativeLowerCaseKey").toString();
    //         row->addKey(key);
    //     }
    //     m_rows[rowName] = row;
    // }
}

void KeyboardLayer::printKeyboardRows() const
{
    qDebug() << "Printing all rows : ";
    for (auto it = m_rows.constBegin(); it != m_rows.constEnd(); ++it) {
        qDebug() << it.key();
    }
    qDebug() << Qt::endl;
}
