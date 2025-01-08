#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);

private slots:
    void newConnection();
    void readData();

private:
    QTcpServer *tcpServer;
    QList<QTcpSocket *> clients;
};

#endif // SERVER_H
