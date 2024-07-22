#ifndef VIEWACCOUNTDETAILSREQUEST_H
#define VIEWACCOUNTDETAILSREQUEST_H

#include "Request.h"
#include <QJsonObject>

class ViewAccountDetailsRequest : public Request
{
public:
    // Constructor with parameters
    ViewAccountDetailsRequest(const QString& accountNumber);

    // Convert the request to a JSON object
    QJsonObject toJson() const override;

private:
    QString m_accountNumber;
};

#endif // VIEWACCOUNTDETAILSREQUEST_H
