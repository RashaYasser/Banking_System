#include"RequestHandler.h"
#include "DataBaseManager.h"
// Initializes the appropriate handler based on action
ReceivedResponseHandler::ReceivedResponseHandler(const QString &action)
{

    // Handle the request based on the action
    if (action == "login")
    {
        qDebug()<<"login  request ";
        handler = new LoginHandler();
    }
    else if (action == "createUser")
    {
        handler = new CreateUserHandler();
    }
    else if (action == "updateUser")
    {
        handler = new UpdateUserHandler();
    }
    else if (action == "deleteUser")
    {
        handler = new DeleteUserHandler();
    }
    else if (action == "viewBalance")
    {
        qDebug()<<"viewBalance  request ";
        handler = new ViewBalanceHandler();
    }
    else if (action == "transferAmount")
    {
        handler = new TransferAmountHandler();
    }
    else if (action == "viewTransactionHistory")
    {
        handler = new ViewTransactionHistoryHandler();
    }
    else if (action == "viewAccountDetails")
    {
        handler = new ViewAccountDetailsHandler();
    }
    else if (action == "viewBankDatabase")
    {
        handler = new ViewBankDatabaseHandler();
    }
    else if (action == "makeTransaction")
    {
        handler = new MakeTransactionHandler();
    }
    else if (action == "getAccountNumberAdmin")
    {
        handler = new GetAccountNumberAdminHandler();
    }
    else if (action == "getAccountNumberUser")
    {
        handler = new GetAccountNumberUserHandler();
    }
    else
    {
        handler = nullptr;
    }
}

// Handles the response by delegating to the appropriate handler
QJsonObject ReceivedResponseHandler::handleResponse(const QJsonObject &request, DataBaseManager &dbManager)
{
    if (handler)
    {
        QJsonObject response = handler->handle(request, dbManager);
        delete handler; // Clean up the handler after use
        return response;
    }
    else
    {
        QJsonObject response;
        response["Status"] = "Failure";
        response["Message"] = "Handler not found.";
        response["Action"] = "Unknown";
        return response;
    }
}

// Handles login requests
QJsonObject LoginHandler::handle(const QJsonObject &request, DataBaseManager &dbManager)
{
    QJsonObject response;
    QString username = request["UserName"].toString();
    QString password = request["Password"].toString();
    QJsonObject user = dbManager.getUser(username);
    if (!user.isEmpty() && user["Password"].toString() == password)
    {
        response["Action"] = "login";
        response["Status"] = "Success";
        response["UserName"] = username;
        response["Authentication"] = user["Authentication"].toString();
        response["AccountNumber"] = dbManager.getAccountNumber(username);

        response["Message"] = "Login Successful Welcome,";

    }
    else
    {
        response["Action"] = "login";
        response["Status"] = "Failure";
        response["Message"] = "Login Failure ,Wrong Passowrd or UserName";

    }
    return response;
}

// Handles creating new users
QJsonObject CreateUserHandler::handle(const QJsonObject &request, DataBaseManager &dbManager)
{
    QJsonObject response;

    if (!request.contains("UserName") || !request.contains("FullName") || !request.contains("Password"))
    {
        response["Status"] = "Failure";
        response["Message"] = "Missing required fields.";
        response["Action"] = "createUser";
        return response;
    }

    QJsonObject newUser;
    newUser["FullName"] = request["FullName"].toString();
    newUser["UserName"] = request["UserName"].toString();
    newUser["Password"] = request["Password"].toString();
    newUser["Balance"] = request["Balance"].toString();
    newUser["Email"] = request["Email"].toString();
    newUser["PhoneNumber"] = request["PhoneNumber"].toString();
    newUser["Authentication"] = request["Authentication"].toString();

    bool success = dbManager.createUser(newUser); // Add user to the database
    response["Status"] = success ? "Success" : "Failure";
    response["Action"] = "createUser";
    response["Message"] = success ? "User created successfully" : "Failed to create user";

    return response;
}

// Handles updating user information
QJsonObject UpdateUserHandler::handle(const QJsonObject &request, DataBaseManager &dbManager)
{
    QJsonObject response;
    QString accountNumber = request["AccountNumber"].toString();

    // Check if AccountNumber is present in the request
    if (accountNumber.isEmpty())
    {
        response["Status"] = "Failure";
        response["Message"] = "Missing Account Number.";
        response["Action"] = "updateUser";
        return response;
    }

    // Find the user with the specified account number
    QJsonObject existingUser;
    QJsonArray accounts = dbManager.getAllAccounts();
    for (const QJsonValue &value : accounts)
    {
        QJsonObject account = value.toObject();
        if (account["AccountNumber"].toString() == accountNumber)
        {
            existingUser = account;
            break;
        }
    }

    if (existingUser.isEmpty())
    {
        response["Status"] = "Failure";
        response["Message"] = "Account not found.";
        response["Action"] = "updateUser";
        return response;
    }

    // Update only the fields provided in the request
    if (request.contains("UserName"))
    {
        existingUser["UserName"] = request["UserName"].toString();
    }
    if (request.contains("Password"))
    {
        existingUser["Password"] = request["Password"].toString();
    }
    if (request.contains("Email"))
    {
        existingUser["Email"] = request["Email"].toString();
    }
    if (request.contains("PhoneNumber"))
    {
        existingUser["PhoneNumber"] = request["PhoneNumber"].toString();
    }

    // Update user in the database
    bool success = dbManager.updateUser(accountNumber, existingUser);

    response["Status"] = success ? "Success" : "Failure";
    response["Action"] = "updateUser";
    response["Message"] = success ? "User updated successfully." : "Failed to update user.";

    return response;
}

// Handles deleting a user
QJsonObject DeleteUserHandler::handle(const QJsonObject &request, DataBaseManager &dbManager)
{

    QJsonObject response;
    QString accountNum = request["AccountNumber"].toString();
    // Check if required fields are present
    if (!request.contains("AccountNumber"))
    {
        response["Status"] = "Failure";
        response["Message"] = "Missing Account Number fields.";
        response["Action"] = "deleteUser";
        return response;
    }

    // Pass the user data to the database manager
    bool success = dbManager.deleteUser(accountNum);
    response["Status"] = success ? "Success" : "Failure";
    response["Action"] = "deleteUser";
    response["Message"] = success ? "User Deleted successfully" : "Failed to Delete User";

    return response;
}

// Handles transferring amounts between accounts
QJsonObject TransferAmountHandler::handle(const QJsonObject &request, DataBaseManager &dbManager)
{
    QJsonObject response;

    // Validate the request
    if (!request.contains("Sender") || !request.contains("Recipient") || !request.contains("Amount"))
    {
        response["Status"] = "Failure";
        response["Message"] = "Missing required fields.";
        response["Action"] = "transferAmount";
        return response;
    }

    QString sender = request["Sender"].toString();
    QString recipient = request["Recipient"].toString();
    QString amountStr = request["Amount"].toString();
    QString timestamp = request["Timestamp"].toString();

    if (sender.isEmpty())
    {
        response["Status"] = "Failure";
        response["Message"] = "Sender account not found.";
        response["Action"] = "transferAmount";
        return response;
    }

    if (recipient.isEmpty())
    {
        response["Status"] = "Failure";
        response["Message"] = "Recipient account not found.";
        response["Action"] = "transferAmount";
        return response;
    }

    // Perform the transaction
    bool transferResult = dbManager.transferAmount(sender, recipient, amountStr);
    if (!transferResult)
    {
        response["Status"] = "Failure";
        response["Message"] = "Transfer failed.";
        response["Action"] = "transferAmount";
        return response;
    }

    response["Status"] = "Success";
    response["Message"] = "Transfer successful.";
    response["Action"] = "transferAmount";
    response["Timestamp"] = timestamp; // Include timestamp in response
    return response;
}

// Handles viewing account balance
QJsonObject ViewBalanceHandler::handle(const QJsonObject &request, DataBaseManager &databaseManager)
{
    QJsonObject response;
    QString accountNum = request["AccountNumber"].toString();
    // Check if required fields are present
    if (!request.contains("AccountNumber"))
    {
        response["Status"] = "Failure";
        response["Message"] = "Missing Account Number fields.";
        response["Action"] = "viewBalance";
        return response;
    }

    QString balance = databaseManager.viewBalance(accountNum);
    if (balance.isEmpty())
    {
        response["Status"] = "Failure";
        response["Action"] = "viewBalance";
        response["Message"] = " Account not found. Please ensure the correct Account Number is provided";
    }
    else
    {
        response["Status"] = "Success";
        response["Action"] = "viewBalance";
        response["Balance"] = balance;
    }
    return response;
}

// Handles viewing transaction history
QJsonObject ViewTransactionHistoryHandler::handle(const QJsonObject &request, DataBaseManager &databaseManager)
{
    QJsonObject response;

    // Check if AccountNumber is provided
    if (!request.contains("AccountNumber"))
    {
        response["Status"] = "Failure";
        response["Message"] = "Missing required field: AccountNumber.";
        response["Action"] = "viewTransactionHistory";
        return response;
    }

    QString accountNum = request["AccountNumber"].toString();

    // Check if the user is an admin and ensure that AdminUsername is provided
    if (request.contains("AdminUsername"))
    {
        // Admins can request transaction history for any account
        QJsonArray transactionHistory = databaseManager.getTransactionHistory(accountNum);

        if (transactionHistory.isEmpty())
        {
            response["Status"] = "Failure";
            response["Action"] = "viewTransactionHistory";
            response["Message"] = "No transactions found for the provided Account Number.";
        }
        else
        {
            response["Status"] = "Success";
            response["Action"] = "viewTransactionHistory";
            response["TransactionHistory"] = transactionHistory;
        }
    }//non admin
    else if (request.contains("UserName"))
    {
        QString username = request["UserName"].toString();

        // Non-admin users can only request their own transaction history
        // Check if the account number matches the username
        QJsonObject account = databaseManager.getAccountDetails(accountNum);
        if (account.isEmpty() || account["UserName"].toString() != username)
        {
            response["Status"] = "Failure";
            response["Action"] = "viewTransactionHistory";
            response["Message"] = "Unauthorized access or Account Number mismatch.";
        }
        else
        {
            QJsonArray transactionHistory = databaseManager.getTransactionHistory(accountNum);

            if (transactionHistory.isEmpty())
            {
                response["Status"] = "Failure";
                response["Action"] = "viewTransactionHistory";
                response["Message"] = "No transactions found for the provided Account Number.";
            }
            else
            {
                response["Status"] = "Success";
                response["Action"] = "viewTransactionHistory";
                response["TransactionHistory"] = transactionHistory;
            }
        }
    }

    return response;
}

// Handles viewing account details
QJsonObject ViewAccountDetailsHandler::handle(const QJsonObject &request, DataBaseManager &databaseManager)
{
    QJsonObject response;

    // Check if AccountNumber is provided
    if (!request.contains("AccountNumber"))
    {
        response["Status"] = "Failure";
        response["Message"] = "Missing required field: AccountNumber.";
        response["Action"] = "viewAccountDetails";
        return response;
    }

    QString accountNum = request["AccountNumber"].toString();

    // Check if the user is an admin and ensure that AdminUsername is provided
    if (request.contains("AdminUsername"))
    {
        // Admins can request transaction history for any account
        QJsonObject accountDetails = databaseManager.getAccountDetails(accountNum);

        if (accountDetails.isEmpty())
        {
            response["Status"] = "Failure";
            response["Action"] = "viewAccountDetails";
            response["Message"] = "Not Found Details For provided Account Number.";
        }
        else
        {
            response["Status"] = "Success";
            response["Action"] = "viewAccountDetails";
            response["AccountDetails"] = accountDetails;
        }
    }//non admin
    else if (request.contains("UserName"))
    {
        QJsonObject accountDetails = databaseManager.getAccountDetails(accountNum);
        QString username = request["UserName"].toString();

        // Non-admin users can only request their own transaction history
        // Check if the account number matches the username
        if (accountDetails.isEmpty() || accountDetails["UserName"].toString() != username)
        {
            response["Status"] = "Failure";
            response["Action"] = "viewAccountDetails";
            response["Message"] = "Unauthorized access or Account Number mismatch.";
        }
        else
        {
            QJsonObject accountDetails = databaseManager.getAccountDetails(accountNum);

            if (accountDetails.isEmpty())
            {
                response["Status"] = "Failure";
                response["Action"] = "viewAccountDetails";
                response["Message"] = "Not Found the provided Account Number.";
            }
            else
            {
                response["Status"] = "Success";
                response["Action"] = "viewAccountDetails";
                response["AccountDetails"] = accountDetails;
            }
        }
    }

    return response;
}

// Handles viewing the bank database (admin only)
QJsonObject ViewBankDatabaseHandler::handle(const QJsonObject &request, DataBaseManager &dbManager)
{    QJsonObject response;
    QString userType =request["Authentication"].toString();

    if(userType=="Admin")
    {

        response["Status"] = "Success";
        response["Message"] = "Operation Successful";
        response["Action"] = "viewBankDatabase";
        QJsonArray accounts = dbManager.getAllAccounts();
        response["Accounts"] = accounts;

    }
    else
    {

        response["Status"] = "Failure";
        response["Action"] = "viewBankDatabase";
    }
    return response;
}

QJsonObject MakeTransactionHandler::handle(const QJsonObject &request, DataBaseManager &dbManager)
{
    QJsonObject response;
    // Extract details from the request
    QString action = request["TransactionType"].toString();
    QString accountNumber = request["AccountNumber"].toString();
    QString amountStr = request["Amount"].toString();
    QString timestamp = request["Timestamp"].toString();

    // Check if required fields are present
    if (action.isEmpty() || accountNumber.isEmpty() || amountStr.isEmpty())
    {
        response["Status"] = "Failure";
        response["Message"] = "Missing required fields.";
        response["Action"] = "makeTransaction";
        return response;
    }

    // Validate the amount
    bool ok;
    double amount = amountStr.toDouble(&ok);
    if (!ok || amount <= 0)
    {
        response["Status"] = "Failure";
        response["Message"] = "Invalid amount.";
        response["Action"] = "makeTransaction";
        return response;
    }

    // Create a transaction object
    QJsonObject transaction;
    transaction["Amount"] = amount;
    transaction["TransactionType"] = action;
    transaction["Timestamp"] = timestamp;

    // Add the transaction to the database
    bool success = dbManager.addTransaction(accountNumber, transaction);

    // Generate the response
    if (success)
    {
        response["Status"] = "Success";
        response["Message"] = "Transaction successful.";
        response["Action"] = "makeTransaction";
    }
    else
    {
        response["Status"] = "Failure";
        response["Message"] = "Transaction failed.";
        response["Action"] = "makeTransaction";
    }

    return response;
}

QJsonObject GetAccountNumberAdminHandler::handle(const QJsonObject &request, DataBaseManager &dbManager)
{
    qDebug() << "Received request:" << request;

    QJsonObject response;
    QString username = request["UserName"].toString();
    QString authentication = request["Authentication"].toString();

    if (!request.contains("UserName"))
    {
        response["Status"] = "Failure";
        response["Message"] = "Missing UserName field.";
        response["Action"] = "getAccountNumberAdmin";
        return response;
    }

    if (authentication != "Admin")
    {
        response["Status"] = "Failure";
        response["Message"] = "Unauthorized Access";
        response["Action"] = "getAccountNumberAdmin";
        return response;
    }

    QJsonObject userAccount = dbManager.getUser(username);
    qDebug() << "Fetched user account:" << userAccount;

    if (userAccount.isEmpty())
    {
        response["Status"] = "Failure";
        response["Message"] = "User not found.";
        response["Action"] = "getAccountNumberAdmin";
        return response;
    }

    if (!userAccount.contains("AccountNumber"))
    {
        response["Status"] = "Failure";
        response["Message"] = "Account number not found.";
        response["Action"] = "getAccountNumberAdmin";
        return response;
    }

    response["Status"] = "Success";
    response["Message"] = "Operation Successful";
    response["Action"] = "getAccountNumberAdmin";
    response["AccountNumber"] = userAccount["AccountNumber"].toString();
    return response;
}

QJsonObject GetAccountNumberUserHandler::handle(const QJsonObject &request, DataBaseManager &dbManager)
{
    QJsonObject response;

    // Ensure 'UserName' is present in the request
    if (!request.contains("UserName"))
    {
        response["Status"] = "Failure";
        response["Message"] = "Missing UserName field.";
        response["Action"] = "getAccountNumberUser"; // Ensure Action is set
        return response;
    }

    QString username = request["UserName"].toString();
    QJsonObject userAccount = dbManager.getUser(username);

    // Check if user account is found
    if (userAccount.isEmpty())
    {
        response["Status"] = "Failure";
        response["Message"] = "User not found.";
        response["Action"] = "getAccountNumberUser"; // Ensure Action is set

        return response;
    }

    response["Action"] = "getAccountNumberUser"; // Ensure Action is set
    response["Status"] = "Success";
    response["Message"] = "Operation Successful";
    response["AccountNumber"] = userAccount["AccountNumber"]; // Return the account number

    return response;
}
