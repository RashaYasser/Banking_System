#include "GetAccountNumberUserRequest.h"

GetAccountNumberUserRequest::GetAccountNumberUserRequest(const QString& username)
    : m_username(username)
{
}

QJsonObject GetAccountNumberUserRequest::toJson() const
{
    QJsonObject request; // Create a JSON object to hold the request
    request["Action"] = "getAccountNumberUser";
    request["UserName"] = m_username; // User can only fetch their own account number
    return request;

}
