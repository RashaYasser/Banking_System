#ifndef GETACCOUNTNUMBERADMINREQUEST_H
#define GETACCOUNTNUMBERADMINREQUEST_H

#include "Request.h"
#include <QJsonObject>

class GetAccountNumberAdminRequest : public Request
{
public:
    // Constructor with parameters
    GetAccountNumberAdminRequest(const QString& username);

    // Convert the request to a JSON object
    QJsonObject toJson() const override;

private:
    QString m_authentication;
    QString m_username;
};

#endif // GETACCOUNTNUMBERADMINREQUEST_H
