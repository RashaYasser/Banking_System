#ifndef RESPONSEHANDLER_H
#define RESPONSEHANDLER_H

#include <QJsonObject>
#include <QObject>

class MainWindow; // Forward declaration of MainWindow

class ResponseHandler : public QObject
{
    Q_OBJECT

public:
    explicit ResponseHandler(MainWindow *mainWindow, QObject *parent = nullptr);

    void handleResponse(const QJsonObject &response);

private:
    MainWindow *m_mainWindow;
};

#endif // RESPONSEHANDLER_H
