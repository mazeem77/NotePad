#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QVariantMap>
#include <QJsonObject>

class DatabaseHandler:public QObject
{
public:
    explicit DatabaseHandler(QObject *parent = nullptr);
    ~DatabaseHandler();
    void setAPIkey(const QString &apikey);
    void signup(const QString &email, const QString &password);
    void signin(const QString &email, const QString &password);
    void realtime(const QString &fname, const QString &lname, const QString &uname);

public slots:
    void QReplyReadyRead();

private:
    void performPOST(const QString &url, const QJsonDocument &payload);
    QString apikey;
    QString localid;
    void parseResponse(const QByteArray &Qbt);
    QNetworkAccessManager *Qman;
    QNetworkReply *Qreply;
};

#endif // DATABASEHANDLER_H
