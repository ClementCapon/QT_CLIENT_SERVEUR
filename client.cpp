#include "client.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>

Client::Client(QWidget *parent) : QWidget(parent), tcpSocket(new QTcpSocket(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Client TCP", this);
    layout->addWidget(label);

    QPushButton *connectButton = new QPushButton("Se connecter", this);
    layout->addWidget(connectButton);

    QLineEdit *input = new QLineEdit(this);
    layout->addWidget(input);

    QPushButton *sendButton = new QPushButton("Envoyer", this);
    layout->addWidget(sendButton);

    tcpSocket = new QTcpSocket(this);

    connect(connectButton, &QPushButton::clicked, this, &Client::connectToServer);
    connect(sendButton, &QPushButton::clicked, [=]() {
        QString data = input->text();
        tcpSocket->write(data.toUtf8());
    });

    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::readData);
}

void Client::connectToServer()
{
    tcpSocket->connectToHost("127.0.0.1", 1234);
    if (tcpSocket->waitForConnected(3000)) {
        qDebug() << "Connecté au serveur.";
    } else {
        qDebug() << "Impossible de se connecter au serveur.";
    }
}

void Client::sendData()
{
    QString data = QString::fromUtf8(tcpSocket->readAll());
    qDebug() << "Données reçues du serveur :" << data;
}

void Client::readData()
{
    QByteArray data = tcpSocket->readAll();
    qDebug() << "Réponse du serveur : " << data;
}
