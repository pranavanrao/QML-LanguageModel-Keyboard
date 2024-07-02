#ifndef KEYBOARDKEY_H
#define KEYBOARDKEY_H

#include <QObject>

class KeyboardKey : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardKey(QObject *parent = nullptr);

signals:
};

#endif // KEYBOARDKEY_H
