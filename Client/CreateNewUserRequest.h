#ifndef CREATENEWUSERREQUEST_H
#define CREATENEWUSERREQUEST_H

#include "Request.h"
#include <QJsonObject>

class CreateNewUserRequest : public Request
{
public:
    // Constructor with parameters
    CreateNewUserRequest(const QString& fullName,const QString& age,const QString& username,
                         const QString& password,const QString& balance, const QString& phoneNumber,
                         const QString& email, const QString& userType);

    // Convert the request to a JSON object
    QJsonObject toJson() const override;

private:
    QString m_fullName;
    QString m_age;
    QString m_username;
    QString m_password;
    QString m_balance;
    QString m_phoneNumber;
    QString m_email;
    QString m_userType;
};

#endif // CREATENEWUSERREQUEST_H
