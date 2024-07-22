#include "ViewBalanceRequest.h"

ViewBalanceRequest::ViewBalanceRequest(const QString& accountNumber, const QString& username)
    : m_accountNumber(accountNumber),
    m_username(username)
{
}

QJsonObject ViewBalanceRequest::toJson() const
{
    QJsonObject request;
    request["Action"] = "viewBalance";
    request["AccountNumber"] = m_accountNumber;
    request["UserName"] = m_username;
    return request;
}
