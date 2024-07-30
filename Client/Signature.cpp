#include "Signature.h"
#include <QCryptographicHash>

// Signs data by creating a SHA-256 hash of the data combined with a key
QByteArray Signature::sign(const QByteArray& data, const QString& key)
{
    // Generate a hash of the key
    QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);

    // Combine data with the hashKey
    QByteArray combined = data + hashKey;

    // Generate the signature by hashing the combined data
    QByteArray signature = QCryptographicHash::hash(combined, QCryptographicHash::Sha256);
    return signature;
}

// Verifies the signature by comparing it to a hash of the data combined with the key
bool Signature::verify(const QByteArray& data, const QByteArray& signature, const QString& key)
{
    // Generate a hash of the key
    QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);

    // Combine data with the hashKey
    QByteArray combined = data + hashKey;

    // Generate the expected signature by hashing the combined data
    QByteArray expectedSignature = QCryptographicHash::hash(combined, QCryptographicHash::Sha256);

    // Check if the provided signature matches the expected signature
    return (signature == expectedSignature);
}
