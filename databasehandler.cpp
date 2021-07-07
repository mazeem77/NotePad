#include "databasehandler.h"
#include <QNetworkAccessManager>

DatabaseHandler::DatabaseHandler(QObject *parent)
    :apikey(QString())
{
    Qman = new QNetworkAccessManager(this);
}

void DatabaseHandler::setAPIkey(const QString &apikey)
{
    this->apikey = apikey;
}

