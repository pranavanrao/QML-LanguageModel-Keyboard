#ifndef KEYBOARDROW_H
#define KEYBOARDROW_H

#include "KeyboardKey.h"

#include <QObject>
#include <QList>

class KeyboardRow : public QObject
{
    Q_OBJECT
    using KEYS = QString;

public:
    explicit KeyboardRow(QObject *parent = nullptr);
    void addKey(const QString &text, const QString &key, const QString &altUpperKey = "", const QString &altLowerKey = "");
    void initializeFromJson(const QJsonArray &json);
    void printKeyboardKeys() const;

    QList<KeyboardKey*> keys() const;
    QVariantList getKeys() const;

signals:

private:
    QList<KeyboardKey*> m_keys;
};

#endif // KEYBOARDROW_H
