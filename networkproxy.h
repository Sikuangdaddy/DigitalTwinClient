#pragma once

#ifndef NETWORKPROXY_H
#define NETWORKPROXY_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QObject>

class NetworkProxy: public QObject
{
    Q_OBJECT
public:
    enum {
        DEFAULT,
        GET,
        POST
    } status;
private:
    QNetworkAccessManager *manager;
public:
    const static QString root_url;
    NetworkProxy();
    void get_data(const QString &device, const QString &type);
    void post_data(const QString &device, const QString &type, const QJsonObject &json);
public slots:
    void get_data_back(QNetworkReply *reply);
    void post_data_back(QNetworkReply *reply);
signals:
    void get_finished(QJsonObject *json);
    void post_finished(QJsonObject *json);
};

#endif // NETWORKPROXY_H
