#include "RequestValidator.h"

// LoginRequestValidate
LoginRequestValidate::LoginRequestValidate(const QString& username, const QString& password)
    : m_username(username), m_password(password) {}

bool LoginRequestValidate::validate() const
{
    return !m_username.isEmpty() && !m_password.isEmpty();
}

// CreateUserRequestValidate
CreateUserRequestValidate::CreateUserRequestValidate(const QJsonObject& request)
    : m_request(request) {}

bool CreateUserRequestValidate::validate() const
{
    return m_request.contains("FullName") && m_request.contains("Age") && m_request.contains("UserName") &&
           m_request.contains("Password") && m_request.contains("Balance") && m_request.contains("Email") &&
           m_request.contains("PhoneNumber") && m_request.contains("Authentication") &&
           !m_request["FullName"].toString().isEmpty() && !m_request["Age"].toString().isEmpty() &&
           !m_request["UserName"].toString().isEmpty() && !m_request["Password"].toString().isEmpty() &&
           !m_request["Balance"].toString().isEmpty() && !m_request["Email"].toString().isEmpty() &&
           !m_request["PhoneNumber"].toString().isEmpty() && !m_request["Authentication"].toString().isEmpty();
}


// UpdateUserRequestValidate
UpdateUserRequestValidate::UpdateUserRequestValidate(const QString accountNum)
    : m_accountNumber(accountNum) {}

bool UpdateUserRequestValidate::validate() const
{
    return m_accountNumber.isEmpty();
}


// DeleteUserRequestValidate
DeleteUserRequestValidate::DeleteUserRequestValidate(const QString& accountNumber)
    : m_accountNumber(accountNumber) {}

    bool DeleteUserRequestValidate::validate() const {
    return !m_accountNumber.isEmpty();
}


// ViewBalanceRequestValidate
ViewBalanceRequestValidate::ViewBalanceRequestValidate(const QString& accountNumber,const QString &currentAccnum)
    : m_accountNumber(accountNumber),m_currentNum(currentAccnum){}

        bool ViewBalanceRequestValidate::validate() const {
         return (!m_accountNumber.isEmpty()&&(m_currentNum == m_accountNumber));
}



// ViewTransactionHistoryRequestValidate
ViewTransactionHistoryRequestValidate::ViewTransactionHistoryRequestValidate(const QString& accountNumber)
    : m_accountNumber(accountNumber) {}

bool ViewTransactionHistoryRequestValidate::validate() const
{
    return !m_accountNumber.isEmpty();
}


// ViewAccountDetailsRequestValidate
ViewAccountDetailsRequestValidate::ViewAccountDetailsRequestValidate(const QString& accountNumber)
    : m_accountNumber(accountNumber){}

bool ViewAccountDetailsRequestValidate::validate() const {
    return !m_accountNumber.isEmpty();
}

// MakeTransactionRequestValidate
MakeTransactionRequestValidate::MakeTransactionRequestValidate(const QString& accountNumber, const QString& amount, const QString& action,const QString& currentAcc)
    : m_accountNumber(accountNumber), m_amount(amount), m_action(action),m_currentAccountNumber(currentAcc) {}

bool MakeTransactionRequestValidate::validate() const
{
    bool ok;
    double amt = m_amount.toDouble(&ok);
    return !m_accountNumber.isEmpty() && m_accountNumber == m_currentAccountNumber && ok && amt > 0 && (m_action == "Deposit" || m_action == "Withdrawal");
}

// TransferAmountRequestValidate
TransferAmountRequestValidate::TransferAmountRequestValidate(const QString& fromAccountNumber, const QString& toAccountNumber, const QString& amount)
    : m_fromAccountNumber(fromAccountNumber), m_toAccountNumber(toAccountNumber), m_amount(amount) {}

bool TransferAmountRequestValidate::validate() const {
    bool ok;
    double amt = m_amount.toDouble(&ok);
    return !m_fromAccountNumber.isEmpty() && !m_toAccountNumber.isEmpty() &&
           m_fromAccountNumber != m_toAccountNumber && ok && amt > 0;
}

// GetAccountNumberRequestValidate
GetAccountNumberRequestValidate::GetAccountNumberRequestValidate(const QString& username,const QString& current_username)
    : m_username(username),m_currentUserName(current_username) {}
bool GetAccountNumberRequestValidate::validate() const
{
    if (m_username.isEmpty()) {
        return false; // Validation fails if username is empty
    }
    if (m_currentUserName != m_username)
    {
        return false; // Validation fails if current username doesn't match
    }
    return true; // Validation succeeds
}


