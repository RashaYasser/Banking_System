#include "ViewTransactionHistoryRequest.h"

ViewTransactionHistoryRequest::ViewTransactionHistoryRequest(const QString& accountNumber, const QString& adminUsername)
    : m_accountNumber(accountNumber),
    m_adminUsername(adminUsername)
{
}

QJsonObject ViewTransactionHistoryRequest::toJson() const
{
    QJsonObject request;
    request["Action"] = "viewTransactionHistory";
    request["AccountNumber"] = m_accountNumber;
    request["AdminUsername"] = m_adminUsername;
    return request;
}
