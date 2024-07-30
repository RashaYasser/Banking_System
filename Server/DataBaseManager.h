#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QDateTime>

class Memento;

class DataBaseManager : public QObject
{
    Q_OBJECT

public:
    static DataBaseManager& getInstance(); // Singleton instance access

    // Method to transfer amount between accounts
    bool transferAmount(const QString &senderAccountNumber, const QString &recipientAccountNumber, const QString &amountStr);
   // QJsonObject createTransaction(double amount, const QString &transactionType);


    // Method to get user details
    QJsonObject getUser(const QString &userName);
    QString getUserEmail(const QString &accountNumber);

    // Method to get account number for a given username
    QString getAccountNumber(const QString &userName);

    // Method to create a new user account
    bool createUser(const QJsonObject &newUser);

    // Method to update an existing user account
    bool updateUser(const QString &accountNumber, const QJsonObject &updatedUser);

    // Method to delete a user account
    bool deleteUser(const QString &accountNumber);

    // Method to view balance for a given account number
    QString viewBalance(const QString &accountNumber);

    // Method to get all accounts
    QJsonArray getAllAccounts();

    // Method to get account details for a given account number
    QJsonObject getAccountDetails(const QString &accountNumber);

    // Method to get transaction history for a given account number
    QJsonArray getTransactionHistory(const QString &accountNumber);

    // Method to add a transaction to an account
    bool addTransaction(const QString &accountNumber, const QJsonObject &transaction);

    // Method to save current data to the file
    bool saveData();

    // Method to generate a new unique account number
    QString generateAccountNumber();

    // Memento pattern methods
    // Method to save the current state
    void saveState();

    // Method to restore the state from a Memento
    void restoreState(const Memento &memento);

private:
    explicit DataBaseManager(QObject *parent = nullptr);

    // Path to the JSON file
    QString filePath;

    // JSON data structure
    QJsonObject data;

    // Method to load data from the JSON file
    void loadData();

    QByteArray savedState;  // Use QByteArray for Memento state

    // Static instance of the Singleton
    static DataBaseManager *instance_;
};

#endif // DATABASEMANAGER_H
