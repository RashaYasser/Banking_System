/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTabWidget *tabWidget;
    QWidget *tabWelcom_0;
    QLabel *label;
    QPushButton *Pb_Start;
    QLabel *label_6;
    QWidget *widget;
    QStatusBar *statusbar_4;
    QLabel *label_2;
    QPushButton *PB_Clear;
    QListWidget *Lw_Connection;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QLineEdit *LE_Port;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLineEdit *lE_IP;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PB_Connect;
    QPushButton *PB_Disconnect;
    QWidget *tabLogin_11;
    QLabel *label_3;
    QLineEdit *LE_userName;
    QLineEdit *LE_password;
    QPushButton *PB_Login;
    QWidget *userOperationsTab_7;
    QLabel *label_4;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_44;
    QComboBox *comboBox_11;
    QHBoxLayout *horizontalLayout_36;
    QLineEdit *LE_usernameForAccountNumber_8;
    QPushButton *PB_getAccountNumberUser_8;
    QHBoxLayout *horizontalLayout_37;
    QLineEdit *LE_accountNumber_8;
    QPushButton *PB_viewBalance_8;
    QHBoxLayout *horizontalLayout_38;
    QPushButton *PB_transferAmount_8;
    QLineEdit *LE_fromAccount_8;
    QLineEdit *LE_toAccount_8;
    QLineEdit *LE_transferAmount_8;
    QComboBox *CB_transactionType_8;
    QLineEdit *LE_accountNumber2_8;
    QLineEdit *LE_transactionAmount_8;
    QPushButton *PB_makeTransaction_8;
    QPushButton *PB_ViweAccountDetails;
    QPushButton *PB_TransactionHistory;
    QListWidget *Lw_User_3;
    QPushButton *PB_ClearUserLw;
    QWidget *tabAccountDetails_8;
    QLabel *label_14;
    QListWidget *Lw_AccountDetails;
    QComboBox *comboBox_3;
    QPushButton *PB_viewAccountDetailsFunction;
    QLineEdit *LE_adminUserName;
    QPushButton *PB_ClearLwAccDetails;
    QLineEdit *LE_accountNumberViewD;
    QWidget *tabTransactionHistory_8;
    QLabel *label_15;
    QLineEdit *LE_adminUserName1;
    QComboBox *comboBox_4;
    QLineEdit *LE_transactionAccountNumber;
    QPushButton *PB_viewTransactionHistoryFunction;
    QPushButton *PB_ClearLwTrans;
    QListWidget *Lw_Transactions;
    QWidget *tabAdminPanel_9;
    QLabel *label_16;
    QWidget *layoutWidget_9;
    QVBoxLayout *verticalLayout_5;
    QComboBox *comboBox_2;
    QLineEdit *LE_authentication;
    QLineEdit *LE_newFullName;
    QLineEdit *LE_newUsername;
    QLineEdit *LE_newPassword;
    QLineEdit *LE_userAge;
    QLineEdit *LE_initialBalance;
    QLineEdit *LE_phoneNumber;
    QLineEdit *LE_userEmail;
    QPushButton *PB_createNewUser;
    QWidget *layoutWidget_10;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *LE_updateAccountNumber;
    QLineEdit *LE_updateUsername;
    QLineEdit *LE_updatePassword;
    QLineEdit *LE_updatePhoneNum;
    QLineEdit *LE_updateUserEmail;
    QPushButton *PB_updateUser;
    QListWidget *LW_admin;
    QPushButton *pushButton;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *LE_usernameAccNum;
    QPushButton *PB_getAccountNumberAdmin;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *LE_deleteUserAccountNumber;
    QPushButton *PB_deleteUser;
    QPushButton *PB_viewBankDatabase;
    QPushButton *PB_TransactionHistoryAdmin;
    QPushButton *PB_ViweAccountDetailsAdmin;
    QWidget *tabBankDatabase_4;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *PB_viewBankDatabaseFunction;
    QPushButton *PB_ClearBankDp;
    QListWidget *LW_BankDP;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(751, 521);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, -20, 751, 541));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 49, 71);"));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 20, 761, 541));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 49, 71);"));
        tabWelcom_0 = new QWidget();
        tabWelcom_0->setObjectName("tabWelcom_0");
        label = new QLabel(tabWelcom_0);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 751, 501));
        label->setPixmap(QPixmap(QString::fromUtf8("C:/Users/t/Pictures/Banka.PNG")));
        label->setScaledContents(true);
        Pb_Start = new QPushButton(tabWelcom_0);
        Pb_Start->setObjectName("Pb_Start");
        Pb_Start->setGeometry(QRect(580, 240, 131, 41));
        Pb_Start->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 18pt \"Script MT Bold\";\n"
"background-color: rgb(2, 25, 39);"));
        label_6 = new QLabel(tabWelcom_0);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(620, 450, 111, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Script MT Bold\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 27, 39);"));
        tabWidget->addTab(tabWelcom_0, QString());
        widget = new QWidget();
        widget->setObjectName("widget");
        statusbar_4 = new QStatusBar(widget);
        statusbar_4->setObjectName("statusbar_4");
        statusbar_4->setGeometry(QRect(150, 150, 3, 22));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 801, 501));
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/t/Pictures/Advantages-and-benefits-of-online-banking-Complete-Controller.jpg")));
        label_2->setScaledContents(true);
        PB_Clear = new QPushButton(widget);
        PB_Clear->setObjectName("PB_Clear");
        PB_Clear->setGeometry(QRect(600, 210, 101, 29));
        PB_Clear->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"color: rgb(225, 225, 225);\n"
"background-color: rgb(1, 71, 131);"));
        Lw_Connection = new QListWidget(widget);
        Lw_Connection->setObjectName("Lw_Connection");
        Lw_Connection->setGeometry(QRect(460, 120, 241, 81));
        Lw_Connection->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 71, 131);"));
        Lw_Connection->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        Lw_Connection->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        layoutWidget_2 = new QWidget(widget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(462, 44, 241, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"color: rgb(225, 225, 225);\n"
"background-color: rgb(1, 71, 131);"));

        horizontalLayout_2->addWidget(label_9);

        LE_Port = new QLineEdit(layoutWidget_2);
        LE_Port->setObjectName("LE_Port");
        LE_Port->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 71, 131);"));

        horizontalLayout_2->addWidget(LE_Port);

        layoutWidget_3 = new QWidget(widget);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(463, 13, 241, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_3);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"color: rgb(225, 225, 225);\n"
"background-color: rgb(1, 71, 131);"));

        horizontalLayout->addWidget(label_8);

        lE_IP = new QLineEdit(layoutWidget_3);
        lE_IP->setObjectName("lE_IP");
        lE_IP->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 71, 131);"));

        horizontalLayout->addWidget(lE_IP);

        widget1 = new QWidget(widget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(461, 81, 241, 31));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        PB_Connect = new QPushButton(widget1);
        PB_Connect->setObjectName("PB_Connect");
        PB_Connect->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"background-color: rgb(0, 139, 0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(PB_Connect);

        PB_Disconnect = new QPushButton(widget1);
        PB_Disconnect->setObjectName("PB_Disconnect");
        PB_Disconnect->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";\n"
"background-color: rgb(121, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(PB_Disconnect);

        tabWidget->addTab(widget, QString());
        tabLogin_11 = new QWidget();
        tabLogin_11->setObjectName("tabLogin_11");
        label_3 = new QLabel(tabLogin_11);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 771, 691));
        label_3->setPixmap(QPixmap(QString::fromUtf8("C:/Users/t/Pictures/wp6603070.png")));
        label_3->setScaledContents(true);
        LE_userName = new QLineEdit(tabLogin_11);
        LE_userName->setObjectName("LE_userName");
        LE_userName->setGeometry(QRect(160, 110, 341, 24));
        LE_password = new QLineEdit(tabLogin_11);
        LE_password->setObjectName("LE_password");
        LE_password->setGeometry(QRect(160, 140, 341, 24));
        LE_password->setEchoMode(QLineEdit::Password);
        PB_Login = new QPushButton(tabLogin_11);
        PB_Login->setObjectName("PB_Login");
        PB_Login->setGeometry(QRect(160, 170, 341, 24));
        PB_Login->setStyleSheet(QString::fromUtf8("color: rgb(247, 247, 247);\n"
"font: 700 9pt \"Segoe UI\";"));
        tabWidget->addTab(tabLogin_11, QString());
        userOperationsTab_7 = new QWidget();
        userOperationsTab_7->setObjectName("userOperationsTab_7");
        label_4 = new QLabel(userOperationsTab_7);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 771, 521));
        label_4->setPixmap(QPixmap(QString::fromUtf8("C:/Users/t/Pictures/online-banking.jpg")));
        label_4->setScaledContents(true);
        layoutWidget_4 = new QWidget(userOperationsTab_7);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(10, 28, 311, 391));
        verticalLayout_44 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_44->setObjectName("verticalLayout_44");
        verticalLayout_44->setContentsMargins(0, 0, 0, 0);
        comboBox_11 = new QComboBox(layoutWidget_4);
        comboBox_11->addItem(QString());
        comboBox_11->addItem(QString());
        comboBox_11->addItem(QString());
        comboBox_11->addItem(QString());
        comboBox_11->setObjectName("comboBox_11");
        comboBox_11->setStyleSheet(QString::fromUtf8("color: rgb(207, 207, 207);"));

        verticalLayout_44->addWidget(comboBox_11);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName("horizontalLayout_36");
        LE_usernameForAccountNumber_8 = new QLineEdit(layoutWidget_4);
        LE_usernameForAccountNumber_8->setObjectName("LE_usernameForAccountNumber_8");
        LE_usernameForAccountNumber_8->setStyleSheet(QString::fromUtf8("color: rgb(232, 232, 232);"));

        horizontalLayout_36->addWidget(LE_usernameForAccountNumber_8);

        PB_getAccountNumberUser_8 = new QPushButton(layoutWidget_4);
        PB_getAccountNumberUser_8->setObjectName("PB_getAccountNumberUser_8");
        PB_getAccountNumberUser_8->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"color: rgb(220, 220, 220);\n"
""));

        horizontalLayout_36->addWidget(PB_getAccountNumberUser_8);


        verticalLayout_44->addLayout(horizontalLayout_36);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName("horizontalLayout_37");
        LE_accountNumber_8 = new QLineEdit(layoutWidget_4);
        LE_accountNumber_8->setObjectName("LE_accountNumber_8");
        LE_accountNumber_8->setStyleSheet(QString::fromUtf8("color: rgb(232, 232, 232);"));

        horizontalLayout_37->addWidget(LE_accountNumber_8);

        PB_viewBalance_8 = new QPushButton(layoutWidget_4);
        PB_viewBalance_8->setObjectName("PB_viewBalance_8");
        PB_viewBalance_8->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"color: rgb(220, 220, 220);"));

        horizontalLayout_37->addWidget(PB_viewBalance_8);


        verticalLayout_44->addLayout(horizontalLayout_37);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setObjectName("horizontalLayout_38");
        PB_transferAmount_8 = new QPushButton(layoutWidget_4);
        PB_transferAmount_8->setObjectName("PB_transferAmount_8");
        PB_transferAmount_8->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"color: rgb(220, 220, 220);"));

        horizontalLayout_38->addWidget(PB_transferAmount_8);

        LE_fromAccount_8 = new QLineEdit(layoutWidget_4);
        LE_fromAccount_8->setObjectName("LE_fromAccount_8");
        LE_fromAccount_8->setStyleSheet(QString::fromUtf8("color: rgb(232, 232, 232);"));

        horizontalLayout_38->addWidget(LE_fromAccount_8);


        verticalLayout_44->addLayout(horizontalLayout_38);

        LE_toAccount_8 = new QLineEdit(layoutWidget_4);
        LE_toAccount_8->setObjectName("LE_toAccount_8");
        LE_toAccount_8->setStyleSheet(QString::fromUtf8("color: rgb(232, 232, 232);"));

        verticalLayout_44->addWidget(LE_toAccount_8);

        LE_transferAmount_8 = new QLineEdit(layoutWidget_4);
        LE_transferAmount_8->setObjectName("LE_transferAmount_8");
        LE_transferAmount_8->setStyleSheet(QString::fromUtf8("color: rgb(232, 232, 232);"));

        verticalLayout_44->addWidget(LE_transferAmount_8);

        CB_transactionType_8 = new QComboBox(layoutWidget_4);
        CB_transactionType_8->addItem(QString());
        CB_transactionType_8->addItem(QString());
        CB_transactionType_8->addItem(QString());
        CB_transactionType_8->setObjectName("CB_transactionType_8");
        CB_transactionType_8->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"color: rgb(220, 220, 220);"));

        verticalLayout_44->addWidget(CB_transactionType_8);

        LE_accountNumber2_8 = new QLineEdit(layoutWidget_4);
        LE_accountNumber2_8->setObjectName("LE_accountNumber2_8");
        LE_accountNumber2_8->setStyleSheet(QString::fromUtf8("color: rgb(232, 232, 232);"));

        verticalLayout_44->addWidget(LE_accountNumber2_8);

        LE_transactionAmount_8 = new QLineEdit(layoutWidget_4);
        LE_transactionAmount_8->setObjectName("LE_transactionAmount_8");
        LE_transactionAmount_8->setStyleSheet(QString::fromUtf8("color: rgb(232, 232, 232);"));

        verticalLayout_44->addWidget(LE_transactionAmount_8);

        PB_makeTransaction_8 = new QPushButton(layoutWidget_4);
        PB_makeTransaction_8->setObjectName("PB_makeTransaction_8");
        PB_makeTransaction_8->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"color: rgb(220, 220, 220);"));

        verticalLayout_44->addWidget(PB_makeTransaction_8);

        PB_ViweAccountDetails = new QPushButton(layoutWidget_4);
        PB_ViweAccountDetails->setObjectName("PB_ViweAccountDetails");
        PB_ViweAccountDetails->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"color: rgb(220, 220, 220);"));

        verticalLayout_44->addWidget(PB_ViweAccountDetails);

        PB_TransactionHistory = new QPushButton(layoutWidget_4);
        PB_TransactionHistory->setObjectName("PB_TransactionHistory");
        PB_TransactionHistory->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"color: rgb(220, 220, 220);"));

        verticalLayout_44->addWidget(PB_TransactionHistory);

        Lw_User_3 = new QListWidget(userOperationsTab_7);
        Lw_User_3->setObjectName("Lw_User_3");
        Lw_User_3->setGeometry(QRect(420, 20, 291, 111));
        Lw_User_3->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 71, 91);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 9pt \"Segoe UI\";"));
        Lw_User_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        PB_ClearUserLw = new QPushButton(userOperationsTab_7);
        PB_ClearUserLw->setObjectName("PB_ClearUserLw");
        PB_ClearUserLw->setGeometry(QRect(630, 140, 80, 21));
        PB_ClearUserLw->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"background-color: rgb(23, 72, 93);\n"
"color: rgb(235, 235, 235);"));
        tabWidget->addTab(userOperationsTab_7, QString());
        tabAccountDetails_8 = new QWidget();
        tabAccountDetails_8->setObjectName("tabAccountDetails_8");
        label_14 = new QLabel(tabAccountDetails_8);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(0, 0, 751, 531));
        label_14->setPixmap(QPixmap(QString::fromUtf8("C:/Users/t/Pictures/ten-reasons-internet-banking-opt.jpg")));
        label_14->setScaledContents(true);
        Lw_AccountDetails = new QListWidget(tabAccountDetails_8);
        Lw_AccountDetails->setObjectName("Lw_AccountDetails");
        Lw_AccountDetails->setGeometry(QRect(121, 22, 451, 211));
        Lw_AccountDetails->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 17, 33);\n"
"background-color: rgb(10, 40, 64);\n"
"font: 700 9pt \"Segoe UI\";\n"
"color: rgb(241, 241, 241);"));
        Lw_AccountDetails->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        comboBox_3 = new QComboBox(tabAccountDetails_8);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(121, 239, 451, 24));
        comboBox_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"color: rgb(220, 220, 220);\n"
""));
        PB_viewAccountDetailsFunction = new QPushButton(tabAccountDetails_8);
        PB_viewAccountDetailsFunction->setObjectName("PB_viewAccountDetailsFunction");
        PB_viewAccountDetailsFunction->setGeometry(QRect(122, 330, 451, 24));
        PB_viewAccountDetailsFunction->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"color: rgb(220, 220, 220);\n"
""));
        LE_adminUserName = new QLineEdit(tabAccountDetails_8);
        LE_adminUserName->setObjectName("LE_adminUserName");
        LE_adminUserName->setGeometry(QRect(122, 270, 451, 24));
        PB_ClearLwAccDetails = new QPushButton(tabAccountDetails_8);
        PB_ClearLwAccDetails->setObjectName("PB_ClearLwAccDetails");
        PB_ClearLwAccDetails->setGeometry(QRect(122, 360, 451, 24));
        PB_ClearLwAccDetails->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"color: rgb(220, 220, 220);\n"
""));
        LE_accountNumberViewD = new QLineEdit(tabAccountDetails_8);
        LE_accountNumberViewD->setObjectName("LE_accountNumberViewD");
        LE_accountNumberViewD->setGeometry(QRect(122, 300, 451, 24));
        tabWidget->addTab(tabAccountDetails_8, QString());
        tabTransactionHistory_8 = new QWidget();
        tabTransactionHistory_8->setObjectName("tabTransactionHistory_8");
        label_15 = new QLabel(tabTransactionHistory_8);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(-160, -10, 931, 511));
        label_15->setPixmap(QPixmap(QString::fromUtf8("C:/Users/t/Pictures/digital-banking-740x445.jpg")));
        label_15->setScaledContents(true);
        LE_adminUserName1 = new QLineEdit(tabTransactionHistory_8);
        LE_adminUserName1->setObjectName("LE_adminUserName1");
        LE_adminUserName1->setGeometry(QRect(111, 249, 481, 24));
        LE_adminUserName1->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 28, 60);\n"
"color: rgb(245, 245, 245);\n"
""));
        comboBox_4 = new QComboBox(tabTransactionHistory_8);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(111, 219, 481, 24));
        comboBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 28, 60);\n"
"color: rgb(245, 245, 245);\n"
""));
        LE_transactionAccountNumber = new QLineEdit(tabTransactionHistory_8);
        LE_transactionAccountNumber->setObjectName("LE_transactionAccountNumber");
        LE_transactionAccountNumber->setGeometry(QRect(111, 279, 481, 24));
        LE_transactionAccountNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 28, 60);\n"
"color: rgb(245, 245, 245);\n"
""));
        PB_viewTransactionHistoryFunction = new QPushButton(tabTransactionHistory_8);
        PB_viewTransactionHistoryFunction->setObjectName("PB_viewTransactionHistoryFunction");
        PB_viewTransactionHistoryFunction->setGeometry(QRect(111, 309, 481, 24));
        PB_viewTransactionHistoryFunction->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 28, 60);\n"
"color: rgb(245, 245, 245);\n"
""));
        PB_ClearLwTrans = new QPushButton(tabTransactionHistory_8);
        PB_ClearLwTrans->setObjectName("PB_ClearLwTrans");
        PB_ClearLwTrans->setGeometry(QRect(111, 339, 481, 24));
        PB_ClearLwTrans->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 28, 60);\n"
"color: rgb(245, 245, 245);\n"
""));
        Lw_Transactions = new QListWidget(tabTransactionHistory_8);
        Lw_Transactions->setObjectName("Lw_Transactions");
        Lw_Transactions->setGeometry(QRect(111, 21, 481, 192));
        Lw_Transactions->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Segoe UI\";\n"
"color: rgb(241, 241, 241);\n"
"background-color: rgb(20, 26, 58);"));
        Lw_Transactions->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tabWidget->addTab(tabTransactionHistory_8, QString());
        tabAdminPanel_9 = new QWidget();
        tabAdminPanel_9->setObjectName("tabAdminPanel_9");
        label_16 = new QLabel(tabAdminPanel_9);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(0, -10, 791, 501));
        label_16->setPixmap(QPixmap(QString::fromUtf8("C:/Users/t/Pictures/online-banking.jpg")));
        label_16->setScaledContents(true);
        layoutWidget_9 = new QWidget(tabAdminPanel_9);
        layoutWidget_9->setObjectName("layoutWidget_9");
        layoutWidget_9->setGeometry(QRect(10, 10, 311, 297));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_9);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBox_2 = new QComboBox(layoutWidget_9);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Segoe UI\";\n"
"color: rgb(221, 221, 221);"));

        verticalLayout_5->addWidget(comboBox_2);

        LE_authentication = new QLineEdit(layoutWidget_9);
        LE_authentication->setObjectName("LE_authentication");

        verticalLayout_5->addWidget(LE_authentication);

        LE_newFullName = new QLineEdit(layoutWidget_9);
        LE_newFullName->setObjectName("LE_newFullName");

        verticalLayout_5->addWidget(LE_newFullName);

        LE_newUsername = new QLineEdit(layoutWidget_9);
        LE_newUsername->setObjectName("LE_newUsername");
        LE_newUsername->setStyleSheet(QString::fromUtf8("color: rgb(190, 190, 190);"));

        verticalLayout_5->addWidget(LE_newUsername);

        LE_newPassword = new QLineEdit(layoutWidget_9);
        LE_newPassword->setObjectName("LE_newPassword");
        LE_newPassword->setEchoMode(QLineEdit::Password);

        verticalLayout_5->addWidget(LE_newPassword);

        LE_userAge = new QLineEdit(layoutWidget_9);
        LE_userAge->setObjectName("LE_userAge");

        verticalLayout_5->addWidget(LE_userAge);

        LE_initialBalance = new QLineEdit(layoutWidget_9);
        LE_initialBalance->setObjectName("LE_initialBalance");

        verticalLayout_5->addWidget(LE_initialBalance);

        LE_phoneNumber = new QLineEdit(layoutWidget_9);
        LE_phoneNumber->setObjectName("LE_phoneNumber");

        verticalLayout_5->addWidget(LE_phoneNumber);

        LE_userEmail = new QLineEdit(layoutWidget_9);
        LE_userEmail->setObjectName("LE_userEmail");

        verticalLayout_5->addWidget(LE_userEmail);

        PB_createNewUser = new QPushButton(layoutWidget_9);
        PB_createNewUser->setObjectName("PB_createNewUser");
        PB_createNewUser->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Segoe UI\";\n"
"color: rgb(221, 221, 221);"));

        verticalLayout_5->addWidget(PB_createNewUser);

        layoutWidget_10 = new QWidget(tabAdminPanel_9);
        layoutWidget_10->setObjectName("layoutWidget_10");
        layoutWidget_10->setGeometry(QRect(10, 310, 311, 176));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_10);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        LE_updateAccountNumber = new QLineEdit(layoutWidget_10);
        LE_updateAccountNumber->setObjectName("LE_updateAccountNumber");

        verticalLayout_6->addWidget(LE_updateAccountNumber);

        LE_updateUsername = new QLineEdit(layoutWidget_10);
        LE_updateUsername->setObjectName("LE_updateUsername");

        verticalLayout_6->addWidget(LE_updateUsername);

        LE_updatePassword = new QLineEdit(layoutWidget_10);
        LE_updatePassword->setObjectName("LE_updatePassword");

        verticalLayout_6->addWidget(LE_updatePassword);

        LE_updatePhoneNum = new QLineEdit(layoutWidget_10);
        LE_updatePhoneNum->setObjectName("LE_updatePhoneNum");

        verticalLayout_6->addWidget(LE_updatePhoneNum);

        LE_updateUserEmail = new QLineEdit(layoutWidget_10);
        LE_updateUserEmail->setObjectName("LE_updateUserEmail");

        verticalLayout_6->addWidget(LE_updateUserEmail);

        PB_updateUser = new QPushButton(layoutWidget_10);
        PB_updateUser->setObjectName("PB_updateUser");
        PB_updateUser->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Segoe UI\";\n"
"color: rgb(221, 221, 221);"));

        verticalLayout_6->addWidget(PB_updateUser);

        LW_admin = new QListWidget(tabAdminPanel_9);
        LW_admin->setObjectName("LW_admin");
        LW_admin->setGeometry(QRect(401, 21, 331, 141));
        LW_admin->setStyleSheet(QString::fromUtf8("color: rgb(249, 249, 249);\n"
"font: 700 9pt \"Segoe UI\";"));
        pushButton = new QPushButton(tabAdminPanel_9);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(399, 170, 331, 25));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"color: rgb(221, 221, 221);"));
        layoutWidget_5 = new QWidget(tabAdminPanel_9);
        layoutWidget_5->setObjectName("layoutWidget_5");
        layoutWidget_5->setGeometry(QRect(403, 243, 331, 26));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        LE_usernameAccNum = new QLineEdit(layoutWidget_5);
        LE_usernameAccNum->setObjectName("LE_usernameAccNum");

        horizontalLayout_8->addWidget(LE_usernameAccNum);

        PB_getAccountNumberAdmin = new QPushButton(layoutWidget_5);
        PB_getAccountNumberAdmin->setObjectName("PB_getAccountNumberAdmin");
        PB_getAccountNumberAdmin->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Segoe UI\";\n"
"color: rgb(221, 221, 221);"));

        horizontalLayout_8->addWidget(PB_getAccountNumberAdmin);

        layoutWidget_6 = new QWidget(tabAdminPanel_9);
        layoutWidget_6->setObjectName("layoutWidget_6");
        layoutWidget_6->setGeometry(QRect(402, 210, 331, 26));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        LE_deleteUserAccountNumber = new QLineEdit(layoutWidget_6);
        LE_deleteUserAccountNumber->setObjectName("LE_deleteUserAccountNumber");

        horizontalLayout_4->addWidget(LE_deleteUserAccountNumber);

        PB_deleteUser = new QPushButton(layoutWidget_6);
        PB_deleteUser->setObjectName("PB_deleteUser");
        PB_deleteUser->setStyleSheet(QString::fromUtf8("font: 700 8pt \"Segoe UI\";\n"
"color: rgb(221, 221, 221);"));

        horizontalLayout_4->addWidget(PB_deleteUser);

        PB_viewBankDatabase = new QPushButton(tabAdminPanel_9);
        PB_viewBankDatabase->setObjectName("PB_viewBankDatabase");
        PB_viewBankDatabase->setGeometry(QRect(531, 433, 191, 25));
        PB_viewBankDatabase->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"color: rgb(221, 221, 221);"));
        PB_TransactionHistoryAdmin = new QPushButton(tabAdminPanel_9);
        PB_TransactionHistoryAdmin->setObjectName("PB_TransactionHistoryAdmin");
        PB_TransactionHistoryAdmin->setGeometry(QRect(531, 371, 191, 25));
        PB_TransactionHistoryAdmin->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"color: rgb(221, 221, 221);"));
        PB_ViweAccountDetailsAdmin = new QPushButton(tabAdminPanel_9);
        PB_ViweAccountDetailsAdmin->setObjectName("PB_ViweAccountDetailsAdmin");
        PB_ViweAccountDetailsAdmin->setGeometry(QRect(531, 402, 191, 25));
        PB_ViweAccountDetailsAdmin->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"color: rgb(221, 221, 221);"));
        tabWidget->addTab(tabAdminPanel_9, QString());
        tabBankDatabase_4 = new QWidget();
        tabBankDatabase_4->setObjectName("tabBankDatabase_4");
        label_17 = new QLabel(tabBankDatabase_4);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(-2, -5, 751, 501));
        label_17->setPixmap(QPixmap(QString::fromUtf8("C:/Users/t/Pictures/banking-financial-digitally-blog-banner.jpg")));
        label_17->setScaledContents(true);
        label_18 = new QLabel(tabBankDatabase_4);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(-500, -20, 1251, 531));
        label_18->setPixmap(QPixmap(QString::fromUtf8("C:/Users/t/Pictures/digital-banking-740x445.jpg")));
        label_18->setScaledContents(true);
        PB_viewBankDatabaseFunction = new QPushButton(tabBankDatabase_4);
        PB_viewBankDatabaseFunction->setObjectName("PB_viewBankDatabaseFunction");
        PB_viewBankDatabaseFunction->setGeometry(QRect(80, 320, 541, 24));
        PB_viewBankDatabaseFunction->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 31, 60);\n"
"color: rgb(247, 247, 247);\n"
"font: 700 9pt \"Segoe UI\";"));
        PB_ClearBankDp = new QPushButton(tabBankDatabase_4);
        PB_ClearBankDp->setObjectName("PB_ClearBankDp");
        PB_ClearBankDp->setGeometry(QRect(80, 350, 541, 24));
        PB_ClearBankDp->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 31, 60);\n"
"color: rgb(247, 247, 247);\n"
"font: 700 9pt \"Segoe UI\";"));
        LW_BankDP = new QListWidget(tabBankDatabase_4);
        LW_BankDP->setObjectName("LW_BankDP");
        LW_BankDP->setGeometry(QRect(81, 31, 541, 281));
        LW_BankDP->setStyleSheet(QString::fromUtf8("color: rgb(247, 247, 247);\n"
"background-color: rgb(16, 31, 60);\n"
"font: 700 10pt \"Segoe UI\";"));
        LW_BankDP->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        LW_BankDP->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tabWidget->addTab(tabBankDatabase_4, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QString());
        Pb_Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Rasha Yasser", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWelcom_0), QCoreApplication::translate("MainWindow", "Welcome", nullptr));
        label_2->setText(QString());
        PB_Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Enter Port:-", nullptr));
        LE_Port->setInputMask(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Enter IP:-", nullptr));
        lE_IP->setInputMask(QCoreApplication::translate("MainWindow", "000.000.000.000", nullptr));
        lE_IP->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        PB_Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        PB_Disconnect->setText(QCoreApplication::translate("MainWindow", "DisConnect", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(widget), QCoreApplication::translate("MainWindow", "Connection", nullptr));
        label_3->setText(QString());
        LE_userName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        LE_password->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        PB_Login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabLogin_11), QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_4->setText(QString());
        comboBox_11->setItemText(0, QCoreApplication::translate("MainWindow", "                                Operations", nullptr));
        comboBox_11->setItemText(1, QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        comboBox_11->setItemText(2, QCoreApplication::translate("MainWindow", "View Balance", nullptr));
        comboBox_11->setItemText(3, QCoreApplication::translate("MainWindow", "Transfer Amount", nullptr));

        LE_usernameForAccountNumber_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Username", nullptr));
        PB_getAccountNumberUser_8->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        LE_accountNumber_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Account Number", nullptr));
        PB_viewBalance_8->setText(QCoreApplication::translate("MainWindow", "View Balance", nullptr));
        PB_transferAmount_8->setText(QCoreApplication::translate("MainWindow", "Transfer Amount", nullptr));
        LE_fromAccount_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "From Account", nullptr));
        LE_toAccount_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "To Account", nullptr));
        LE_transferAmount_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "Transfer Amount", nullptr));
        CB_transactionType_8->setItemText(0, QCoreApplication::translate("MainWindow", "TransactionType", nullptr));
        CB_transactionType_8->setItemText(1, QCoreApplication::translate("MainWindow", "Withdrawal", nullptr));
        CB_transactionType_8->setItemText(2, QCoreApplication::translate("MainWindow", "Deposit", nullptr));

        LE_accountNumber2_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Account Number", nullptr));
        LE_transactionAmount_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "Transaction Amount", nullptr));
        PB_makeTransaction_8->setText(QCoreApplication::translate("MainWindow", "Make Transaction", nullptr));
        PB_ViweAccountDetails->setText(QCoreApplication::translate("MainWindow", "View Account Details", nullptr));
        PB_TransactionHistory->setText(QCoreApplication::translate("MainWindow", "Transaction History", nullptr));
        PB_ClearUserLw->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(userOperationsTab_7), QCoreApplication::translate("MainWindow", "User Operations", nullptr));
        label_14->setText(QString());
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "                                         Authentication", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "User", nullptr));

        PB_viewAccountDetailsFunction->setText(QCoreApplication::translate("MainWindow", "View Account Details", nullptr));
        LE_adminUserName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Admin User Name", nullptr));
        PB_ClearLwAccDetails->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        LE_accountNumberViewD->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter User Account Number", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAccountDetails_8), QCoreApplication::translate("MainWindow", "Account Details", nullptr));
        label_15->setText(QString());
        LE_adminUserName1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Admin User Name", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "                                                                 Authentication", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("MainWindow", "User", nullptr));

        LE_transactionAccountNumber->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter  User Account Number", nullptr));
        PB_viewTransactionHistoryFunction->setText(QCoreApplication::translate("MainWindow", "View Transaction History", nullptr));
        PB_ClearLwTrans->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTransactionHistory_8), QCoreApplication::translate("MainWindow", "Transaction History", nullptr));
        label_16->setText(QString());
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "                                Authentication", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "User", nullptr));

        LE_authentication->setPlaceholderText(QCoreApplication::translate("MainWindow", "Authentication(Admin or User)", nullptr));
        LE_newFullName->setPlaceholderText(QCoreApplication::translate("MainWindow", "New User Full Name", nullptr));
        LE_newUsername->setPlaceholderText(QCoreApplication::translate("MainWindow", "New Username", nullptr));
        LE_newPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "New Password", nullptr));
        LE_userAge->setPlaceholderText(QCoreApplication::translate("MainWindow", "User Age", nullptr));
        LE_initialBalance->setPlaceholderText(QCoreApplication::translate("MainWindow", "Initial Balance", nullptr));
        LE_phoneNumber->setPlaceholderText(QCoreApplication::translate("MainWindow", "User Phone Number", nullptr));
        LE_userEmail->setPlaceholderText(QCoreApplication::translate("MainWindow", "User Email", nullptr));
        PB_createNewUser->setText(QCoreApplication::translate("MainWindow", "Create New User", nullptr));
        LE_updateAccountNumber->setPlaceholderText(QCoreApplication::translate("MainWindow", "User Account Number", nullptr));
        LE_updateUsername->setPlaceholderText(QCoreApplication::translate("MainWindow", "Update User Name", nullptr));
        LE_updatePassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "Update User Password", nullptr));
        LE_updatePhoneNum->setPlaceholderText(QCoreApplication::translate("MainWindow", "Update User Phone Number", nullptr));
        LE_updateUserEmail->setPlaceholderText(QCoreApplication::translate("MainWindow", "Update User Email", nullptr));
        PB_updateUser->setText(QCoreApplication::translate("MainWindow", "Update User", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        LE_usernameAccNum->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Username", nullptr));
        PB_getAccountNumberAdmin->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        LE_deleteUserAccountNumber->setPlaceholderText(QCoreApplication::translate("MainWindow", "Delete User Account Number", nullptr));
        PB_deleteUser->setText(QCoreApplication::translate("MainWindow", "Delete User", nullptr));
        PB_viewBankDatabase->setText(QCoreApplication::translate("MainWindow", "View Bank Database", nullptr));
        PB_TransactionHistoryAdmin->setText(QCoreApplication::translate("MainWindow", "Transaction History", nullptr));
        PB_ViweAccountDetailsAdmin->setText(QCoreApplication::translate("MainWindow", "View Account Details", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAdminPanel_9), QCoreApplication::translate("MainWindow", "Admin Panel", nullptr));
        label_17->setText(QString());
        label_18->setText(QString());
        PB_viewBankDatabaseFunction->setText(QCoreApplication::translate("MainWindow", "View Bank Database", nullptr));
        PB_ClearBankDp->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabBankDatabase_4), QCoreApplication::translate("MainWindow", "Bank Database", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
