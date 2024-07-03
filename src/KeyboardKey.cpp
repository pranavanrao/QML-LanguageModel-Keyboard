#include "KeyboardKey.h"

KeyboardKey::KeyboardKey(const QString &text, const QString &key, const QString &altUpperKey, const QString &altLowerKey, QObject *parent)
    : QObject(parent),
    m_text(text),
    m_key(key),
    m_altUpperKey(altUpperKey),
    m_altLowerKey(altLowerKey)
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
