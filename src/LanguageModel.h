#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H

#include "Keyboard.h"

#include <QObject>
#include <QMap>
#include <QJsonObject>

class LanguageModel : public QObject
{
    Q_OBJECT
    using LANGUAGE = QString;

public:
    explicit LanguageModel(QObject *parent = nullptr);

    Keyboard *getKeyboard(const QString& language) const;

    void initializeFromJson(const QJsonObject& json);
    void printKeyboards() const;

    Q_INVOKABLE QVariantList parseKeyboards() const;

signals:
    void keyboardsChanged();

private:
    QMap<LANGUAGE, Keyboard*> m_keyboards;
};

#endif // LANGUAGEMODEL_H
