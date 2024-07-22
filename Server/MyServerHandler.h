#ifndef MYSERVERHANDLER_H
#define MYSERVERHANDLER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QJsonObject>
#include "DataBaseManager.h"
#include "RequestHandler.h"

class MyServerHandler : public QThread
{
    Q_OBJECT

public:

    // - ID: Integer representing the client ID.
    // - parent: Optional parent QObject.
    explicit MyServerHandler(int ID, QObject *parent = nullptr);

    // Description:
    // Utility function to send a JSON response to a client.
    // Parameters:
    // - response: QJsonObject containing the response data to be sent.
    void sendResponse(const QJsonObject &response);

    // Description:
    // Logs the incoming request for auditing or debugging purposes.
    // Parameters:
    // - action: QString describing the action or type of request.
    // - request: QJsonObject containing the details of the request to log.
    void logRequest(const QString &action, const QJsonObject &request);

private:
    int id;
    QTcpSocket *socket;
    DataBaseManager &databaseManager; // Reference to Singleton DataBaseManager

    QJsonObject handleRequest(const QJsonObject &request);
public slots:
    // Description:
    // Slot called when new data is available to read from the socket.
    // Reads data from the client, processes the request, and sends a response.
    void onReadyRead();

    // Description:
    // Slot called when the client disconnects.
    // Cleans up resources and handles client disconnection.
    void onDisconnect();

protected:
    // Description:
    // Override of QThread's run method.
    // Contains the main execution loop for handling client requests.
    void run() override;
};

#endif // MYSERVERHANDLER_H
