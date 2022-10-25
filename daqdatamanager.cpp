#include "daqdatamanager.h"
#include <QJsonObject>
#include <QTimer>
#include <QDebug>

DAQDataManager::DAQDataManager(const QStringList &params) :
    timer(new QTimer), configDialog(new DAQConfigDialog(params))
{
    connect(timer, &QTimer::timeout, this, &DAQDataManager::timerTicked);
    timer->start(200);
}

void DAQDataManager::timerTicked()
{
    for (const QString &key: sources.keys())
    {
        if (sources[key].instantAiCtrl != nullptr)
        {
            sources[key].instantAiCtrl->Read(sources[key].channel, datas[key]);
        }
    }
}

QJsonObject DAQDataManager::toJson() const
{
    QJsonObject json;
    for (const QString &key: datas.keys())
    {
        json.insert(key, datas[key]);
    }
    return json;
}

QStringList DAQDataManager::toQStringList() const
{
    QStringList list;
    for (const QString &key: datas.keys())
    {
        list << key + QString::number(datas[key]);
    }
    return list;
}

void DAQDataManager::showConfigDialog()
{
    if (configDialog->exec() == QDialog::Accepted)
    {
        configDialog->updateConfig(sources);
    }
}
