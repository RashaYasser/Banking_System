#ifndef SIGNATURE_H
#define SIGNATURE_H

#include <QString>
#include <QByteArray>

// The Signature class provides static methods to sign data and verify signatures
class Signature
{
public:
    // Signs a byte array using the provided key
    static QByteArray sign(const QByteArray& data, const QString& key);

    // Verifies if the signature matches the data and key
    static bool verify(const QByteArray& data, const QByteArray& signature, const QString& key);
};

#endif
