#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <QByteArray>
#include <QString>
#include <QJsonObject>
class Encryption
{
public:
    // Encrypts a JSON object using XOR encryption with a key
    static QByteArray encrypt(const QJsonObject& json, const QString& key);

    // Decrypts a byte array using XOR encryption with a key and converts it back to JSON
    static QJsonObject decrypt(const QByteArray& data, const QString& key);
};


#endif // ENCRYPTION_H
