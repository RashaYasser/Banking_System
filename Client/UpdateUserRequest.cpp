#include "UpdateUserRequest.h"

UpdateUserRequest::UpdateUserRequest(const QString& accountNumber, const QString& newPassword, const QString& username, const QString& newEmail, const QString& newPhoneNumber)
    : m_accountNumber(accountNumber), m_newPassword(newPassword),
    m_username(username), m_newEmail(newEmail), m_newPhoneNumber(newPhoneNumber)
{
}

QJsonObject UpdateUserRequest::toJson() const
{
    QJsonObject request;
    request["Action"] = "updateUser";
    request["AccountNumber"] = m_accountNumber;

    // Update the fields with new data from the request if present
    if (!m_username.isEmpty())
    {
        request["UserName"] = m_username;
    }
    if (!m_newPassword.isEmpty())
    {
        request["Password"] = m_newPassword;
    }
    if (!m_newEmail.isEmpty())
    {
        request["Email"] = m_newEmail;
    }
    if (!m_newPhoneNumber.isEmpty())
    {
        request["PhoneNumber"] = m_newPhoneNumber;
    }

    return request;
}
