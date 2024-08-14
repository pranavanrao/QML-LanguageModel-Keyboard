#ifndef KEYBOARDKEY_H
#define KEYBOARDKEY_H

#include <QObject>

class KeyboardKey : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardKey(const QString &text, const QString &key, const QString &altUpperKey, const QString &altLowerKey, const QString &color, const QString width, const QString height, QObject *parent = nullptr);

    QString text() const;
    QString key() const;
    QString alternativeUpperCaseKey() const;
    QString alternativeLowerCaseKey() const;
    QString color() const;
    QString width() const;
    QString height() const;

signals:

private:
    QString m_text;
    QString m_key;
    QString m_altUpperKey;
    QString m_altLowerKey;
    QString m_color;
    QString m_width;
    QString m_height;
};

#endif // KEYBOARDKEY_H
