#ifndef UPDATEUSERREQUEST_H
#define UPDATEUSERREQUEST_H

#include "Request.h"
#include <QJsonObject>

class UpdateUserRequest : public Request
{
public:
    // Constructor with parameters
    UpdateUserRequest(const QString& accountNumber,
                      const QString& newPassword,
                      const QString& username,
                      const QString& newEmail,
                      const QString& newPhoneNumber);

    // Convert the request to a JSON object
    QJsonObject toJson() const override;

private:
    QString m_accountNumber;
    QString m_newPassword;
    QString m_username;
    QString m_newEmail;
    QString m_newPhoneNumber;
};

#endif // UPDATEUSERREQUEST_H
