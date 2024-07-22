#include "CreateNewUserRequest.h"

CreateNewUserRequest::CreateNewUserRequest(const QString& fullName,const QString& age,const QString& username,
                                           const QString& password,const QString& balance,const QString& phoneNumber,
                                           const QString& email, const QString& userType)
    : m_fullName(fullName),m_age(age),m_username(username),m_password(password),m_balance(balance),m_phoneNumber(phoneNumber)
    ,m_email(email),m_userType(userType)
{
}

QJsonObject CreateNewUserRequest::toJson() const
{
    // Validate input fields (account number, new password, etc.) here if needed
    QJsonObject request;
    request["Action"] = "createUser";
    request["FullName"] = m_fullName;
    request["Age"] = m_age;
    request["UserName"] = m_username;
    request["Password"] = m_password;
    request["Balance"] = m_balance;
    request["Email"] = m_email;
    request["PhoneNumber"] = m_phoneNumber;
    request["Authentication"] = m_userType;
    return request;

}
