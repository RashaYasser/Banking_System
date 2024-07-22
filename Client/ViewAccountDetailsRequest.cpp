#include "ViewAccountDetailsRequest.h"

ViewAccountDetailsRequest::ViewAccountDetailsRequest(const QString& accountNumber)
    : m_accountNumber(accountNumber)
{
}

QJsonObject ViewAccountDetailsRequest::toJson() const
{
    QJsonObject request;
    request["Action"] = "viewAccountDetails";
    request["AccountNumber"] = m_accountNumber;
    return request;
}
