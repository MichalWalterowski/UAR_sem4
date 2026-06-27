#ifndef SERWERKONFIGURACJI_H
#define SERWERKONFIGURACJI_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDataStream>
#include <QMap>
#include <vector>
#include "ProtokolSieciowy.h"

    class MyTCPServer : public QObject
    {
        Q_OBJECT
    public:
        explicit MyTCPServer(QObject *parent = nullptr);
        bool startListening(int port);
        bool isListening() {return m_isListening;}
        void stopListening();
        int getNumClients();

        void wyslijKonfigPID(double kp, double ti, double td, int metoda, int numCli = 0);
        void wyslijKonfigARX(const std::vector<double>& A, const std::vector<double>& B, int opoznienie, double szum,
                             double umin, double umax, double ymin, double ymax, bool ograniczenia, int numCli = 0);
        void wyslijKonfigGen(double amplituda, double okres, int interwal, int typ, double skladowa, double wypelnienie, int numCli = 0);
        void wyslijAkcjeSymulacji(Akcja akcja, int parametr = 0, int numCli = 0);


        void wyslijProbkeRegulatora(double u, double w, double e, double p, double i, double d, int numCli = 0);

        signals:
        void newClientConnected(QString adr);
        void clientDisconnected(int num);

        void odebranoKonfigPID(double kp, double ti, double td, int metoda);
        void odebranoKonfigARX(std::vector<double> A, std::vector<double> B, int opoznienie, double szum,
                               double umin, double umax, double ymin, double ymax, bool ograniczenia);
        void odebranoKonfigGen(double amplituda, double okres, int interwal, int typ, double skladowa, double wypelnienie);
        void odebranoAkcjeSymulacji(Akcja akcja, int parametr);

        void odebranoProbkeOdObiektu(double y);

    private slots:
        void slot_new_client();
        void slot_client_disconnected();
        void slot_newMsg();
    private:
        bool m_isListening = false;
        int m_port = 12345;
        QTcpServer m_server;
        QVector<QTcpSocket*> m_clients;
        QMap<QTcpSocket*, quint32> m_expectedSizes;
    };

#endif // SERWERKONFIGURACJI_H
