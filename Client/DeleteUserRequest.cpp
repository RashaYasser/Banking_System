#include "DeleteUserRequest.h"

DeleteUserRequest::DeleteUserRequest(const QString& accountNumber)
    : m_accountNumber(accountNumber)
{
}

QJsonObject DeleteUserRequest::toJson() const
{
    QJsonObject request;
    request["Action"] = "deleteUser";
    request["AccountNumber"] = m_accountNumber;
    return request;

}
