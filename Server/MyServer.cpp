#include "MyServer.h"

MyServer::MyServer(QObject *parent)
    : QTcpServer{parent},qin(stdin),qout(stdout)
{}

void MyServer::startServer()
{
    //ask user to enter the port number for the server
    qout<<"Enter Server To Listen to => ";
    qout.flush();
    port = qin.readLine().toInt();

    //listen builtin function in QTcpserver mkae the server listen to port
    this->listen(QHostAddress::Any,port);//take ip & port

    //check if server is listen to port
    if(this->isListening())
    {
        qout<<"The Server Is Up And Listening To Port => "<<port<<Qt::endl;
        qout.flush();
    }
    else
    {
        qout<<"The Server Cant't Listen To Port => "<<port<<Qt::endl;
        qout.flush();
    }
}
//slot call when server start
void MyServer::incomingConnection(qintptr handle)//handle is a i=unique number for every client
{
    qDebug()<<"Client "<<handle <<" Is Connecting....";

    MyServerHandler *server = new MyServerHandler(handle,this);//send the unique id to contractor in myserverhandler
    connect(server,&QThread::finished,server,&QThread::deleteLater);//delet resources after client end the connection
    server->start();// now will jumb to run function

}
