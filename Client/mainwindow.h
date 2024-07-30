#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MyClient.h"
#include <QMetaEnum>
#include <QListWidget>
#include <QDateTime>
#include <QMessageBox>
#include "RequestValidator.h"

#include "Request.h"
#include"LoginRequest.h"
#include"CreateNewUserRequest.h"
#include"DeleteUserRequest.h"
#include"GetAccountNumberAdminRequest.h"
#include"GetAccountNumberUserRequest.h"
#include"MakeTransactionRequest.h"
#include"TransferAmountRequest.h"
#include"UpdateUserRequest.h"
#include"ViewAccountDetailsRequest.h"
#include"ViewBalanceRequest.h"
#include"ViewBankDatabaseRequest.h"
#include"ViewTransactionHistoryRequest.h"

#include "ResponseHandler.h"


QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Represents the main window of the application.
 *
 * This class manages the user interface for the application, handles user interactions,
 * communicates with the server using the MyClient class, and processes various user operations.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a MainWindow object.
     * @param parent Optional parent widget.
     *
     * Initializes the MainWindow object and sets up the user interface.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for MainWindow.
     *
     * Cleans up resources used by the MainWindow object.
     */
    ~MainWindow();

public slots:
    /**************************** Slots to connect To Server ***********************************/

    /**
     * @brief Slot called to handle connection to the server.
     *
     * This slot is triggered when a connection to the server is established successfully.
     */
    void onConnectionDevice();

    /**
     * @brief Slot called to handle disconnection from the server.
     *
     * This slot is triggered when the connection to the server is closed or lost.
     */
    void onDisconnectedDevice();

    /**
     * @brief Slot called when a socket error occurs.
     * @param socketError The error that occurred.
     *
     * This slot handles errors that occur during socket communication and processes the error details.
     */
    void onErrorOccurredDevice(QAbstractSocket::SocketError socketError);

    /**
     * @brief Slot called when the socket state changes.
     * @param socketState The new state of the socket.
     *
     * This slot handles changes in the socket's state and updates the user interface accordingly.
     */
    void onStateChangedDevice(QAbstractSocket::SocketState socketState);

    /**
     * @brief Slot called when a response is received from the server.
     * @param response The JSON response from the server.
     *
     * This slot processes the server's response and updates the user interface with the received data.
     */
    //void onResponseReceived(const QJsonObject &response);

private slots:
    /**************************** Slots for handling user operations ****************************/

    /**
     * @brief Slot called to handle user login.
     *
     * This slot handles the user login operation, including sending login requests and processing responses.
     */
    void onLogin();

    /**
     * @brief Slot called to create a new user.
     *
     * This slot handles the creation of new user accounts, including sending requests and processing responses.
     */
    void createNewUser();

    /**
     * @brief Slot called to update user details.
     *
     * This slot handles the updating of existing user information, including sending update requests and processing responses.
     */
    void updateUser();

    /**
     * @brief Slot called to delete a user.
     *
     * This slot handles the deletion of user accounts, including sending deletion requests and processing responses.
     */
    void deleteUser();

    /**
     * @brief Slot called to view transaction history.
     *
     * This slot handles the operation of viewing a user's transaction history, including sending requests and displaying results.
     */
    void viewTransactionHistory();

    /**
     * @brief Slot called to view account details.
     *
     * This slot handles the operation of viewing details of a user’s account, including sending requests and displaying results.
     */
    void viewAccountDetails();

    /**
     * @brief Slot called to view the bank database.
     *
     * This slot handles the operation of viewing the bank's database, including sending requests and displaying results.
     */
    void viewBankDatabase();

    /**
     * @brief Slot called to view the balance of an account.
     *
     * This slot handles the operation of viewing the balance of a user's account, including sending requests and displaying results.
     */
    void viewBalance();

    /**
     * @brief Slot called to make a transaction.
     *
     * This slot handles the operation of making a financial transaction, including sending requests and processing responses.
     */
    void makeTransaction();

    /**
     * @brief Slot called to transfer an amount between accounts.
     *
     * This slot handles the operation of transferring funds between accounts, including sending transfer requests and processing responses.
     */
    void transferAmount();

    /**
     * @brief Slot called to get the account number for an admin.
     *
     * This slot handles the operation of retrieving account numbers for admin purposes.
     */
    void getAccountNumberAdmin();

    /**
     * @brief Slot called to get the account number for a user.
     *
     * This slot handles the operation of retrieving account numbers for user purposes.
     */
    void getAccountNumberUser();

    /********************************** UI direct slots *********************************/

    /**
     * @brief Slot called when the Connect button is clicked.
     *
     * This slot initiates a connection to the server when the Connect button is pressed.
     */
    void on_PB_Connect_clicked();

    /**
     * @brief Slot called when the Disconnect button is clicked.
     *
     * This slot closes the connection to the server when the Disconnect button is pressed.
     */
    void on_PB_Disconnect_clicked();

    /**
     * @brief Slot called when the Clear button is clicked.
     *
     * This slot clears the user interface elements when the Clear button is pressed.
     */
    void on_PB_Clear_clicked();

    /**
     * @brief Slot called when the Start button is clicked.
     *
     * This slot handles operations related to starting an action when the Start button is pressed.
     */
    void on_Pb_Start_clicked();

    /**
     * @brief Slot called when the View Account Details button is clicked.
     *
     * This slot handles the operation of viewing account details when the View Account Details button is pressed.
     */
    void on_PB_ViweAccountDetails_clicked();

    /**
     * @brief Slot called when the Transaction History button is clicked.
     *
     * This slot handles the operation of viewing transaction history when the Transaction History button is pressed.
     */
    void on_PB_TransactionHistory_clicked();

    /**
     * @brief Slot called when the View Bank Database button is clicked.
     *
     * This slot handles the operation of viewing the bank database when the View Bank Database button is pressed.
     */
    void on_PB_viewBankDatabase_clicked();

    /**
     * @brief Slot called when the Clear User List Widget button is clicked.
     *
     * This slot clears the user list widget when the Clear User List Widget button is pressed.
     */
    void on_PB_ClearUserLw_clicked();

    /**
     * @brief Slot called when the Transaction History Admin button is clicked.
     *
     * This slot handles the operation of viewing transaction history for admins when the Transaction History Admin button is pressed.
     */
    void on_PB_TransactionHistoryAdmin_clicked();

    /**
     * @brief Slot called when the View Account Details Admin button is clicked.
     *
     * This slot handles the operation of viewing account details for admins when the View Account Details Admin button is pressed.
     */
    void on_PB_ViweAccountDetailsAdmin_clicked();

    /**
     * @brief Slot called when the Clear Transaction List Widget button is clicked.
     *
     * This slot clears the transaction list widget when the Clear Transaction List Widget button is pressed.
     */
    void on_PB_ClearLwTrans_clicked();

    /**
     * @brief Slot called when an item in the second combo box is selected.
     * @param index The index of the selected item.
     *
     * This slot handles changes in the selection of the second combo box.
     */
    void on_comboBox_2_activated(int index);

    /**
     * @brief Slot called when an item in the third combo box is selected.
     * @param index The index of the selected item.
     *
     * This slot handles changes in the selection of the third combo box.
     */
    void on_comboBox_3_activated(int index);

    /**
     * @brief Slot called when an item in the fourth combo box is selected.
     * @param index The index of the selected item.
     *
     * This slot handles changes in the selection of the fourth combo box.
     */
    void on_comboBox_4_activated(int index);

    /**
     * @brief Slot called when the Clear Bank Database button is clicked.
     *
     * This slot clears the bank database display when the Clear Bank Database button is pressed.
     */
    void on_PB_ClearBankDp_clicked();

    /**
     * @brief Slot called when the Clear Account Details button is clicked.
     *
     * This slot clears the account details display when the Clear Account Details button is pressed.
     */
    void on_PB_ClearLwAccDetails_clicked();

    /**
     * @brief Slot called when the Push Button is clicked.
     *
     * This slot handles operations related to the Push Button when it is pressed.
     */
    void on_pushButton_clicked();

    void on_comboBox_11_activated(int index);

public:
    /************************** Display Methods **********************************/

    /**
     * @brief Displays the result of a login operation.
     * @param response The JSON response from the server containing login result details.
     *
     * This method updates the user interface to show the result of a login attempt.
     */
    void displayLoginResult(const QJsonObject &response);

    /**
     * @brief Displays the balance of an account.
     * @param response The JSON response from the server containing account balance details.
     *
     * This method updates the user interface to show the balance of an account.
     */
    void displayBalance(const QJsonObject &response);

    /**
     * @brief Displays the account number for a user.
     * @param response The JSON response from the server containing the user's account number.
     *
     * This method updates the user interface to show the account number for a user.
     */
    void displayUserAccountNumber(const QJsonObject &response);

    /**
     * @brief Displays the account number for an admin.
     * @param response The JSON response from the server containing the admin's account number.
     *
     * This method updates the user interface to show the account number for an admin.
     */
    void displayAdminAccountNumber(const QJsonObject &response);

    /**
     * @brief Displays the transaction history.
     * @param response The JSON response from the server containing transaction history details.
     *
     * This method updates the user interface to show the transaction history.
     */
    void displayTransactionHistory(const QJsonObject &response);

    /**
     * @brief Displays account details.
     * @param response The JSON response from the server containing account details.
     *
     * This method updates the user interface to show the details of an account.
     */
    void displayAccountDetails(const QJsonObject &response);

    /**
     * @brief Displays the bank database.
     * @param response The JSON response from the server containing the bank database.
     *
     * This method updates the user interface to show the bank database.
     */
    void displayBankDatabase(const QJsonObject &response);

    /**
     * @brief Displays the result of an admin operation.
     * @param response The JSON response from the server containing the result of an admin operation.
     *
     * This method updates the user interface to show the result of an admin operation.
     */
    void displayAdminOperationResult(const QJsonObject &response);

    /**
     * @brief Displays the result of a user operation.
     * @param response The JSON response from the server containing the result of a user operation.
     *
     * This method updates the user interface to show the result of a user operation.
     */
    void displayUserOperationResult(const QJsonObject &response);
    /**
     * @brief Checks if the current user is an admin.
     * @return True if the current user is an admin, false otherwise.
     *
     * This method determines whether the logged-in user has admin privileges.
     */
    bool isAdmin() const;
    void logTransfer(const QString &fromAccountNumber, const QString &toAccountNumber, const QString &amount);

private:
    Ui::MainWindow *ui; // UI object for the main window
    MyClient client; // Client object for handling client-specific tasks
    QString currentUser; // Current user logged in
    QString Authentication; // User type or authentication level ("user" or "admin")
    QString message; // Message string for various purposes
    QString currentAccountNumber; // Current account number

    /************************************** Operations *********************************/

    /**
     * @brief Sets up connections between UI elements and their corresponding slots.
     *
     * This method connects UI elements like buttons and combo boxes to their respective slots.
     */
    void setupConnections();
    void handleResponse(const QJsonObject &response);
    ResponseHandler *responseHandler;


};

#endif // MAINWINDOW_H
