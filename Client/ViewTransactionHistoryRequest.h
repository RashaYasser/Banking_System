#ifndef VIEWTRANSACTIONHISTORYREQUEST_H
#define VIEWTRANSACTIONHISTORYREQUEST_H

#include "Request.h"
#include <QJsonObject>

class ViewTransactionHistoryRequest : public Request
{
public:
    // Constructor with parameters
    ViewTransactionHistoryRequest(const QString& accountNumber, const QString& adminUsername);

    // Convert the request to a JSON object
    QJsonObject toJson() const override;

private:
    QString m_accountNumber;
    QString m_adminUsername;
};

#endif // VIEWTRANSACTIONHISTORYREQUEST_H
