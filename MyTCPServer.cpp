#include "MyTCPServer.h"

MyTCPServer::MyTCPServer(int port, QObject *parent)
    : QObject{parent}
{
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &MyTCPServer::onClientConnecting);

    isStarted = server->listen(QHostAddress::Any, port);
    // not listening to port
    if (!isStarted) {
        qDebug() << "server could not start";
    } else {
        qDebug() << "server listening";
    }


}

void MyTCPServer::onClientConnecting() {
    qDebug() << "client connected to server";
    auto socket = server->nextPendingConnection();
    socketsList.append(socket);

    emit newClientConnected();
}

bool MyTCPServer::getIsStarted() {
    return isStarted;
}
