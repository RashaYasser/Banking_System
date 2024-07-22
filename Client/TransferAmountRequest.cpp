#include "TransferAmountRequest.h"

TransferAmountRequest::TransferAmountRequest(const QString& sender,
                                             const QString& recipient,
                                             double amount)
    : m_sender(sender),
    m_recipient(recipient),
    m_amount(amount),
    m_timestamp(QDateTime::currentDateTime().toString("ddd MMM dd HH:mm:ss yyyy"))
{
}

QJsonObject TransferAmountRequest::toJson() const
{
    // Create a JSON request for a transfer
    QJsonObject request;
    request["Action"] = "transferAmount";
    request["Sender"] = m_sender; // Use currentUser as the sender
    request["Recipient"] = m_recipient; // Recipient is provided as a parameter
    request["Amount"] = m_amount; // Ensure amount is correctly formatted as a string
    request["Timestamp"] = m_timestamp;
    return request;

}
