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
    if(!m_tcpSocket->isOpen())
    {
        delete m_generetor;
    }
    connect(m_tcpSocket, &QTcpSocket::readyRead , this , &socketCreateConnection::reciveData);

}

void socketCreateConnection::reciveData()
{
    bool _status;
    QByteArray _data = m_tcpSocket->readAll();
    QDataStream _stream(&_data , QIODevice::ReadOnly);
    _stream >> _status;
    if(_status)
    {
        m_generetor = new Generator(this);
//        m_generetor->setStatus(_status);
        connect(m_generetor, &Generator::dataCreated, this , &socketCreateConnection::sendDataToClient);
    }
    else
    {
        m_generetor->setStatus(false);
//        delete m_generetor;
    }
}

void socketCreateConnection::sendDataToClient(double _data)
{
    QByteArray _dataByteArray;
    QDataStream _stream(&_dataByteArray , QIODevice::WriteOnly);
    _stream << _data;
//    qDebug() << _data;
    if(m_tcpSocket->isOpen())
    {
        m_tcpSocket->write(_dataByteArray);
    }
    else
    {
        delete m_generetor;
    }
}
