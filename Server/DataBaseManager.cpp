#include "DataBaseManager.h"
#include "Memento.h"
#include <QFile>
#include <QJsonDocument>
#include <QDebug>

// Initialize the static instance pointer

// Initialize the singleton instance
DataBaseManager& DataBaseManager::getInstance()
{
    static DataBaseManager instance;
    return instance;
}


DataBaseManager::DataBaseManager(QObject *parent)
    : QObject(parent), filePath("E:\\ITIDA_FINAL_PROJECT3\\Server\\BankDataBase.json")
{
    loadData();
}

void DataBaseManager::loadData()
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Could not open file for reading:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (doc.isNull() || !doc.isObject())
    {
        qWarning() << "Invalid JSON data";
        return;
    }
    data = doc.object();
}

bool DataBaseManager::saveData()
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qWarning() << "Could not open file for writing:" << file.errorString();
        return false;
    }

    QJsonDocument doc(data);
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
    return true;
}

bool DataBaseManager::transferAmount(const QString &senderAccountNumber, const QString &recipientAccountNumber, const QString &amountStr)
{
    // Convert amount from QString to double
    bool conversionOk;
    double amount = amountStr.toDouble(&conversionOk);
    if (!conversionOk)
    {
        qDebug() << "Invalid amount format.";
        return false;
    }

    // Load the existing accounts from data
    QJsonArray accounts = data["Accounts"].toArray();

    QJsonObject senderAccount;
    QJsonObject recipientAccount;
    bool senderFound = false;
    bool recipientFound = false;

    // Find the sender and recipient accounts
    for (const QJsonValue &value : accounts)
    {
        QJsonObject account = value.toObject();
        QString accountNumber = account["AccountNumber"].toString();

        if (accountNumber == senderAccountNumber)
        {
            senderAccount = account;
            senderFound = true;
        }
        else if (accountNumber == recipientAccountNumber)
        {
            recipientAccount = account;
            recipientFound = true;
        }
    }

    // Check if both accounts were found
    if (!senderFound || !recipientFound)
    {
        qDebug() << "Sender or recipient account not found.";
        return false;
    }

    // Get and update sender's balance
    double senderBalance = senderAccount["Balance"].toString().toDouble(&conversionOk);
    if (!conversionOk)
    {
        qDebug() << "Invalid balance format for sender account.";
        return false;
    }
    qDebug() << "Sender's current balance:" << senderBalance;

    if (senderBalance < amount)
    {
        qDebug() << "Insufficient balance.";
        return false;
    }
    senderBalance -= amount;
    senderAccount["Balance"] = QString::number(senderBalance, 'f', 2);

    // Get and update recipient's balance
    double recipientBalance = recipientAccount["Balance"].toString().toDouble(&conversionOk);
    if (!conversionOk)
    {
        qDebug() << "Invalid balance format for recipient account.";
        return false;
    }
    qDebug() << "Recipient's current balance:" << recipientBalance;

    recipientBalance += amount;
    recipientAccount["Balance"] = QString::number(recipientBalance, 'f', 2);

    // Update sender's transaction history
    QJsonArray senderHistory = senderAccount["TransactionHistory"].toArray();
    QJsonObject senderTransaction;
    senderTransaction["Amount"] = amount;
    senderTransaction["Timestamp"] = QDateTime::currentDateTime().toString("ddd MMM dd HH:mm:ss yyyy");
    senderTransaction["TransactionType"] = "Withdrawal";
    senderHistory.append(senderTransaction);
    senderAccount["TransactionHistory"] = senderHistory;

    // Update recipient's transaction history
    QJsonArray recipientHistory = recipientAccount["TransactionHistory"].toArray();
    QJsonObject recipientTransaction;
    recipientTransaction["Amount"] = amount;
    recipientTransaction["Timestamp"] = QDateTime::currentDateTime().toString("ddd MMM dd HH:mm:ss yyyy");
    recipientTransaction["TransactionType"] = "Deposit";
    recipientHistory.append(recipientTransaction);
    recipientAccount["TransactionHistory"] = recipientHistory;

    // Update the accounts in the JSON data
    for (int i = 0; i < accounts.size(); ++i)
    {
        QJsonObject account = accounts[i].toObject();
        QString accountNumber = account["AccountNumber"].toString();
        if (accountNumber == senderAccountNumber)
        {
            accounts[i] = senderAccount;
        }
        else if (accountNumber == recipientAccountNumber)
        {
            accounts[i] = recipientAccount;
        }
    }
    data["Accounts"] = accounts;

    // Save the updated data to the JSON file
    bool result = saveData();
    if (!result)
    {
        qDebug() << "Failed to save data.";
        return false;
    }

    return true;
}


bool DataBaseManager::addTransaction(const QString &accountNumber, const QJsonObject &transaction)
{
    // Get the array of accounts from the JSON data
    QJsonArray accounts = data["Accounts"].toArray();

    // Iterate through each account in the array
    for (int i = 0; i < accounts.size(); ++i)
    {
        QJsonObject account = accounts[i].toObject();

        // Check if the current account number matches the provided account number
        if (account["AccountNumber"].toString() == accountNumber)
        {
            // Get the current balance of the account
            double currentBalance = account["Balance"].toString().toDouble();

            // Get the transaction amount
            double amount = transaction["Amount"].toDouble();
            QString action = transaction["TransactionType"].toString();

            // Update the balance based on the type of transaction
            if (action == "Deposit")
            {
                currentBalance += amount;
            }
            else if (action == "Withdrawal")
            {
                // Ensure there are sufficient funds for the withdrawal
                if (currentBalance < amount)
                {
                    qDebug() << "Insufficient funds for account:" << accountNumber;
                    return false; // Insufficient funds
                }
                currentBalance -= amount; // Deduct the amount from the balance
            }
            else
            {
                qDebug() << "Unknown transaction type:" << action;
                return false; // Unknown action type
            }

            // Update the account balance
            account["Balance"] = QString::number(currentBalance, 'f', 2);

            // Get the transaction history array of the matched account
            QJsonArray transactions = account["TransactionHistory"].toArray();

            // Append the new transaction to the transaction history
            transactions.append(transaction);

            // Update the account's transaction history with the new transaction
            account["TransactionHistory"] = transactions;

            // Replace the old account object with the updated account object in the accounts array
            accounts[i] = account;

            // Update the data object with the modified accounts array
            data["Accounts"] = accounts;

            // Save the updated data back to the JSON file
            if (saveData())
            {
                qDebug() << "Transaction successfully added for account:" << accountNumber;
                return true;
            }
            else
            {
                qDebug() << "Failed to save data for account:" << accountNumber;
                return false;
            }
        }
    }

    qDebug() << "Account number not found:" << accountNumber;
    // Return false if the account number was not found
    return false;
}

bool DataBaseManager::updateUser(const QString &accountNumber, const QJsonObject &updatedUser)
{

    QJsonArray accounts = data["Accounts"].toArray();
    for (int i = 0; i < accounts.size(); ++i)
    {
        QJsonObject account = accounts[i].toObject();
        if (account["AccountNumber"].toString() == accountNumber)
        {
            // Update the specific account object with new values
            accounts[i] = updatedUser;
            data["Accounts"] = accounts;
            return saveData(); // Save changes to the file
        }
    }
    return false; // Return false if account not found
}

QJsonObject DataBaseManager::getUser(const QString &userName)
{
    QJsonArray accounts = data["Accounts"].toArray();
    for (const QJsonValue &value : accounts)
    {
        QJsonObject account = value.toObject();
        if (account["UserName"].toString() == userName)
        {
            return account;
        }
    }
    return QJsonObject();
}

QString DataBaseManager::getUserEmail(const QString &accountNumber)
{
    // Access the array of accounts from the JSON data
    QJsonArray accounts = data["Accounts"].toArray();

    // Iterate over each account in the array
    for (const QJsonValue &value : accounts)
    {
        // Convert each value to a JSON object
        QJsonObject account = value.toObject();

        // Check if the AccountNumber matches the provided accountNumber
        if (account["AccountNumber"].toString() == accountNumber)
        {
            // Return the email address for the matched account
            return account["Email"].toString();
        }
    }

    // Return an empty string if no account is found
    return QString();
}

QString DataBaseManager::getAccountNumber(const QString &userName)
{
    QJsonObject user = getUser(userName);
    if (!user.isEmpty() && user.contains("AccountNumber"))
    {
        return user["AccountNumber"].toString();
    }
    return QString();
}

bool DataBaseManager::createUser(const QJsonObject &newUser)
{
    QJsonArray accounts = data["Accounts"].toArray();

    for (const QJsonValue &value : accounts)
    {
        QJsonObject account = value.toObject();
        if (account["UserName"].toString() == newUser["UserName"].toString())
        {
            return false;
        }
    }

    QJsonObject userWithAccountNumber = newUser;
    userWithAccountNumber["AccountNumber"] = generateAccountNumber();

    if (!userWithAccountNumber.contains("Balance"))
    {
        userWithAccountNumber["Balance"] = "0.00";
    }
    else
    {
        QString balance = userWithAccountNumber["Balance"].toString();
        if (!balance.contains('.'))
        {
            balance += ".00";
        }
        userWithAccountNumber["Balance"] = balance;
    }

    accounts.append(userWithAccountNumber);
    data["Accounts"] = accounts;

    return saveData();
}

bool DataBaseManager::deleteUser(const QString &accountNumber)
{
    QJsonArray accounts = data["Accounts"].toArray();
    for (int i = 0; i < accounts.size(); ++i)
    {
        QJsonObject account = accounts[i].toObject();
        if (account["AccountNumber"].toString() == accountNumber)
        {
            accounts.removeAt(i);
            data["Accounts"] = accounts;
            return saveData();
        }
    }
    return false;
}

QString DataBaseManager::viewBalance(const QString &accountNumber)
{

    // Check if the data is valid
    if (!data.contains("Accounts") || !data["Accounts"].isArray())
    {
        qDebug() << "Data does not contain 'Accounts' array.";
        return QString();
    }

    QJsonArray accounts = data["Accounts"].toArray();  // Get the array of accounts from `data`

    for (const QJsonValue &value : accounts)
    {
        QJsonObject account = value.toObject();  // Convert the value to a QJsonObject

        // Check if the account number matches
        if (account["AccountNumber"].toString() == accountNumber)
        {
            if (account.contains("Balance") && account["Balance"].isString())  // Check if Balance field exists and is a string
            {
                QString balance = account["Balance"].toString();
                qDebug() << "Account found. Balance:" << balance;
                return balance;
            }
            else
            {
                qDebug() << "Balance field not found or not a string for account number:" << accountNumber;
                return QString();  // Handle missing or non-string balance field
            }
        }
    }

    qDebug() << "Account not found for account number:" << accountNumber;
    return QString();  // Return empty string or error message if account not found
}

QJsonArray DataBaseManager::getAllAccounts()
{
    return data["Accounts"].toArray();
}

QJsonObject DataBaseManager::getAccountDetails(const QString &accountNumber)
{
    QJsonArray accounts = data["Accounts"].toArray();
    for (const QJsonValue &value : accounts)
    {
        QJsonObject account = value.toObject();
        if (account["AccountNumber"].toString() == accountNumber)
        {
            return account;
        }
    }
    return QJsonObject();
}

QJsonArray DataBaseManager::getTransactionHistory(const QString &accountNumber)
{
    QJsonObject account = getAccountDetails(accountNumber);
    if (!account.isEmpty() && account.contains("TransactionHistory"))
    {
        return account["TransactionHistory"].toArray();
    }
    return QJsonArray();
}


QString DataBaseManager::generateAccountNumber()
{
    QJsonArray accounts = data["Accounts"].toArray();
    int highestNumber = 0;

    for (const QJsonValue &value : accounts)
    {
        QJsonObject account = value.toObject();
        if (account.contains("AccountNumber"))
        {
            bool ok;
            int number = account["AccountNumber"].toString().toInt(&ok);
            if (ok && number > highestNumber)
            {
                highestNumber = number;
            }
        }
    }

    return QString::number(highestNumber + 1);
}

void DataBaseManager::saveState()
{
    // Save the current state of the database to the `savedState` member variable
    // Serialize the current state into QByteArray
    QJsonDocument doc(data);
    savedState = doc.toJson();
}

void DataBaseManager::restoreState(const Memento &memento)
{
    // Deserialize the state from QByteArray
    QJsonDocument doc = QJsonDocument::fromJson(memento.getState());
    data = doc.object();
}
