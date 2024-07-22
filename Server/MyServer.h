#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTextStream>
#include <QDebug>
#include <MyServerHandler.h>

// The MyServer class inherits from QTcpServer and is responsible for starting the server
// and handling incoming connections from clients.
class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    // Constructor for MyServer, optionally takes a parent QObject
    explicit MyServer(QObject *parent = nullptr);

    // Function to start the server, initializes the server on the specified port
    void startServer();

protected:
    // Overridden slot function from QTcpServer, called when a client tries to connect
    // 'handle' is the socket descriptor for the incoming connection
    void incomingConnection(qintptr handle) override;

private:
    // QTextStream objects for input and output stream handling
    QTextStream qin;
    QTextStream qout;

    // Port number on which the server will listen for incoming connections
    qint32 port;
};

#endif // MYSERVER_H
