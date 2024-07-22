/************final********/
#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

/**
 * Manages communication with a TCP server.
 *
 * This class connects to a server, sends and receives data in JSON format, and handles socket events.
 */
class MyClient : public QObject
{
    Q_OBJECT

public:
    explicit MyClient(QObject *parent = nullptr);

    /*
     * Description:
     * Connects to the server at the given IP address and port.
     * ip The IP address of the server.
     * port The port number to connect to.
     *
     * Starts a connection to the server using the provided IP address and port number.
     */
    void ConnectToDevice(QString ip, qint32 port);

    /*
     * Description:
     * Sends JSON data to the server.
     * data The JSON object to send.
     *
     * Sends the provided JSON data to the server.
     */
    void sendData(const QJsonObject &data);

    /*
     * Description:
     * Disconnects from the server.
     *
     * Closes the connection to the server.
     */
    void Disconnect();

signals:
    /*
     * Description:
     * Emitted when a response is received from the server.
     * response The JSON data received from the server.
     *
     * This signal is sent when a response from the server is received.
     * The response is provided as JSON data.
     */
    void responseReceived(const QJsonObject &response);

    /*
     * Description:
     * Emitted when the connection to the server is established.
     *
     * This signal is sent when the connection to the server is successfully set up.
     */
    void connected();

    /*
     * Description:
     * Emitted when the connection to the server is closed.
     *
     * This signal is sent when the connection to the server is closed or lost.
     */
    void disconnected();

    /*
     * Description:
     * Emitted when there is a socket error.
     * socketError The error that occurred.
     *
     * This signal is sent when something goes wrong with the socket connection.
     * It provides details about the problem through the `socketError` parameter.
     */
    void errorOccurred(QAbstractSocket::SocketError socketError);

    /*
     * Description:
     * Emitted when the socket's state changes.
     * socketState The new state of the socket.
     *
     * This signal is sent when the state of the socket changes (e.g., from connected to disconnected).
     * The new state is provided through the `socketState` parameter.
     */
    void stateChanged(QAbstractSocket::SocketState socketState);

private slots:
    /*
     * Description:
     * Called when the connection to the server is established.
     *
     * Handles the event when the connection to the server is successfully set up.
     */
    void onConnected();

    /*
     * Description:
     * Called when the connection to the server is closed.
     *
     * Handles the event when the connection to the server is closed or lost.
     */
    void onDisconnected();

    /*
     * Description:
     * Called when there is a socket error.
     * socketError The error that occurred.
     *
     * Handles the event when a socket error occurs.
     * Provides details about the error through the `socketError` parameter.
     */
    void onErrorOccurred(QAbstractSocket::SocketError socketError);

    /*
     * Description:
     * Called when the socket's state changes.
     * socketState The new state of the socket.
     *
     * Handles the event when the state of the socket changes.
     * The new state is provided through the `socketState` parameter.
     */
    void onStateChanged(QAbstractSocket::SocketState socketState);

    /*
     * Description:
     * Called when new data is available to read from the socket.
     *
     * Handles incoming data from the server and processes it.
     * Emits the responseReceived signal if a complete response is received.
     */
    void onReadyRead();

private:
    QString ip; //The IP address of the server to connect to.
    qint32 port; // The port number of the server to connect to.
    QTcpSocket socket; //The TCP socket used for communication.
};

#endif // MYCLIENT_H
