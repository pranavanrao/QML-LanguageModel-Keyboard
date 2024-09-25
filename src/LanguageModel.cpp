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
        qWarning() << Q_FUNC_INFO << "Failed to open" << filename;
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(jsonData));
    QJsonObject jsonObject = doc.object();

    initializeFromJson(jsonObject);

    // Set the default language to English
    if (m_keyboards.contains("english")) {
        m_keyboards["english"]->setLanguage("english");
    }
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
        qWarning() << Q_FUNC_INFO << "Keyboard for" << language << "not found";
        return nullptr;
    }
}

void LanguageModel::printKeyboards() const
{
    qDebug() << Q_FUNC_INFO << "All Language Keyboards available :";
    for (auto it = m_keyboards.constBegin(); it != m_keyboards.constEnd(); ++it) {
        qDebug() << Q_FUNC_INFO << it.key();
    }
}

QVariantList LanguageModel::parseKeyboards() const {
    QVariantList list;
    for (auto it = m_keyboards.constBegin(); it != m_keyboards.constEnd(); ++it) {
        list.append(it.key());
    }
    return list;
}
