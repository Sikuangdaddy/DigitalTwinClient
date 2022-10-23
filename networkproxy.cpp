#include "networkproxy.h"
#include <QJsonDocument>

const QString NetworkProxy::root_url("http://127.0.0.1:8080");

NetworkProxy::NetworkProxy(): manager(new QNetworkAccessManager())
{
    connect(manager, &QNetworkAccessManager::finished, this, &NetworkProxy::get_data_back);
    connect(manager, &QNetworkAccessManager::finished, this, &NetworkProxy::post_data_back);
}

void NetworkProxy::get_data(const QString &device, const QString &type)
{
    status = GET;
    QString url = root_url + '/' + device + '/' + type;
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void NetworkProxy::post_data(const QString &device, const QString &type, const QJsonObject &json)
{
    status = POST;
    QString url = root_url + '/' + device + '/' + type;
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=UTF-8");
    manager->post(request, QJsonDocument(json).toJson(QJsonDocument::Compact));
}

void NetworkProxy::get_data_back(QNetworkReply *reply)
{
    if (status != GET) {
        return ;
    }
    QJsonDocument document = QJsonDocument::fromJson(reply->readAll().data());
    QJsonObject *json = new QJsonObject(document.object());
    emit get_finished(json);
    status = DEFAULT;
}

void NetworkProxy::post_data_back(QNetworkReply *reply)
{
    if (status != POST) {
        return ;
    }
    QJsonDocument document = QJsonDocument::fromJson(reply->readAll().data());
    QJsonObject *json = new QJsonObject(document.object());
    emit get_finished(json);
    status = DEFAULT;
}
