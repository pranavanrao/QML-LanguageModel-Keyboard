#ifndef KEYBOARDLAYER_H
#define KEYBOARDLAYER_H

#include "KeyboardRow.h"

#include <QObject>
#include <QMap>

class KeyboardLayer : public QObject
{
    Q_OBJECT
    using ROWS = QString;

public:
    explicit KeyboardLayer(QObject *parent = nullptr);
    void initializeFromJson(const QJsonObject &json);
    void printKeyboardRows() const;

    QMap<QString, KeyboardRow*> rows() const;
    KeyboardRow *getRow(const QString &rowName) const;

    QVariantList getRowKeys() const;

signals:

private:
    QMap<ROWS, KeyboardRow*> m_rows;
};

#endif // KEYBOARDLAYER_H
