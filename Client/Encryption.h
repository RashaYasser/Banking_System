#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <QJsonObject>
#include <QByteArray>

class Encryption
{
public:
    static QByteArray encrypt(const QJsonObject& json, const QString& key);
    static QJsonObject decrypt(const QByteArray& data, const QString& key);
};

#endif // ENCRYPTION_H
