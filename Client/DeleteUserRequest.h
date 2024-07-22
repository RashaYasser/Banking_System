#ifndef DELETEUSERREQUEST_H
#define DELETEUSERREQUEST_H

#include "Request.h"
#include <QJsonObject>

class DeleteUserRequest : public Request
{
public:
    // Constructor with parameters
    DeleteUserRequest(const QString& accountNumber);

    // Convert the request to a JSON object
    QJsonObject toJson() const override;

private:
    QString m_accountNumber;
};

#endif // DELETEUSERREQUEST_H
