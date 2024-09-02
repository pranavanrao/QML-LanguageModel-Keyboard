#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "KeyboardLayer.h"

#include <QObject>
#include <QVariantList>
#include <QMap>

class Keyboard : public QObject
{
    Q_OBJECT
    using LAYERS = QString;

public:
    explicit Keyboard(QObject *parent = nullptr);

    void initializeFromJson(const QJsonObject &json);
    void printKeyBoardLayers() const;

    Q_INVOKABLE QVariantList parseKeyboardLayers() const;
    Q_INVOKABLE QVariantList parseKeyboardRows() const;

    Q_INVOKABLE QVariantList parseKeyboardKeysRow1();
    Q_INVOKABLE QVariantList parseKeyboardKeysRow2();
    Q_INVOKABLE QVariantList parseKeyboardKeysRow3();
    Q_INVOKABLE QVariantList parseKeyboardKeysRow4();

    Q_INVOKABLE QVariantList parseAltKeyForKey(const QString &keyText) const;

    Q_INVOKABLE void setLanguage(const QString &language);
    Q_INVOKABLE void setLayer(const QString &layer);

signals:

private:
    QMap<LAYERS, KeyboardLayer*> m_layers;
    QString m_currentLayer;

    QVariantList parseKeyboardKeys(int rows) const;
};

#endif // KEYBOARD_H
