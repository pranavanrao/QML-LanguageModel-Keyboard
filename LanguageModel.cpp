#include "LanguageModel.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

LanguageModel::LanguageModel(QObject *parent)
    : QObject{parent}
{
    loadFromJson(":/data/languages_data.json");
}

void LanguageModel::loadFromJson(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file" << fileName;
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(jsonData));
    QJsonObject jsonObject = doc.object();

    QJsonArray languagesArray = jsonObject["languages"].toArray();
    for (const QJsonValue& value : languagesArray) {
        QString language = value.toString();
        m_keyboards[language] = new Keyboard(this);
    }
}

void LanguageModel::printKeyboards() const
{
    qDebug() << "All Language Keyboards available :";
    for (auto it = m_keyboards.constBegin(); it != m_keyboards.constEnd(); ++it) {
        qDebug() << it.key();
    }
    qDebug() << Qt::endl;
}
