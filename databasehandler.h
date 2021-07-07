#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <qfiledialog.h>
#include <qfile.h>
#include <QJsonDocument>
#include <QVariantMap>
#include <QNetworkRequest>
#include <fstream>
#include <QDir>

class DatabaseHandler
{
public:
    explicit DatabaseHandler(QObject *parent = nullptr);
    void setAPIkey(const QString &apikey);

public slots:
    void readyRead();

private:
    QString apikey;
    QNetworkAccessManager *Qman;
    QNetworkReply *Qreply;
};

#endif // DATABASEHANDLER_H
