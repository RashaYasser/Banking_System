#ifndef VIEWBANKDATABASEREQUEST_H
#define VIEWBANKDATABASEREQUEST_H

#include "Request.h"
#include <QJsonObject>

class ViewBankDatabaseRequest : public Request
{
public:
    // Constructor with parameters
    ViewBankDatabaseRequest(const QString& authentication);

    // Convert the request to a JSON object
    QJsonObject toJson() const override;

private:
    QString m_authentication;
};

#endif // VIEWBANKDATABASEREQUEST_H
