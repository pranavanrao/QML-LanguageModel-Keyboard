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

    void printKeyboards() const;

signals:
    void keyboardsChanged();

private:
    QMap<LANGUAGE, Keyboard*> m_keyboards;

    void loadFromJson(const QString &fileName);
};

#endif // LANGUAGEMODEL_H
