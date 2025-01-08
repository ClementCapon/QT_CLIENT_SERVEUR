#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QWidget>

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);

private slots:
    void connectToServer();
    void sendData();
    void readData();

private:
    QTcpSocket *tcpSocket;
};

#endif // CLIENT_H
