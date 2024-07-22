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
    : QObject(parent), filePath("D:\\ITIDA_FINAL_PROJECT3\\Server\\BankDataBase.json")
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

bool DataBaseManager::transferAmount(const QString &sender, const QString &recipient, double amount)
{

    // Load the existing accounts from data
    QJsonArray accounts = data["Accounts"].toArray();

    QJsonObject senderAccount;
    QJsonObject recipientAccount;

    // Find the sender and recipient accounts
    for (const QJsonValue &value : accounts)
    {
        QJsonObject account = value.toObject();
        if (account["UserName"].toString() == sender)
        {
            senderAccount = account;
        }
        else if (account["UserName"].toString() == recipient)
        {
            recipientAccount = account;
        }
    }

    // Check if both accounts were found
    if (senderAccount.isEmpty() || recipientAccount.isEmpty())
    {
        qDebug() << "Sender or recipient account not found.";
        return false;
    }

    // Get and update sender's balance
    double senderBalance = senderAccount["Balance"].toString().toDouble();
    if (senderBalance < amount)
    {
        qDebug() << "Insufficient balance.";
        return false;
    }
    senderBalance -= amount;
    senderAccount["Balance"] = QString::number(senderBalance, 'f', 2);

    // Get and update recipient's balance
    double recipientBalance = recipientAccount["Balance"].toString().toDouble();
    recipientBalance += amount;
    recipientAccount["Balance"] = QString::number(recipientBalance, 'f', 2);

    // Update sender's transaction history
    QJsonArray senderHistory = senderAccount["TransactionHistory"].toArray();
    QJsonObject senderTransaction;
    senderTransaction["Amount"] = QString::number(amount, 'f', 2);
    senderTransaction["Timestamp"] = QDateTime::currentDateTime().toString("ddd MMM dd HH:mm:ss yyyy");
    senderTransaction["TransactionType"] = "Withdrawal";
    senderHistory.append(senderTransaction);
    senderAccount["TransactionHistory"] = senderHistory;

    // Update recipient's transaction history
    QJsonArray recipientHistory = recipientAccount["TransactionHistory"].toArray();
    QJsonObject recipientTransaction;
    recipientTransaction["Amount"] = QString::number(amount, 'f', 2);
    recipientTransaction["Timestamp"] = QDateTime::currentDateTime().toString("ddd MMM dd HH:mm:ss yyyy");
    recipientTransaction["TransactionType"] = "Deposit";
    recipientHistory.append(recipientTransaction);
    recipientAccount["TransactionHistory"] = recipientHistory;

    // Update the accounts in the JSON data
    for (int i = 0; i < accounts.size(); ++i)
    {
        QJsonObject account = accounts[i].toObject();
        if (account["UserName"].toString() == sender)
        {
            accounts[i] = senderAccount;
        }
        else if (account["UserName"].toString() == recipient)
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

bool DataBaseManager::addTransaction(const QString &accountNumber, const QJsonObject &transaction)
{
    QJsonObject account = getAccountDetails(accountNumber);
    if (account.isEmpty())
    {
        return false;
    }

    QJsonArray history = account["TransactionHistory"].toArray();
    history.append(transaction);
    account["TransactionHistory"] = history;

    return updateUser(accountNumber, account);
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
