#ifndef KEYBOARDKEY_H
#define KEYBOARDKEY_H

#include <QObject>

class KeyboardKey : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardKey(const QString &text, const QString &key, const QString &altUpperKey = "", const QString &altLowerKey = "", QObject *parent = nullptr);

    QString text() const;
    QString key() const;
    QString alternativeUpperCaseKey() const;
    QString alternativeLowerCaseKey() const;

signals:

private:
    QString m_text;
    QString m_key;
    QString m_altUpperKey;
    QString m_altLowerKey;
};

#endif // KEYBOARDKEY_H
