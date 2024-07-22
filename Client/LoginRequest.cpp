#include "LoginRequest.h"

LoginRequest::LoginRequest(const QString& username, const QString& password)
    : m_username(username), m_password(password) {}

QJsonObject LoginRequest::toJson() const
{
    QJsonObject request; // Create a JSON object to hold the request
    request["Action"] = "login"; // Set the action to "login"
    request["UserName"] = m_username; // Add the username to the request
    request["Password"] = m_password; // Add the password to the request
    return request;
}
