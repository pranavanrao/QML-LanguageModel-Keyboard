#include "LanguageModel.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

LanguageModel::LanguageModel(QObject *parent)
    : QObject{parent}
{
    QString filename = ":/data/languages_data.json";
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open" << filename;
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(jsonData));
    QJsonObject jsonObject = doc.object();

    initializeFromJson(jsonObject);
}

void LanguageModel::initializeFromJson(const QJsonObject& json)
{
    QJsonArray languagesArray = json["languages"].toArray();
    for (const QJsonValue& value : languagesArray) {
        QString language = value.toString();
        m_keyboards[language] = new Keyboard(this);
    }
}

Keyboard *LanguageModel::getKeyboard(const QString &language) const
{
    if (m_keyboards.contains(language)) {
        return m_keyboards[language];
    } else {
        qDebug() << "Keyboard for" << language << "not found";
        return nullptr;
    }
}

void LanguageModel::printKeyboards() const
{
    qDebug() << "All Language Keyboards available :";
    for (auto it = m_keyboards.constBegin(); it != m_keyboards.constEnd(); ++it) {
        qDebug() << it.key();
        // it.value()->printKeyBoardLayers();
    }
    qDebug() << Qt::endl;
}
