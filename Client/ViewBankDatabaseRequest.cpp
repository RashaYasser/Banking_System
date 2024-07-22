#include "ViewBankDatabaseRequest.h"

ViewBankDatabaseRequest::ViewBankDatabaseRequest(const QString& authentication)
    : m_authentication(authentication)
{
}

QJsonObject ViewBankDatabaseRequest::toJson() const
{

    QJsonObject request;
    request["Action"] = "viewBankDatabase";
    request["Authentication"] = m_authentication;

    return request;
}
