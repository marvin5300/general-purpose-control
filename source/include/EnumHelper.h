#ifndef UTILITIES_H
#define UTILITIES_H
#pragma once

#include <QDebug>
#include <QMetaEnum>
#include <QString>
#include <QSerialPort>

namespace EnumHelper{
/* function to convert string to enum
 */
template <typename E>
E fromString(const QString &text)
{
    bool ok;
    auto result = static_cast<E>(QMetaEnum::fromType<E>().keyToValue(text.toUtf8(), &ok));
    if(!ok) {
        qDebug() << "Failed to convert enum" << text;
        return {};
    }
    return result;
}


/* Function to convert enum to string
 */
template <typename E>
QString toString(E value)
{
    const int intValue = static_cast<int>(value);
    return QString::fromUtf8(QMetaEnum::fromType<E>().valueToKey(intValue));
}
}
#endif // UTILITIES_H
