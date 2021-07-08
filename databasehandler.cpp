#include "databasehandler.h"

DatabaseHandler::DatabaseHandler(QObject *parent) : QObject(parent) ,apikey(QString())
{
    Qman = new QNetworkAccessManager();
}

DatabaseHandler::~DatabaseHandler()
{
    Qman->deleteLater();
}

void DatabaseHandler::setAPIkey(const QString &apikey)
{
    this->apikey = apikey;
}

void DatabaseHandler::signup(const QString &email, const QString &password)
{
    QString signupEndPoint = "https://identitytoolkit.googleapis.com/v1/accounts:signUp?key=" + apikey;
    QVariantMap Qvar;
    Qvar ["email"] = email;
    Qvar ["password"] = password;
    Qvar ["returnSecureToken"] = true;

    QJsonDocument Qjson = QJsonDocument::fromVariant(Qvar);
    performPOST(signupEndPoint, Qjson);
}

void DatabaseHandler::signin(const QString &email, const QString &password)
{
    QString signinEndPoint = "https://identitytoolkit.googleapis.com/v1/accounts:signInWithPassword?key=" + apikey;
    QVariantMap Qvar;
    Qvar ["email"] = email;
    Qvar ["password"] = password;
    Qvar ["returnSecureToken"] = true;

    QJsonDocument Qjson = QJsonDocument::fromVariant(Qvar);
    performPOST(signinEndPoint, Qjson);
}

void DatabaseHandler::realtime(const QString &fname, const QString &lname, const QString &uname)
{
    QVariantMap QV;
    QV ["First Name"] = fname;
    QV ["Last Name"] = lname;
    QV ["User Name"] = uname;

    QJsonDocument QJ = QJsonDocument::fromVariant(QV);
}

void DatabaseHandler::QReplyReadyRead()
{
    QByteArray Qbt = Qreply->readAll();
    Qreply->deleteLater();

    parseResponse(Qbt);
}

void DatabaseHandler::performPOST(const QString &url, const QJsonDocument &payload)
{
    QNetworkRequest Qreq((QUrl(url)));
    Qreq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    Qreply = Qman->post(Qreq, payload.toJson());
    qDebug() << Qreply;
    connect(Qreply, &QNetworkReply::readyRead, this, &DatabaseHandler::QReplyReadyRead);
}

void DatabaseHandler::parseResponse(const QByteArray &Qbt)
{
    QJsonDocument QJSON = QJsonDocument::fromJson(Qbt);

    if(QJSON.object().contains("error")){
        qDebug() << "Error";
    }
    else if (QJSON.object().contains("localId")){
        localid = QJSON.object().value("localId").toString();
        qDebug() << localid;
    }
}


