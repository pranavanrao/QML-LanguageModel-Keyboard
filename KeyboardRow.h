#ifndef KEYBOARDROW_H
#define KEYBOARDROW_H

#include "KeyboardKey.h"

#include <QObject>
#include <QMap>

class KeyboardRow : public QObject
{
    Q_OBJECT
    using KEYS = QString;

public:
    explicit KeyboardRow(QObject *parent = nullptr);

    void printKeyboardKeys() const;

signals:

private:
    QMap<KEYS, KeyboardKey*> m_key;
};

#endif // KEYBOARDROW_H
