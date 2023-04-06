#ifndef SOCKETCREATECONNECTION_H
#define SOCKETCREATECONNECTION_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include "generator.h"

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
    void sendDataToClient(double _data);

private:
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
    QVector<double> m_vector;
    Generator *m_generetor;
    enum _WHATIS{
        _WHATIS_hello,
        _WHATIS_DATA_SEND
    };
};

#endif // SOCKETCREATECONNECTION_H
