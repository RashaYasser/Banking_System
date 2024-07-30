#ifndef SIGNATURE_H
#define SIGNATURE_H

#include <QByteArray>
#include <QString>

class Signature
{
public:
    QByteArray sign(const QByteArray& data, const QString& key);
    static bool verify(const QByteArray &data, const QByteArray &signature, const QString &key);
};

#endif // SIGNATURE_H

