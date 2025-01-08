#include "server.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

Server::Server(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Serveur en écoute sur le port 1234", this);
    layout->addWidget(label);

    tcpServer = new QTcpServer(this);

    if (!tcpServer->listen(QHostAddress::Any, 1234)) {
        qDebug() << "Le serveur n'a pas pu démarrer : " << tcpServer->errorString();
    } else {
        qDebug() << "Le serveur a démarré.";
        connect(tcpServer, &QTcpServer::newConnection, this, &Server::newConnection);
    }
}

void Server::newConnection()
{
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    clients.append(clientSocket);
    qDebug() << "Un nouveau client est connecté.";
    connect(clientSocket, &QTcpSocket::readyRead, this, &Server::readData);
    connect(clientSocket, &QTcpSocket::disconnected, [=]() {
        clients.removeOne(clientSocket);
        clientSocket->deleteLater();
        qDebug() << "Un client s'est déconnecté.";
    });
}

void Server::readData()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if (!clientSocket)
        return;

    QByteArray data = clientSocket->readAll();
    qDebug() << "Données reçues : " << data;

    if (data.trimmed() == "hello") {
        clientSocket->write("Bonjour");
    } else {
        clientSocket->write("Commande non reconnue");
    }
}
