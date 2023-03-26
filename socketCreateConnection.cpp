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

    generator m_generator;
    m_vector = m_generator.getGenerated();
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out <<  m_vector;

    m_tcpSocket = m_tcpServer->nextPendingConnection();
    m_tcpSocket->write(dat);

    connect(m_tcpSocket, &QTcpSocket::readyRead , this , &socketCreateConnection::reciveData);

}

void socketCreateConnection::reciveData()
{
    qDebug() << m_tcpSocket->readAll();
}
