#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyTCPServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTCPServer(int port, QObject *parent = nullptr);
    bool getIsStarted();
signals:
    void newClientConnected();
private slots:
    void onClientConnecting();
private:
    QTcpServer *server;
    QList<QTcpSocket *> socketsList;
    bool isStarted;
};

#endif // MYTCPSERVER_H
