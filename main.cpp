#include <QCoreApplication>
#include "socketCreateConnection.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    socketCreateConnection server;
    server.createConnectionServer();

    return a.exec();
}
