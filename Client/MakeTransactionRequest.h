#ifndef MAKETRANSACTIONREQUEST_H
#define MAKETRANSACTIONREQUEST_H

#include "Request.h"
#include <QJsonObject>
#include <QDateTime>

class MakeTransactionRequest : public Request
{
public:
    // Constructor with parameters
    MakeTransactionRequest(const QString& transactionType,
                           const QString& accountNumber,
                           const QString& username,
                           const QString&);

    // Convert the request to a JSON object
    QJsonObject toJson() const override;

private:
    QString m_transactionType;
    QString m_accountNumber;
    QString m_username;
    QString m_amount;
    QString m_timestamp;
};

#endif // MAKETRANSACTIONREQUEST_H
