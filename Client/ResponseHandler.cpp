#include "ResponseHandler.h"
#include "mainwindow.h"

ResponseHandler::ResponseHandler(MainWindow *mainWindow, QObject *parent)
    : QObject(parent), m_mainWindow(mainWindow)
{
}

void ResponseHandler::handleResponse(const QJsonObject &response)
{
    if (response.contains("Action") && response["Action"].isString())
    {
        QString action = response["Action"].toString();

        if (action == "login")
        {
            m_mainWindow->displayLoginResult(response);
        }
        else if (action == "getAccountNumberUser")
        {
            m_mainWindow->displayUserAccountNumber(response);
        }
        else if (action == "getAccountNumberAdmin")
        {
            m_mainWindow->displayAdminAccountNumber(response);
        }
        else if (action == "viewTransactionHistory")
        {
            m_mainWindow->displayTransactionHistory(response);
        }
        else if (action == "viewAccountDetails")
        {
            m_mainWindow->displayAccountDetails(response);
        }
        else if (action == "viewBankDatabase")
        {
            m_mainWindow->displayBankDatabase(response);
        }
        else if (action == "createUser" || action == "updateUser" || action == "deleteUser")
        {
            m_mainWindow->displayAdminOperationResult(response);
        }
        else if (action == "makeTransaction" || action == "transferAmount")
        {
            m_mainWindow->displayUserOperationResult(response);
        }
        else if(action == "viewBalance")
        {
            m_mainWindow->displayBalance(response);
        }
    }
    else
    {
        qWarning() << "Response does not contain a valid 'Action' field.";
    }
}
