#include "Encryption.h"
#include <QCryptographicHash>
#include <QJsonDocument>

// Encrypts a JSON object using XOR encryption with a key
QByteArray Encryption::encrypt(const QJsonObject& json, const QString& key)
{
    // Convert JSON object to byte array
    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    // Generate a hash of the key for encryption
    QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);

    // XOR each byte of data with the key's hash
    for (int i = 0; i < data.size(); ++i)
    {
        data[i] = data[i] ^ hashKey[i % hashKey.size()];
    }

    // Return the encrypted data encoded in Base64
    return data.toBase64();
}

// Decrypts a byte array using XOR encryption with a key and converts it back to JSON
QJsonObject Encryption::decrypt(const QByteArray& data, const QString& key)
{
    QByteArray decodedData = QByteArray::fromBase64(data);

    // Generate a hash of the key for decryption
    QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);
    QByteArray decryptedData = decodedData;

    // XOR each byte of encrypted data with the key's hash to decrypt it
    for (int i = 0; i < decryptedData.size(); ++i)
    {
        decryptedData[i] = decryptedData[i] ^ hashKey[i % hashKey.size()];
    }

    // Convert decrypted data back to JSON object
    QJsonDocument doc = QJsonDocument::fromJson(decryptedData);
    return doc.object();
}
