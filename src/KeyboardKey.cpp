#include "KeyboardKey.h"

KeyboardKey::KeyboardKey(const QString &text, const QString &image, const QString &key, const QString &altUpperKey, const QString &altLowerKey, const QString &color, const QString width, const QString height, const QString pressedColor, const QList<QString> &altKey, QObject *parent)
    : QObject(parent),
    m_text(text),
    m_image(image),
    m_key(key),
    m_altUpperKey(altUpperKey),
    m_altLowerKey(altLowerKey),
    m_color(color),
    m_width(width),
    m_height(height),
    m_pressedColor(pressedColor),
    m_altKey(altKey)
{}

QString KeyboardKey::text() const
{
    return m_text;
}

QString KeyboardKey::image() const
{
    return m_image;
}

QString KeyboardKey::key() const
{
    return m_key;
}

QString KeyboardKey::alternativeUpperCaseKey() const
{
    return m_altUpperKey;
}

QString KeyboardKey::alternativeLowerCaseKey() const
{
    return m_altLowerKey;
}

QString KeyboardKey::color() const
{
    return m_color;
}

QString KeyboardKey::width() const
{
    return m_width;
}

QString KeyboardKey::height() const
{
    return m_height;
}

QString KeyboardKey::pressedColor() const
{
    return m_pressedColor;
}

QList<QString> KeyboardKey::altKey() const
{
    return m_altKey;
}
