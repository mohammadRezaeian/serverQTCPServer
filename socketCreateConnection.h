#ifndef SOCKETCREATECONNECTION_H
#define SOCKETCREATECONNECTION_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class socketCreateConnection : public QObject
{
    Q_OBJECT
public:
    explicit socketCreateConnection(QObject *parent = nullptr);

    void createConnectionServer();
signals:

public slots:
    void newConnection();
    void reciveData();
private:
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
};

#endif // SOCKETCREATECONNECTION_H
