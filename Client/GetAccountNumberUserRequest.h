#ifndef GETACCOUNTNUMBERUSERREQUEST_H
#define GETACCOUNTNUMBERUSERREQUEST_H

#include "Request.h"
#include <QJsonObject>

class GetAccountNumberUserRequest : public Request
{
public:
    // Constructor with parameters
    GetAccountNumberUserRequest(const QString& username);

    // Convert the request to a JSON object
    QJsonObject toJson() const override;

private:
    QString m_username;
};

#endif // GETACCOUNTNUMBERUSERREQUEST_H
