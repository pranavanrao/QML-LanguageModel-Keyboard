#ifndef KEYBOARDKEY_H
#define KEYBOARDKEY_H

#include <QObject>

class KeyboardKey : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardKey(const QString &text, const QString &image, const QString &key, const QString &altUpperKey, const QString &altLowerKey, const QString &color, const QString width, const QString height, const QString pressedColor, const QList<QString> &altKey, QObject *parent = nullptr);

    QString text() const;
    QString image() const;
    QString key() const;
    QString alternativeUpperCaseKey() const;
    QString alternativeLowerCaseKey() const;
    QString color() const;
    QString width() const;
    QString height() const;
    QString pressedColor() const;
    QList<QString> altKey() const;

private:
    QString m_text;
    QString m_image;
    QString m_key;
    QString m_altUpperKey;
    QString m_altLowerKey;
    QString m_color;
    QString m_width;
    QString m_height;
    QString m_pressedColor;
    QList<QString> m_altKey;
};

#endif // KEYBOARDKEY_H
