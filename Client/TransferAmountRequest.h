#ifndef TRANSFERAMOUNTREQUEST_H
#define TRANSFERAMOUNTREQUEST_H

#include "Request.h"
#include <QJsonObject>
#include <QDateTime>

class TransferAmountRequest : public Request
{
public:
    // Constructor with parameters
    TransferAmountRequest(const QString& sender,
                          const QString& recipient,
                          QString amount);

    // Convert the request to a JSON object
    QJsonObject toJson() const override;

private:
    QString m_sender;
    QString m_recipient;
    QString m_amount;
    QString m_timestamp;
};

#endif // TRANSFERAMOUNTREQUEST_H
