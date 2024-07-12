#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "KeyboardLayer.h"

#include <QObject>
#include <QMap>

class Keyboard : public QObject
{
    Q_OBJECT
    using LAYERS = QString;

public:
    explicit Keyboard(QObject *parent = nullptr);
    void initializeFromJson(const QJsonObject &json);
    void printKeyBoardLayers() const;

signals:

private:
    QMap<LAYERS, KeyboardLayer*> m_layers;
};

#endif // KEYBOARD_H
