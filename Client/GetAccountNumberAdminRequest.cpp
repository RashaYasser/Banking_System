#include "GetAccountNumberAdminRequest.h"

GetAccountNumberAdminRequest::GetAccountNumberAdminRequest(const QString& username)
    : m_authentication("Admin"),
    m_username(username)
{
}

QJsonObject GetAccountNumberAdminRequest::toJson() const
{
    QJsonObject json;
    json["Action"] = "getAccountNumberAdmin";
    json["Authentication"] = m_authentication;
    json["UserName"] = m_username;
    return json;
}
