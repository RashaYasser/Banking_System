#include "MyServerHandler.h"
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

MyServerHandler::MyServerHandler(int ID, QObject *parent)
    : QThread(parent), id(ID), socket(nullptr), databaseManager(DataBaseManager::getInstance()) // Use Singleton instance
{

}

void MyServerHandler::sendResponse(const QJsonObject &response)
{
    if (socket->isOpen())
    {
        // Convert the response to a JSON byte array
        QByteArray byteArray = QJsonDocument(response).toJson(QJsonDocument::Compact);

        // Write the byte array to the socket
        qint64 bytesWritten = socket->write(byteArray);
        socket->flush();

        // Error handling for write failures
        if (bytesWritten == -1)
        {
            qDebug() << "Failed to write to socket:" << socket->errorString();
        }
        else
        {
            qDebug() << "Successfully wrote to socket:" << bytesWritten << "bytes";
        }
    }
    else
    {
        qDebug() << "Socket is not open!";
    }
}


void MyServerHandler::logRequest(const QString &action, const QJsonObject &request)
{
    QString logFilePath = "D:\\ITIDA_FINAL_PROJECT3\\Server\\Requests.log"; // Define the path to the log file
    QFile logFile(logFilePath); // Create a QFile object with the specified path
    if (!logFile.open(QIODevice::Append | QIODevice::Text)) // Open the file in append mode for text
    {
        qWarning("Failed to open log file."); // Print a warning if the file could not be opened
        return; // Exit the function if the file could not be opened
    }

    QTextStream out(&logFile);
    QDateTime timestamp = QDateTime::currentDateTime();
    QString logEntry = QString("Action: [%1]\nRequest: %2\nDate: %3\n")
                           .arg(action)
                           .arg(QString(QJsonDocument(request).toJson(QJsonDocument::Compact)))
                           .arg(timestamp.toString(Qt::ISODate));


/*
    QString logEntry = QString("Action:[%1]\n Request:%2\n, Date: %3\n") // Format the log entry
                           .arg(action) // Add the action
                           .arg(QString(QJsonDocument(request).toJson(QJsonDocument::Compact)))
                           .arg(timestamp.toString(Qt::ISODate)); */// Add the timestamp
    out << logEntry; // Write the log entry to the file
    logFile.close(); // Close the file
}

void MyServerHandler::run()
{
    qDebug()<<"Client "<< id <<" Is Running On Thread => "<<QThread::currentThreadId()<<Qt::endl;
    socket = new QTcpSocket;//initalize socket
    //how socket know the client ?
    socket->setSocketDescriptor(id);//set the id for this client

    connect(socket,&QTcpSocket::readyRead,this,&MyServerHandler::onReadyRead,Qt::DirectConnection);
    connect(socket,&QTcpSocket::disconnected,this,&MyServerHandler::onDisconnect,Qt::DirectConnection);

    //if you write any connect in run function you must do this two steps
    exec();//1-start event loop(This is a member function for QThread ) 2-write Qt::DirectConnection);
}

void MyServerHandler::onReadyRead()
{

    // Read all available data from the socket
    QByteArray data = socket->readAll();

    // Parse the data into a QJsonDocument
    QJsonDocument requestDoc = QJsonDocument::fromJson(data);

    // Extract the JSON object from the document
    QJsonObject request = requestDoc.object();

    // Prepare a response JSON object
    QJsonObject response = handleRequest(request);
    sendResponse(response);

}


void MyServerHandler::onDisconnect()
{
    if(socket->isOpen())
    {
        socket->close();
        qDebug()<<"Client "<<id<<"Has Disconnected..."<<Qt::endl;
    }
}

QJsonObject MyServerHandler::handleRequest(const QJsonObject &request)
{
    logRequest(request["Action"].toString(), request);
    QString action = request["Action"].toString();
    ReceivedResponseHandler handler(action);
    return handler.handleResponse(request, databaseManager);
}
