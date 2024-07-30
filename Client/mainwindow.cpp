#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) // Call the QMainWindow constructor with the parent widget
    , ui(new Ui::MainWindow) // Initialize the UI pointer
    , currentUser("") // Initialize the currentUser as an empty string
    , Authentication("") // Initialize the Authentication as an empty string
    , currentAccountNumber("") // Initialize the currentAccountNumber as an empty string
{
    ui->setupUi(this);
    setupConnections(); // Function to connect UI buttons to their corresponding slots
    responseHandler = new ResponseHandler(this); // Create ResponseHandler instance

    /********************** Connect TcpSocket signals to MainWindow slots *********************/

    connect(&client,&MyClient::connected,this,&MainWindow::onConnectionDevice);
    connect(&client,&MyClient::disconnected,this,&MainWindow::onDisconnectedDevice);
    connect(&client,&MyClient::errorOccurred,this,&MainWindow::onErrorOccurredDevice);
    connect(&client,&MyClient::stateChanged,this,&MainWindow::onStateChangedDevice);
    connect(&client,&MyClient::responseReceived,this,&MainWindow::handleResponse);
}

MainWindow::~MainWindow()
{
    delete responseHandler;
    delete ui;
}
/************************pb*************/
// Slot to handle start button click
void MainWindow::on_Pb_Start_clicked()
{
    ui->tabWidget->setCurrentIndex(1);

}

void MainWindow::setupConnections()
{
    // Connect button clicks to respective slots
    connect(ui->PB_Login, &QPushButton::clicked, this, &MainWindow::onLogin);
    connect(ui->PB_createNewUser, &QPushButton::clicked, this, &MainWindow::createNewUser);
    connect(ui->PB_updateUser, &QPushButton::clicked, this, &MainWindow::updateUser);
    connect(ui->PB_deleteUser, &QPushButton::clicked, this, &MainWindow::deleteUser);
    connect(ui->PB_viewBalance_8, &QPushButton::clicked, this, &MainWindow::viewBalance);
    connect(ui->PB_viewTransactionHistoryFunction, &QPushButton::clicked, this, &MainWindow::viewTransactionHistory);
    connect(ui->PB_viewAccountDetailsFunction, &QPushButton::clicked, this, &MainWindow::viewAccountDetails);
    connect(ui->PB_viewBankDatabaseFunction, &QPushButton::clicked, this, &MainWindow::viewBankDatabase);
    connect(ui->PB_makeTransaction_8, &QPushButton::clicked, this, &MainWindow::makeTransaction);
    connect(ui->PB_transferAmount_8, &QPushButton::clicked, this, &MainWindow::transferAmount);
    connect(ui->PB_getAccountNumberAdmin, &QPushButton::clicked, this, &MainWindow::getAccountNumberAdmin);
    connect(ui->PB_getAccountNumberUser_8, &QPushButton::clicked, this, &MainWindow::getAccountNumberUser);
}
// Slot called when connection is established
void MainWindow::onConnectionDevice()
{
    ui->Lw_Connection->addItem("Client has connected to the server....");
    ui->tabWidget->setCurrentIndex(2); // Switch to the connection tab

}
// Slot called when disconnected
void MainWindow::onDisconnectedDevice()
{
    ui->Lw_Connection->addItem("Client has disconnected from the server....");
}

// Slot called when an error occurs
void MainWindow::onErrorOccurredDevice(QAbstractSocket::SocketError socketError)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    ui->Lw_Connection->addItem(meta.valueToKey(socketError));// Display the error message
}

// Slot called when socket state changes
void MainWindow::onStateChangedDevice(QAbstractSocket::SocketState socketState)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    ui->Lw_Connection->addItem(meta.valueToKey(socketState));
}

// Slot to handle connect button click
void MainWindow::on_PB_Connect_clicked()
{
    QString ip = ui->lE_IP->text(); // Get IP address from the UI
    qint32 port = ui->LE_Port->text().toInt(); // Get port number from the UI
    client.ConnectToDevice(ip, port); // Connect to the specified IP and port


     ui->lE_IP->clear();
     ui->LE_Port->clear();
}

// Slot to handle disconnect button click
void MainWindow::on_PB_Disconnect_clicked()
{
    client.Disconnect();// Disconnect from the server

}

void MainWindow::handleResponse(const QJsonObject &response)
{

    responseHandler->handleResponse(response); // Delegate response handling to ResponseHandler

}

/***************************************Slots Used to Send Requests*************************************************/
// Slot to handle login button click
void MainWindow::onLogin()
{
    // Retrieve the username from the user input field
    QString username = ui->LE_userName->text(); // Get the username from the input field

    // Retrieve the password from the user input field
    QString password = ui->LE_password->text(); // Get the password from the input field

    // Create a validator instance to check the login request details
    LoginRequestValidate validator(username, password);

    // Validate the username and password
    if (!validator.validate())
    {
        // Show a warning message if the validation fails
        QMessageBox::warning(this, "Validation Error", "Please enter both username and password.");
        return; // Exit the function if validation fails
    }

    // Create a login request object with the provided username and password
    LoginRequest loginRequest(username, password);

    // Convert the login request object to a QJsonObject for serialization
    QJsonObject request = loginRequest.toJson();

    // Define encryption and signature keys (ensure these are securely managed)
    const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
    const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity

    // Encrypt the JSON request data using the encryption key
    QByteArray encryptedData = Encryption::encrypt(request, encryptionKey);

    // Generate a signature for the encrypted data using the signature key
    QByteArray signature = Signature::sign(encryptedData, signatureKey);

    // Combine the encrypted data with the signature
    QByteArray finalData = encryptedData + signature;

    // Send the final encrypted and signed data to the server
    client.sendData(finalData);
    // Clear the input fields after successful login
    ui->LE_userName->clear(); // Clear the username field
    ui->LE_password->clear(); // Clear the password field
}

// Slot to handle Create a New user
void MainWindow::createNewUser()
{
    QString fullname = ui->LE_newFullName->text();
    QString age = ui->LE_userAge->text();
    QString username = ui->LE_newUsername->text();
    QString password = ui->LE_newPassword->text();
    QString balance = ui->LE_initialBalance->text();
    QString phoneNumber = ui->LE_phoneNumber->text();
    QString email = ui->LE_userEmail->text();        
    QString usertype = ui->comboBox_2->currentText();

    // Check if current user is an admin
    if (isAdmin())
    {
        // Create the request object
        CreateNewUserRequest createNewUserRequest(fullname, age, username, password, balance, phoneNumber, email, usertype);

        // Validate the request
        CreateUserRequestValidate validator(createNewUserRequest.toJson());
        if (!validator.validate())
        {
            // Handle validation failure (e.g., show an error message to the user)
            QMessageBox::warning(this, "Validation Error", "Please enter valid user details.");
            return;
        }

        // Convert the request to JSON
        QJsonObject requestJson = createNewUserRequest.toJson();

        // Define encryption and signature keys (ensure these are securely managed)
        const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
        const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity


        // Encrypt the JSON request data using the encryption key
        QByteArray encryptedData = Encryption::encrypt(requestJson, encryptionKey);

        // Generate a signature for the encrypted data using the signature key
        QByteArray signature = Signature::sign(encryptedData, signatureKey);

        // Combine the encrypted data with the signature
        QByteArray finalData = encryptedData + signature;

        // Send the final encrypted and signed data to the server
        client.sendData(finalData);

        ui->LE_newFullName->clear();
        ui->LE_newPassword->clear();
        ui->LE_newUsername->clear();
        ui->LE_initialBalance->clear();
        ui->LE_phoneNumber->clear();
        ui->LE_userAge->clear();
        ui->LE_userEmail->clear();

    }
    else
    {
        QMessageBox::warning(this, "Access Denied", "Only Administrators can create new users.");
    }
}

// Slot to handle Update user
void MainWindow::updateUser()
{
    QString accountNumber = ui->LE_updateAccountNumber->text();
    QString newPassword = ui->LE_updatePassword->text();
    QString username = ui->LE_updateUsername->text();
    QString newEmail = ui->LE_updateUserEmail->text();
    QString newPhoneNumber = ui->LE_updatePhoneNum->text();

    // Check if current user is an admin
    if (isAdmin())
    {
        // Create the request object
        UpdateUserRequest updateUserRequest(accountNumber, newPassword, username, newEmail, newPhoneNumber);

        // Validate the request
        // UpdateUserRequestValidate validator(accountNumber);
        // if (!validator.validate())
        // {
        //     QMessageBox::warning(this, "Validation Error", "Please enter valid user details.");
        //     return;
        // }

        // Convert the request to JSON
        QJsonObject requestJson = updateUserRequest.toJson();

        // Define encryption and signature keys
        // Define encryption and signature keys (ensure these are securely managed)
        const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
        const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity

        // Encrypt the JSON request data using the encryption key
        QByteArray encryptedData = Encryption::encrypt(requestJson, encryptionKey);

        // Generate a signature for the encrypted data using the signature key
        QByteArray signature = Signature::sign(encryptedData, signatureKey);

        // Combine the encrypted data with the signature
        QByteArray finalData = encryptedData + signature;

        // Send the final encrypted and signed data to the server
        client.sendData(finalData);

        ui->LE_updateAccountNumber->clear();
        ui->LE_updateUsername->clear();
        ui->LE_updateUserEmail->clear();
        ui->LE_updatePhoneNum->clear();
        ui->LE_updatePassword->clear();

    }
    else
    {
        QMessageBox::warning(this, "Access Denied", "Only Administrators can update user information.");
    }
}

// Slot to handle Delete user
void MainWindow::deleteUser()
{
    QString accountNumber = ui->LE_deleteUserAccountNumber->text();

    // Check if current user is an admin
    if (isAdmin())
    {
        // Create the request object
        DeleteUserRequest deleteUserRequest(accountNumber);

        // Validate the request
        DeleteUserRequestValidate validator(accountNumber);
        if (!validator.validate())
        {
            // Handle validation failure
            QMessageBox::warning(this, "Validation Error", "Please enter Account number.");
            return;
        }

        // Convert the request to JSON
        QJsonObject requestJson = deleteUserRequest.toJson();

        // Define encryption and signature keys
        // Define encryption and signature keys (ensure these are securely managed)
        const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
        const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity


        // Encrypt the JSON request data using the encryption key
        QByteArray encryptedData = Encryption::encrypt(requestJson, encryptionKey);

        // Generate a signature for the encrypted data using the signature key
        QByteArray signature = Signature::sign(encryptedData, signatureKey);

        // Combine the encrypted data with the signature
        QByteArray finalData = encryptedData + signature;

        // Send the final encrypted and signed data to the server
        client.sendData(finalData);
        ui->LE_deleteUserAccountNumber->clear();

    }
    else
    {
        QMessageBox::warning(this, "Access Denied", "Only Administrators can delete users.");
    }
}

void MainWindow::viewBalance()
{
    QString accountNumber = ui->LE_accountNumber_8->text();

    // Create the request object
    ViewBalanceRequest viewBalanceRequest(accountNumber, currentUser);

    // Validate the request
    ViewBalanceRequestValidate validator(accountNumber, currentAccountNumber);
    if (!validator.validate())
    {
        QMessageBox::warning(this, "Validation Error", "Please Enter Your account number.");
        return;
    }

    // Convert the request to JSON
    QJsonObject requestJson = viewBalanceRequest.toJson();

    // Define encryption and signature keys
    // Define encryption and signature keys (ensure these are securely managed)
    const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
    const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity


    // Encrypt the JSON request data using the encryption key
    QByteArray encryptedData = Encryption::encrypt(requestJson, encryptionKey);

    // Generate a signature for the encrypted data using the signature key
    QByteArray signature = Signature::sign(encryptedData, signatureKey);

    // Combine the encrypted data with the signature
    QByteArray finalData = encryptedData + signature;

    // Send the final encrypted and signed data to the server
    client.sendData(finalData);
    ui->LE_accountNumber_8->clear();

}

void MainWindow::viewTransactionHistory()
{
    QString accountNumber = ui->LE_transactionAccountNumber->text();
    QString username = ui->LE_adminUserName1->text();
    ViewTransactionHistoryRequestValidate validator(accountNumber);

    if (!validator.validate())
    {
        // Handle validation failure
        QMessageBox::warning(this, "Validation Error", "Please enter Your Account Number.");
        return;
    }

    // Create the request object
    ViewTransactionHistoryRequest viewTransactionHistoryRequest(accountNumber, username);
    QJsonObject requestData = viewTransactionHistoryRequest.toJson();

    // Define encryption and signature keys
    // Define encryption and signature keys (ensure these are securely managed)
    const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
    const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity


    if (isAdmin())
    {
        if (username.isEmpty())
        {
            QMessageBox::warning(this, "Input Error", "Please enter your username.");
            return;
        }
        if (username != currentUser)
        {
            QMessageBox::warning(this, "Input Error", "Please Make Sure Enter Your username..!");
            return;
        }
        // Add admin's username to the request
        requestData["AdminUsername"] = currentUser;
    }
    else
    {
        if(accountNumber != currentAccountNumber)
        {
            QMessageBox::warning(this, "Validation Error", "Please enter Your Account Number.");
            return;
        }
    }

    // Encrypt the JSON request data using the encryption key
    QByteArray encryptedData = Encryption::encrypt(requestData, encryptionKey);

    // Generate a signature for the encrypted data using the signature key
    QByteArray signature = Signature::sign(encryptedData, signatureKey);

    // Combine the encrypted data with the signature
    QByteArray finalData = encryptedData + signature;

    // Send the final encrypted and signed data to the server
    client.sendData(finalData);

     ui->LE_transactionAccountNumber->clear();
    ui->LE_adminUserName1->clear();
}

void MainWindow::viewAccountDetails()
{
    QString accountNumber = ui->LE_accountNumberViewD->text(); // Assuming input for account number
    QString username = ui->LE_adminUserName->text(); // Input for admin's own username

    ViewAccountDetailsRequestValidate validator(accountNumber);
    if (!validator.validate())
    {
        // Handle validation failure
        QMessageBox::warning(this, "Validation Error", "Please enter Your Account Number.");
        return;
    }

    QJsonObject requestData = ViewAccountDetailsRequest(accountNumber).toJson();

    // Define encryption and signature keys
    // Define encryption and signature keys (ensure these are securely managed)
    const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
    const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity


    if (isAdmin())
    {
        // Admin needs to enter their own username to view account details
        if (username.isEmpty())
        {
            QMessageBox::warning(this, "Input Error", "Please enter your username.");
            return;
        }
        if (username != currentUser)
        {
            QMessageBox::warning(this, "Input Error", "Please Make Sure Enter Your username..!");
            return;
        }
        requestData["AdminUsername"] = currentUser; // Admin's current username
    }
    else
    {
        // Non-admin user can only view their own account details
        requestData["UserName"] = currentUser; // Fetch details for current logged-in user
    }

    // Encrypt the JSON request data using the encryption key
    QByteArray encryptedData = Encryption::encrypt(requestData, encryptionKey);

    // Generate a signature for the encrypted data using the signature key
    QByteArray signature = Signature::sign(encryptedData, signatureKey);

    // Combine the encrypted data with the signature
    QByteArray finalData = encryptedData + signature;

    // Send the final encrypted and signed data to the server
    client.sendData(finalData);

    ui->LE_accountNumberViewD->clear(); // Assuming input for account number
    ui->LE_adminUserName->clear(); // Input for admin's own username
}

void MainWindow::viewBankDatabase()
{
    if (isAdmin())
    {
        // Create the request object
        ViewBankDatabaseRequest viewBankDatabaseRequest("Admin");

        // Convert the request to JSON
        QJsonObject requestJson = viewBankDatabaseRequest.toJson();

        // Define encryption and signature keys
        // Define encryption and signature keys (ensure these are securely managed)
        const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
        const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity


        // Encrypt the JSON request data using the encryption key
        QByteArray encryptedData = Encryption::encrypt(requestJson, encryptionKey);

        // Generate a signature for the encrypted data using the signature key
        QByteArray signature = Signature::sign(encryptedData, signatureKey);

        // Combine the encrypted data with the signature
        QByteArray finalData = encryptedData + signature;

        // Send the final encrypted and signed data to the server
        client.sendData(finalData);
    }
    else
    {
        QMessageBox::warning(this, "Access Denied", "Only Administrators can view the bank database.");
    }

    ui->LE_accountNumberViewD->clear(); // Assuming input for account number
    ui->LE_adminUserName->clear(); // Input for admin's own username
}

void MainWindow::makeTransaction()
{
    QString amount = ui->LE_transactionAmount_8->text();
    QString accountNumber = ui->LE_accountNumber2_8->text();
    QString action = ui->CB_transactionType_8->currentText();
    QString currentAccountnum = currentAccountNumber; // Assuming you have this variable in your class
    if (accountNumber != currentAccountNumber)
    {
        QMessageBox::warning(this, "Error", "Please Enter Your Account Number..!");
        return;
    }
    // Create the request object
    MakeTransactionRequest makeTransactionRequest(action, accountNumber, currentUser, amount);

    // Validate the request
    MakeTransactionRequestValidate validator(accountNumber, amount, action, currentAccountnum);
    if (!validator.validate())
    {
        QMessageBox::warning(this, "Validation Error", "Please Enter valid transaction details.");
        return;
    }

    // Convert the request to JSON
    QJsonObject requestJson = makeTransactionRequest.toJson();

    // Define encryption and signature keys
    // Define encryption and signature keys (ensure these are securely managed)
    const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
    const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity


    // Encrypt the JSON request data using the encryption key
    QByteArray encryptedData = Encryption::encrypt(requestJson, encryptionKey);

    // Generate a signature for the encrypted data using the signature key
    QByteArray signature = Signature::sign(encryptedData, signatureKey);

    // Combine the encrypted data with the signature
    QByteArray finalData = encryptedData + signature;

    // Send the final encrypted and signed data to the server
    client.sendData(finalData);
    // logTransaction(action, accountNumber, amount);


    ui->LE_transactionAmount_8->clear();
    ui->LE_accountNumber2_8->clear();
    ui->CB_transactionType_8->currentText().clear();
}

void MainWindow::transferAmount()
{
    QString fromAccountNumber = ui->LE_fromAccount_8->text();
    QString toAccountNumber = ui->LE_toAccount_8->text();
    QString amount = ui->LE_transferAmount_8->text();
    if (fromAccountNumber != currentAccountNumber)
    {
        QMessageBox::warning(this, "Error", "Please Enter Your Account Number In first Field.");
        return;
    }
    // Create the request object
    TransferAmountRequest transferAmountRequest(fromAccountNumber, toAccountNumber, amount);

    // Validate the request
    TransferAmountRequestValidate validator(fromAccountNumber, toAccountNumber, amount);
    if (!validator.validate())
    {
        qDebug() << "Transfer amount validation failed";
        QMessageBox::warning(this, "Validation Error", "Please enter valid transfer details.");
        return;
    }

    // Convert the request to JSON
    QJsonObject requestJson = transferAmountRequest.toJson();

    // Define encryption and signature keys
    // Define encryption and signature keys (ensure these are securely managed)
    const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
    const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity

    // Encrypt the JSON request data using the encryption key
    QByteArray encryptedData = Encryption::encrypt(requestJson, encryptionKey);

    // Generate a signature for the encrypted data using the signature key
    QByteArray signature = Signature::sign(encryptedData, signatureKey);

    // Combine the encrypted data with the signature
    QByteArray finalData = encryptedData + signature;

    // Send the final encrypted and signed data to the server
    client.sendData(finalData);
    ui->LE_fromAccount_8->clear();
    ui->LE_toAccount_8->clear();
    ui->LE_transferAmount_8->clear();

    logTransfer(fromAccountNumber, toAccountNumber, amount);
}

void MainWindow::logTransfer(const QString &fromAccountNumber, const QString &toAccountNumber, const QString &amount)
{
    // Log a transfer
    QString timestamp = QDateTime::currentDateTime().toString();
    QString logMessage = QString("\nTransfer from: %1\nTo: %2\nAmount: %3\nDate: [%4]\n")
                             .arg(fromAccountNumber)
                             .arg(toAccountNumber)
                             .arg(amount)
                             .arg(timestamp);
    ui->Lw_User_3->addItem(logMessage);
}

void MainWindow::getAccountNumberAdmin()
{
    QString username = ui->LE_usernameAccNum->text();

    if (isAdmin())
    {
        // Create the request object
        GetAccountNumberAdminRequest getAccountNumberAdminRequest(username);

        // Convert the request to JSON
        QJsonObject requestJson = getAccountNumberAdminRequest.toJson();

        // Define encryption and signature keys
        // Define encryption and signature keys (ensure these are securely managed)
        const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
        const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity


        // Encrypt the JSON request data using the encryption key
        QByteArray encryptedData = Encryption::encrypt(requestJson, encryptionKey);

        // Generate a signature for the encrypted data using the signature key
        QByteArray signature = Signature::sign(encryptedData, signatureKey);

        // Combine the encrypted data with the signature
        QByteArray finalData = encryptedData + signature;

        // Send the final encrypted and signed data to the server
        client.sendData(finalData);
        ui->LE_usernameAccNum->clear();

    }
    else
    {
        QMessageBox::warning(this, "Access Denied", "Only Administrators can view the bank database.");
    }
}

void MainWindow::getAccountNumberUser()
{
    QString username = ui->LE_usernameForAccountNumber_8->text();

    QString currentUserName = currentUser;

    // Create the request object
    GetAccountNumberUserRequest getAccountNumberUserRequest(username);

    // Validate the request
    GetAccountNumberRequestValidate validator(username, currentUserName);
    if (!validator.validate())
    {
        QMessageBox::warning(this, "Validation Error", "Please enter Your username.");
        return;
    }

    // Convert the request to JSON
    QJsonObject requestJson = getAccountNumberUserRequest.toJson();

    // Define encryption and signature keys
    // Define encryption and signature keys (ensure these are securely managed)
    const QString encryptionKey = "SecretEncryptionKey"; // Encryption key for securing data
    const QString signatureKey = "SecretSignatureKey";   // Signature key for data integrity

    // Encrypt the JSON request data using the encryption key
    QByteArray encryptedData = Encryption::encrypt(requestJson, encryptionKey);

    // Generate a signature for the encrypted data using the signature key
    QByteArray signature = Signature::sign(encryptedData, signatureKey);

    // Combine the encrypted data with the signature
    QByteArray finalData = encryptedData + signature;

    // Send the final encrypted and signed data to the server
    client.sendData(finalData);
    ui->LE_usernameForAccountNumber_8->clear();

}


/************************ Functions to display a general response from the serve ***********************************/

// Handle login result and set current user and type
void MainWindow::displayLoginResult(const QJsonObject &response)
{
    currentAccountNumber = response["AccountNumber"].toString(); // Set the current account number

    // Handle login result and set current user and type
    QString status = response["Status"].toString();// Get the result from the response
    if (status == "Success")
    {
        currentUser = response["UserName"].toString();// Set the current user
        Authentication = response["Authentication"].toString();// Set the authentication status
        currentAccountNumber = response["AccountNumber"].toString(); // Set the current account number
        QString welcomeMessage = "Login Successful Welcome, " + currentUser;

        if (isAdmin())
        {
            ui->LW_admin->addItem(welcomeMessage);

            ui->tabWidget->setCurrentIndex(6); // Admin tab index
        }
        else
        {
            ui->Lw_User_3->addItem(welcomeMessage);
            ui->tabWidget->setCurrentIndex(3); // User tab index
        }
    }
    else
    {
        QString errorMessage = "Login failed: " ;
        QMessageBox::warning(this, errorMessage, response["Message"].toString());
    }

}
// Function to display  user account number

void MainWindow::displayUserAccountNumber(const QJsonObject &response)
{
    // Handle login result and set current user and type
    QString status = response["Status"].toString();// Get the result from the response
    if (status == "Success")
    {
        QString accountNumber = response["AccountNumber"].toString(); // Get the account number from the response
        ui->Lw_User_3->addItem("User Account Number: " + accountNumber); // Display the account number
    }
    else
    {
        QString errorMessage = " Failed Operation: " ;
        QMessageBox::warning(this, errorMessage, response["Message"].toString());
    }
}

void MainWindow::displayAdminAccountNumber(const QJsonObject &response)
{

    QString status = response["Status"].toString();// Get the result from the response
    if (status == "Success")
    {
        QString accountNumber = response["AccountNumber"].toString(); // Get the account number from the response
        ui->LW_admin->addItem("User Account Number: " + accountNumber); // Display the account number
    }
    else
    {
        QString errorMessage = " Failed Operation: " ;
        QMessageBox::warning(this, errorMessage, response["Message"].toString());
    }
}

void MainWindow::displayBalance(const QJsonObject &response)
{
    QString status = response["Status"].toString(); // Get the result from the response

    if (status == "Success")
    {
        // Check if the response contains the "Balance" key
        if (response.contains("Balance"))
        {
            // Get the balance as a QString
            QString balance = response["Balance"].toString();
            // Display the balance
            ui->Lw_User_3->addItem("Your Balance: " + balance);
        }
        else
        {
            // Handle the case where the "Balance" key is missing
            ui->Lw_User_3->addItem("Error: Balance information is not available.");
        }
    }
    else if (status == "Failure")
    {
        // Handle errors by showing a message box with the error message
        QString errorMessage = "Operation Failed";
        QString detailedMessage = response["Message"].toString();
        if (detailedMessage.isEmpty())
        {
            detailedMessage = "An unknown error occurred.";
        }
        QMessageBox::warning(this, errorMessage, detailedMessage);
    }
}

void MainWindow::displayTransactionHistory(const QJsonObject &response)
{

    // Check if the response status is successful
    QString status = response["Status"].toString();
    qDebug() << "Response Status:" << status;

    if (status == "Success")
    {
        // Retrieve the transactions array from the response
        QJsonArray transactions = response["TransactionHistory"].toArray(); // Corrected field name

        // Clear any existing items in the list widget
        ui->Lw_Transactions->clear();

        // Iterate through each transaction in the array
        for (const QJsonValue &value : transactions)
        {
            // Convert each value to a QJsonObject representing a transaction
            QJsonObject transaction = value.toObject();
            // Format the transaction details into a QString with new lines
            QString item = QString("Action: %1\nAmount: %2\nTimestamp: %3\n")
                               .arg(transaction["TransactionType"].toString())  // Get the action of the transaction (e.g., Deposit, Withdrawal)
                               .arg(transaction["Amount"].toDouble())  // Get the amount of the transaction
                               .arg(transaction["Timestamp"].toString());  // Get the timestamp of the transaction

            // Add the formatted transaction details to the UI list widget
            ui->Lw_Transactions->addItem(item);

        }
    }
    else
    {
        // Handle error or failure response
        QString errorMessage = "Failed: ";
        QMessageBox::warning(this, errorMessage, response["Message"].toString());
    }

}

void MainWindow::displayAccountDetails(const QJsonObject &response)
{

    // Check if the response status is successful
    QString status = response["Status"].toString();
    qDebug() << "Response Status:" << status;

    if (status == "Success")
    {
        // Extract the account details object from the JSON response
        QJsonObject accountDetails = response["AccountDetails"].toObject(); // Get the account details object from the response

        // Clear any existing items in the list widget
        ui->Lw_AccountDetails->clear();

        QString item = QString("Account Number : %1\n"
                               "Full Name : %2\n"
                               "User Name : %3\n"
                               "Password : %4\n"
                               "Balance : %5\n"
                               "Phone Number: %6\n"
                               "Email : %7")
                           .arg(accountDetails["AccountNumber"].toString()) // Get the account number
                           .arg(accountDetails["FullName"].toString()) // Get the full name
                           .arg(accountDetails["UserName"].toString()) // Get the User Name
                           .arg(accountDetails["Password"].toString()) // Get the password
                           .arg(accountDetails["Balance"].toString()) // Get the balance
                           .arg(accountDetails["PhoneNumber"].toString()) // Get the phone number
                           .arg(accountDetails["Email"].toString()); // Get the email
        ui->Lw_AccountDetails->addItem(item); // Display the account details
    }
    else
    {
        // Handle error or failure response
        QString errorMessage = "Failed: ";
        QMessageBox::warning(this, errorMessage, response["Message"].toString());
    }


}

void MainWindow::displayBankDatabase(const QJsonObject &response)
{
    QJsonArray accounts = response["Accounts"].toArray(); // Get the accounts array from the response

    // Clear the list widget before adding new items
    ui->LW_BankDP->clear();

    for (const QJsonValue &value : accounts)
    {
        QJsonObject account = value.toObject(); // Get each account object
        QString item = QString("Account Number: %1\n"
                               "Full Name: %2\n"
                               "User Name: %3\n"
                               "Password: %4\n"
                               "Balance: %5\n"
                               "Phone Number: %6\n"
                               "Email: %7\n"
                               "---------------------------------------")
                           .arg(account["AccountNumber"].toString()) // Get the account number
                           .arg(account["FullName"].toString()) // Get the full name
                           .arg(account["UserName"].toString()) // Get the User Name
                           .arg(account["Password"].toString()) // Get the password
                           .arg(account["Balance"].toString()) // Get the balance
                           .arg(account["PhoneNumber"].toString()) // Get the phone number
                           .arg(account["Email"].toString()); // Get the email

        ui->LW_BankDP->addItem(item); // Display the account
    }

}

// Function to display Admin operation result
void MainWindow::displayAdminOperationResult(const QJsonObject &response)
{
    QString status = response["Status"].toString(); // Get the result from the response
    if (status == "Success")
    {
        ui->LW_admin->addItem("Operation Successful: " + response["Message"].toString()); // Display a success message
    }
    else
    {
        QString errorMessage = "Failure : " ;
        QMessageBox::warning(this, errorMessage, response["Message"].toString());
    }
}

// Function to display user operation result
void MainWindow::displayUserOperationResult(const QJsonObject &response)
{
    QString result = response["Status"].toString(); // Get the result from the response
    if (result == "Success")
    {
        // ui->Lw_User->addItem("Operation Successful: " + response["Message"].toString()); // Display a success message
        ui->Lw_User_3->addItem(response["Message"].toString()); // Display a success message

    }
    else
    {
        //ui->Lw_User->addItem("Operation Failed: " + response["Message"].toString()); // Display a failure message
        ui->Lw_User_3->addItem(response["Message"].toString()); // Display a failure message

    }
}

// Check if current user is admin
bool MainWindow::isAdmin() const
{
    // Example implementation: Check if current user is admin
    return Authentication == "Admin";
}

/*********************************** ceate new user comboBox **************************************/
//comboBox for user operation
void MainWindow::on_comboBox_11_activated(int index)
{
    switch (index)
    {
    case 0:
        ui->LE_usernameForAccountNumber_8->setEnabled(false);
        ui->LE_accountNumber_8->setEnabled(false);
        ui->LE_toAccount_8->setEnabled(false);
        ui->LE_fromAccount_8->setEnabled(false);
        ui->LE_transferAmount_8->setEnabled(false);
        break;
    case 1:
        ui->LE_usernameForAccountNumber_8->setEnabled(true);
        ui->LE_accountNumber_8->setEnabled(false);

        ui->LE_toAccount_8->setEnabled(false);
        ui->LE_fromAccount_8->setEnabled(false);
        ui->LE_transferAmount_8->setEnabled(false);
        break;
    case 2:
        ui->LE_usernameForAccountNumber_8->setEnabled(false);
        ui->LE_accountNumber_8->setEnabled(true);
        ui->LE_toAccount_8->setEnabled(false);
        ui->LE_fromAccount_8->setEnabled(false);
        ui->LE_transferAmount_8->setEnabled(false);

        break;
    case 3:
        ui->LE_usernameForAccountNumber_8->setEnabled(false);
        ui->LE_accountNumber_8->setEnabled(false);
        ui->LE_toAccount_8->setEnabled(true);
        ui->LE_fromAccount_8->setEnabled(true);
        ui->LE_transferAmount_8->setEnabled(true);
        break;
    }
}
//comboBox for Admin operation
void MainWindow::on_comboBox_2_activated(int index)
{
    switch (index)
    {
    case 0:
        ui->LE_newPassword->setEnabled(false);
        ui->LE_newFullName->setEnabled(false);
        ui->LE_newUsername->setEnabled(false);
        ui->LE_userAge->setEnabled(false);
        ui->LE_initialBalance->setEnabled(false);
        ui->LE_userEmail->setEnabled(false);
        ui->LE_phoneNumber->setEnabled(false);
        break;
    case 1:
        ui->LE_newFullName->setEnabled(true);
        ui->LE_newUsername->setEnabled(true);
        ui->LE_newPassword->setEnabled(true);
        ui->LE_userAge->setEnabled(false);
        ui->LE_initialBalance->setEnabled(false);
        ui->LE_userEmail->setEnabled(false);
        ui->LE_phoneNumber->setEnabled(false);

        break;
    case 2:
        ui->LE_newFullName->setEnabled(true);
        ui->LE_newUsername->setEnabled(true);
        ui->LE_newPassword->setEnabled(true);
        ui->LE_userAge->setEnabled(true);
        ui->LE_initialBalance->setEnabled(true);
        ui->LE_userEmail->setEnabled(true);
        ui->LE_phoneNumber->setEnabled(true);
        break;

    }

}
//comboBox for view acc Details
void MainWindow::on_comboBox_3_activated(int index)
{
    switch (index)
    {
    case 0:
        ui->LE_accountNumberViewD->setEnabled(false);
        ui->LE_adminUserName->setEnabled(false);

        break;
    case 1:

        ui->LE_accountNumberViewD->setEnabled(true);
        ui->LE_adminUserName->setEnabled(true);

        break;
    case 2:
        ui->LE_accountNumberViewD->setEnabled(true);
        ui->LE_adminUserName->setEnabled(false);

        break;
    }
}

//comboBox for view transaction history
void MainWindow::on_comboBox_4_activated(int index)
{
    switch (index)
    {
    case 0:
        ui->LE_transactionAccountNumber->setEnabled(false);
        ui->LE_adminUserName1->setEnabled(false);

        break;
    case 1:

        ui->LE_transactionAccountNumber->setEnabled(true);
        ui->LE_adminUserName1->setEnabled(true);

        break;
    case 2:
        ui->LE_transactionAccountNumber->setEnabled(true);
        ui->LE_adminUserName1->setEnabled(false);

        break;
    }
}

/***************************PB For Switching Between Tabs*****************************/
//Go To Tab which have list Widget ViweAccountDetails by User
void MainWindow::on_PB_ViweAccountDetails_clicked()
{
    ui->tabWidget->setCurrentIndex(4);

}
//Go To Tab which have list Widget TransactionHistory by user
void MainWindow::on_PB_TransactionHistory_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}

//Go To Tab which have list Widget TransactionHistory by Admin
void MainWindow::on_PB_TransactionHistoryAdmin_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}
//Go To Tab which have list Widget ViweAccountDetails by Admin
void MainWindow::on_PB_ViweAccountDetailsAdmin_clicked()
{
    ui->tabWidget->setCurrentIndex(4);

}
//Go To Tab which have list Widget viewBankDatabase by Admin
void MainWindow::on_PB_viewBankDatabase_clicked()
{
    ui->tabWidget->setCurrentIndex(7);

}

/***************************PB Clear List Widget *****************************/
//clear Connection list Widget
void MainWindow::on_PB_Clear_clicked()
{
    ui->Lw_Connection->clear();
}

//clear User list Widget
void MainWindow::on_PB_ClearUserLw_clicked()
{
    ui->Lw_User_3->clear();
}

//clear Transactions list Widget
void MainWindow::on_PB_ClearLwTrans_clicked()
{
    ui->Lw_Transactions->clear();

}

//clear Bank Database list Widget
void MainWindow::on_PB_ClearBankDp_clicked()
{
    ui->LW_BankDP->clear();
}

//clear Acc Details lise widget
void MainWindow::on_PB_ClearLwAccDetails_clicked()
{
    ui->Lw_AccountDetails->clear();

}
void MainWindow::on_pushButton_clicked()
{
    ui->LW_admin->clear();

}


