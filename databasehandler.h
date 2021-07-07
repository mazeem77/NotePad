#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QVariantMap>

class DatabaseHandler:public QObject
{
public:
    explicit DatabaseHandler(QObject *parent = nullptr);
    ~DatabaseHandler();
    void setAPIkey(const QString &apikey);
    void signup(const QString &email, const QString &password);
    void signin(const QString &email, const QString &password);

public slots:
    void QReplyReadyRead();

private:
    void performPOST(const QString &url, const QJsonDocument &payload);
    QString apikey;
    QNetworkAccessManager *Qman;
    QNetworkReply *Qreply;
};

#endif // DATABASEHANDLER_H
