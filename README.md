# Banking System Project using Qt

![ce-este-open-banking](https://github.com/user-attachments/assets/85d38c6e-fac7-498d-8ff4-5c4f0aaa348a)

## Summary of Sections

- **Overview:** Provides a general description of the project.
- **Features:** Details various functionalities and features.
- **Encryption and Signature:** Explains security measures.
- **Requirements:** Lists prerequisites and system requirements.
- **Installation and Setup:** Provides step-by-step instructions for setting up the project.
- **Usage:** Guides users on how to use the application.
- **GUI Interface**: Visuals and descriptions of the GUI.
  
## Overview

This project creates a comprehensive client-server banking system, expertly designed to manage a wide range of banking operations using the client-server model. 
It supports multiple functionalities for both user and admin roles, including login, account management, transaction processing, and more.

The system Designed and developed using the Qt/C++ framework, which provides a robust environment for both graphical user interface (GUI) development and network communication. 
This framework ensures a seamless and interactive user experience while enabling secure and efficient data exchange between client and server applications.

## Features

### Request/Response Pairs

1. **Log In (user, pass)**
   - **Request:** Login request with user or admin credentials.
   - **Response:** Boolean (`true` if credentials are correct, `false` otherwise).

2. **Get Account Number (username)**
   - **Authorized:** User
   - **Request:** Retrieve account number for a given username (must be logged in).
   - **Response:** Account number string or empty string if not logged in.

3. **Get Account Number (admin, username)**
   - **Authorized:** Admin
   - **Request:** Retrieve account number for a given username (admin must be logged in).
   - **Response:** Account number string.

4. **View Account Balance (account number)**
   - **Authorized:** User & Admin
   - **Request:** Retrieve the balance of a given account number.
   - **Response:** Signed 4-byte integer representing the balance.

5. **View Transaction History (account number, count)**
   - **Authorized:** User & Admin
   - **Request:** Retrieve the last `count` transactions for an account number.
   - **Response:** Serialized JSON array of transactions.

6. **Make Transaction (account number, transaction amount)**
   - **Authorized:** User
   - **Request:** Modify the balance of an account by a transaction amount.
   - **Response:** Boolean (`true` if transaction is possible, `false` otherwise).

7. **Transfer Amount (from_AN, to_AN, transfer amount)**
   - **Authorized:** User
   - **Request:** Transfer an amount from one account to another.
   - **Response:** Boolean (`true` if transaction is possible, `false` otherwise).

8. **View Bank Database**
   - **Authorized:** Admin
   - **Request:** Retrieve the entire bank database.
   - **Response:** Serialized JSON array of all user data.

9. **Create New User (userdata)**
   - **Authorized:** Admin
   - **Request:** Create a new user with provided data.
   - **Response:** Boolean (`true` if creation is successful, `false` otherwise).

10. **Delete User (accountnumber)**
    - **Authorized:** Admin
    - **Request:** Delete a user by account number.
    - **Response:** Boolean (`true` if deletion is successful, `false` otherwise).

11. **Update User (AN, newData)**
    - **Authorized:** Admin
    - **Request:** Update user data in the database.
    - **Response:** Boolean (`true` if update is successful, `false` otherwise).

### Encryption and Signature

- **Encryption:** All client requests are encrypted before being sent to the server. The server decrypts these requests upon receipt.
- **Signature:** Each request includes a digital signature for verification to ensure the integrity and authenticity of the request.

## Requirements

1. **System Architecture**
   - The system should be distributed across two applications—one client and one server—developed using Qt/C++.
   - **Client Application:** A graphical user interface (GUI) application developed using Qt, enabling users to interact with the banking system through a user-friendly interface.
   - **Server Application:** A console-based application that manages and processes client requests, handling multiple connections concurrently through multi-threading.
     
2. **User Types**
   - Only two user types are supported: standard user and admin.

3. **Framework**
   - Developed using the Qt/C++ framework.

4. **Communication**
   - Client-server communication is handled via sockets.

5. **Client Application**
   - GUI-based application that runs continuously until an exit command is issued.

6. **Server Application**
   - Console application that runs in the background.

7. **Concurrency**
   - The server should handle multiple requests from different clients using threads.

8. **Encryption**
   - Client requests are encrypted before sending. The server decrypts the requests.
   - Requests include a signature for verification.

9. **Email Notifications**
   - Server responses sent to a client’s email.

10. **Design**
    - OOP design principles with UML diagrams including Sequence, Class, and State diagrams are applied.

11. **Output Formatting**
    - Client application should format JSON data into readable tables.

12. **Server as a Service**
    - The server can be set up as a service using systemctl.

13. **Logging Requests**
    - The server logs client requests to a file.

14. **Request Signatures**
    - Added for verification of request integrity.


## Installation and Setup

### Prerequisites

- Qt6
- C++ compiler
- JSON library
- Git (optional, for version control)

### Steps

1. **Clone the Repository**
   ```bash
    git clone < repository-url>
    cd banking_system
   
2. Build the Project
      ```bash
     qmake
     make

3. Run the Server
      ```bash
   ./server.exe

4. Run the Client
      ```bash
   ./client.exe


## Usage

1. Start the Server Application
   
2. Start the Client Application
   
3. When prompted, enter the server's IP address and port to connect.

Example:

Enter server IP: 192.168.1.100
Enter server port: 12356

4. Log in as an admin or a user.
   
5. Perform banking operations based on the logged-in role.
   
6. Log out and exit the application when done.
   

## GUI Interface

1. Start the Application
   
   ![start](https://github.com/user-attachments/assets/dd7585e5-27e5-4531-8b0b-c8fdf085e2e8)

    -To Start App click on PB Start
  
2. Enter IP and Port to Connect to the Server
   
   ![connection](https://github.com/user-attachments/assets/3755f212-eea8-47dc-ac14-0a63e485815d)

    -To Start Connection Between server and client
   
3. Login as User or Admin
   
   ![login](https://github.com/user-attachments/assets/1a2021b9-4d1e-45de-b820-219881b5f645)
   
4. User Features 

   ![User op](https://github.com/user-attachments/assets/820bc556-4f90-4e92-b0bd-dc41f5e41752)

5. View Account Details
   
   ![acc](https://github.com/user-attachments/assets/703734e2-fdca-4496-9b0b-a60b82164354)

     - select authentication
     - if user you can see only your details
     - admin can see any account but must enter her user name
      
6. View Transaction History
   
   ![TRans](https://github.com/user-attachments/assets/0a5998e0-0b67-4116-adc1-fb2904c4182a)
    
    - select authentication
    - if user you can see only your transaction history
    - admin can see any transaction history for any account but must enter her user name 

7. Admin Features

   ![admin](https://github.com/user-attachments/assets/672f7a69-5097-432a-80ce-cd64aa60e08e)

8. View bank DataBase
    
    ![bankdp](https://github.com/user-attachments/assets/a25cc002-0f09-4929-9b55-90353fee4062)
 
    -only admin can see the database







