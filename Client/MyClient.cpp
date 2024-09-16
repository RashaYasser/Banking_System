#include "MyClient.h"

#include <QDebug>

// Constructor: Initializes the MyClient object and sets up signal-slot connections.
MyClient::MyClient(QObject *parent)
    : QObject{parent}
{
    // Connects the QTcpSocket signals to the corresponding slots in MyClient
    connect(&socket, &QTcpSocket::connected, this, &MyClient::onConnected);
    connect(&socket, &QTcpSocket::disconnected, this, &MyClient::onDisconnected);
#if QT_VERSION < QT_VERSION_CHECK(5,15,0)
    connect(&socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
        [=](QAbstractSocket::SocketError socketError){
          qDebug() << "ERROR: " << socketError << '\n';
        });
#else
    connect(&socket, &QTcpSocket::errorOccurred, this, &MyClient::onErrorOccurred);
#endif
    connect(&socket, &QTcpSocket::stateChanged, this, &MyClient::onStateChanged);
    connect(&socket, &QTcpSocket::readyRead, this, &MyClient::onReadyRead);
}

// Connects to the server with the specified IP address and port.
// If already connected to a different server, it will close the existing connection first.
void MyClient::ConnectToDevice(QString ip, qint32 port)
{
    // Check if the socket is already open
    if (socket.isOpen())
    {
        // If the socket is open but connected to a different server, close it and reconnect
        if ((this->ip == ip) && (this->port == port))
        {
            // Already connected to the same server, no action needed
            return;
        }
        else
        {
            // Close the existing connection and update the IP and port
            socket.close();
            this->port = port;
            this->ip = ip;
            // Connect to the new server
            socket.connectToHost(this->ip, this->port);
        }
    }
    else
    {
        // Socket is not open, just set the IP and port and connect
        this->port = port;
        this->ip = ip;
        socket.connectToHost(this->ip, this->port);
    }
}

// Disconnects from the server by closing the socket.
void MyClient::Disconnect()
{
    // Check if the socket is open before closing
    if (socket.isOpen())
    {
        socket.close();
    }
}
void MyClient::sendData(const QByteArray& data)
{
    if (socket.state() == QTcpSocket::ConnectedState)
    {
        qint64 bytesWritten = socket.write(data);

        if (bytesWritten == -1)
        {
            qDebug() << "Failed to write data to socket:" << socket.errorString();
        }

    }
    else
    {
        qDebug() << "Socket is not connected!";
    }
}


// Slot called when the connection to the server is successfully established.
void MyClient::onConnected()
{
    // Emit the connected signal
    emit connected();
}

// Slot called when the connection to the server is closed.
void MyClient::onDisconnected()
{
    // Emit the disconnected signal
    emit disconnected();
}

// Slot called when a socket error occurs.
// Provides the error details through the socketError parameter.
void MyClient::onErrorOccurred(QAbstractSocket::SocketError socketError)
{
    // Emit the errorOccurred signal with the socket error details
    emit errorOccurred(socketError);
}

// Slot called when the state of the socket changes.
// Provides the new state through the socketState parameter.
void MyClient::onStateChanged(QAbstractSocket::SocketState socketState)
{
    // Emit the stateChanged signal with the new socket state
    emit stateChanged(socketState);
}

// Slot called when new data is available to read from the socket.
void MyClient::onReadyRead()
{
    // Read all available data from the socket
    QByteArray byteArray = socket.readAll();
    qDebug() << "Raw data received:" << byteArray;

    // Convert the data to a string for easier debugging
    QString str = QString::fromUtf8(byteArray);
    qDebug() << "Data as string:" << str;

    // Parse the JSON document from the received data
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray);

    // Check if the JSON document is valid and is an object
    if (!jsonDoc.isNull() && jsonDoc.isObject())
    {
        // Extract the JSON object from the document
        QJsonObject jsonObject = jsonDoc.object();
        qDebug() << "Parsed JSON Object:" << jsonObject;

        // Emit the responseReceived signal with the JSON object
        emit responseReceived(jsonObject);
    }
    else
    {
        // Handle the case where JSON parsing fails
        qWarning() << "Failed to parse JSON response. Data:" << str;
    }
}
