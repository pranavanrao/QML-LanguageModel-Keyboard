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

    void initializeFromJson(const QJsonObject& json);
    Keyboard *getKeyboard(const QString& language) const;
    void printKeyboards() const;

signals:
    void keyboardsChanged();

private:
    QMap<LANGUAGE, Keyboard*> m_keyboards;
};

#endif // LANGUAGEMODEL_H
