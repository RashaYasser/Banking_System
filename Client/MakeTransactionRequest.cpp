#include "MakeTransactionRequest.h"

MakeTransactionRequest::MakeTransactionRequest(const QString& transactionType,
                                               const QString& accountNumber,
                                               const QString& username,
                                                const QString& amount)
    : m_transactionType(transactionType),
    m_accountNumber(accountNumber),
    m_username(username),
    m_amount(amount),
    m_timestamp(QDateTime::currentDateTime().toString())
{
}

QJsonObject MakeTransactionRequest::toJson() const
{
    // Create a JSON request for a transaction
    QJsonObject request;
    request["Action"] = "makeTransaction";
    request["TransactionType"] = m_transactionType;
    request["AccountNumber"] = m_accountNumber;
    request["UserName"] = m_username;
    request["Amount"] = m_amount;
    request["Timestamp"] =m_timestamp;
    return request;
}
