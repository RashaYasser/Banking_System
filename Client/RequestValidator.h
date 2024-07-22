#ifndef REQUESTVALIDATOR_H
#define REQUESTVALIDATOR_H

#include <QString>
#include <QJsonObject>

// Abstract base class
class RequestValidate
{
public:
    virtual ~RequestValidate() = default;
    virtual bool validate() const = 0;
};

// Concrete request validator classes

class LoginRequestValidate : public RequestValidate
{
public:
    LoginRequestValidate(const QString& username, const QString& password);

    bool validate() const override;

private:
    QString m_username;
    QString m_password;
};

class CreateUserRequestValidate : public RequestValidate
{
public:
    CreateUserRequestValidate(const QJsonObject& request);

    bool validate() const override;

private:
    QJsonObject m_request;
};

class UpdateUserRequestValidate : public RequestValidate
{
public:
    UpdateUserRequestValidate(const QString accountNum);

    bool validate() const override;

private:
    QString m_accountNumber;
};

class DeleteUserRequestValidate : public RequestValidate
{
public:
    DeleteUserRequestValidate(const QString& accountNumber);

    bool validate() const override;

private:
    QString m_accountNumber;
};

class ViewBalanceRequestValidate : public RequestValidate
{
public:
    ViewBalanceRequestValidate(const QString& accountNumber,const QString &currentAccnum);
    bool validate() const override;

private:
    QString m_accountNumber;
    QString m_currentNum;
};

class ViewTransactionHistoryRequestValidate : public RequestValidate
{
public:
    ViewTransactionHistoryRequestValidate(const QString& accountNumber);

    bool validate() const override;

private:
    QString m_accountNumber;
};

class ViewAccountDetailsRequestValidate : public RequestValidate
{
public:
    ViewAccountDetailsRequestValidate(const QString& accountNumber);

    bool validate() const override;

private:
    QString m_accountNumber;
};

class MakeTransactionRequestValidate : public RequestValidate
{
public:
    MakeTransactionRequestValidate(const QString& accountNumber, const QString& amount, const QString& action,const QString& currentAcc);

    bool validate() const override;

private:
    QString m_accountNumber;
    QString m_amount;
    QString m_action;
    QString m_currentAccountNumber;
};

class TransferAmountRequestValidate : public RequestValidate
{
public:
    TransferAmountRequestValidate(const QString& fromAccountNumber, const QString& toAccountNumber, const QString& amount);

    bool validate() const override;

private:
    QString m_fromAccountNumber;
    QString m_toAccountNumber;
    QString m_amount;
};

class GetAccountNumberRequestValidate : public RequestValidate
{
public:
    GetAccountNumberRequestValidate(const QString& username,const QString& current_username);

    bool validate() const override;

private:
    QString m_username;
    QString m_currentUserName;
};

#endif // REQUESTVALIDATOR_H
