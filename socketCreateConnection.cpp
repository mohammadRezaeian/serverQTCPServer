#include "socketCreateConnection.h"

socketCreateConnection::socketCreateConnection(QObject *parent)
    : QObject{parent}
{
    m_tcpServer = new QTcpServer(this);
    m_tcpSocket = new QTcpSocket(this);

    connect(m_tcpServer, &QTcpServer::newConnection, this, &socketCreateConnection::newConnection);
}

void socketCreateConnection::createConnectionServer()
{

    if(!m_tcpServer->listen(QHostAddress::Any,1234))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "server starts";
    }
}

void socketCreateConnection::newConnection()
{
    m_tcpSocket = m_tcpServer->nextPendingConnection();
    connect(m_tcpSocket, &QTcpSocket::readyRead , this , &socketCreateConnection::reciveData);

    m_tcpSocket->write("hello client");
    m_tcpSocket->flush();
    m_tcpSocket->waitForBytesWritten(10);
    //    _socket->close();
}

void socketCreateConnection::reciveData()
{
    qDebug() << m_tcpSocket->readAll();
}
