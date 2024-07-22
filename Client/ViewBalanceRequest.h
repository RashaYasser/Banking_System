#ifndef VIEWBALANCEREQUEST_H
#define VIEWBALANCEREQUEST_H

#include "Request.h"
#include <QJsonObject>

class ViewBalanceRequest : public Request
{
public:
    // Constructor with parameters
    ViewBalanceRequest(const QString& accountNumber, const QString& username);

    // Convert the request to a JSON object
    QJsonObject toJson() const override;

private:
    QString m_accountNumber;
    QString m_username;
};

#endif // VIEWBALANCEREQUEST_H
