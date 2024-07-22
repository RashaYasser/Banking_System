#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include "Request.h"

// Class for handling login requests
class LoginRequest : public Request
{
public:
    LoginRequest(const QString& username, const QString& password);
    QJsonObject toJson() const override;

private:
    QString m_username;
    QString m_password;
};

#endif // LOGINREQUEST_H
