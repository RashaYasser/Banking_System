#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QJsonObject>
#include <QJsonArray>

// Forward declaration of DataBaseManager
class DataBaseManager;

// Base class for handling requests
class RequestHandler
{
public:
    virtual ~RequestHandler() {} // Virtual destructor for proper cleanup
    // Method to handle requests and generate responses
    virtual QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) = 0;
};

// Manages the response based on the action
class ReceivedResponseHandler
{
public:
    // Constructor to initialize the appropriate handler based on action
    ReceivedResponseHandler(const QString &action);
    // Handles the response by delegating to the appropriate handler
    QJsonObject handleResponse(const QJsonObject &request, DataBaseManager &dbManager);

private:
    RequestHandler *handler; // Pointer to the appropriate RequestHandler
};


// Handler for login requests
class LoginHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};

// Handler for creating a new user
class CreateUserHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};

// Handler for updating user information
class UpdateUserHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};

// Handler for deleting a user
class DeleteUserHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};

// Handler for transferring amounts between accounts
class TransferAmountHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};

// Handler for viewing account balance
class ViewBalanceHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};

// Handler for viewing transaction history
class ViewTransactionHistoryHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};

// Handler for viewing account details
class ViewAccountDetailsHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};

// Handler for viewing the entire bank database (admin only)
class ViewBankDatabaseHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};

// Handler for making transactions
class MakeTransactionHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};


// Handler for retrieving account number for admin requests
class GetAccountNumberAdminHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};

// Handler for retrieving account number for user requests
class GetAccountNumberUserHandler : public RequestHandler
{
public:
    QJsonObject handle(const QJsonObject &request, DataBaseManager &dbManager) override;
};


#endif // REQUESTHANDLER_H
