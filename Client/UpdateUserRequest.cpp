#include "UpdateUserRequest.h"

UpdateUserRequest::UpdateUserRequest(const QString& accountNumber,const QString& newPassword,const QString& username,const QString& newEmail,const QString& newPhoneNumber)
    : m_accountNumber(accountNumber),m_newPassword(newPassword),
    m_username(username), m_newEmail(newEmail),m_newPhoneNumber(newPhoneNumber)
{
}

QJsonObject UpdateUserRequest::toJson() const
{

    QJsonObject request;
    request["Action"] = "updateUser";
    request["AccountNumber"] = m_accountNumber;
    request["UserName"] = m_username;
    request["Password"] = m_newPassword;
    request["Email"] = m_newEmail;
    request["PhoneNumber"] = m_newPhoneNumber;
    return request;
}

