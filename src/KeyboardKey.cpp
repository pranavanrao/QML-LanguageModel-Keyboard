#include "KeyboardKey.h"

KeyboardKey::KeyboardKey(const QString &text, const QString &key, const QString &altUpperKey, const QString &altLowerKey, const QString &color, int width, int height, QObject *parent)
    : QObject(parent),
    m_text(text),
    m_key(key),
    m_altUpperKey(altUpperKey),
    m_altLowerKey(altLowerKey),
    m_color(color),
    m_width(width),
    m_height(height)
{}

QString KeyboardKey::text() const
{
    return m_text;
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

int KeyboardKey::width() const
{
    return m_width;
}

int KeyboardKey::height() const
{
    return m_height;
}
