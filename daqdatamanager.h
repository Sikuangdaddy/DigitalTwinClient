#pragma once

#ifndef DAQDATAMANAGER_H
#define DAQDATAMANAGER_H

#include "DAQ/bdaqctrl.h"
#include <QObject>
#include <QMap>
#include <QTimer>
#include "daqconfigdialog.h"

class DAQDataManager: public QObject
{
    Q_OBJECT
private:
    QTimer *timer;
    DAQConfigDialog *configDialog;
    QMap<QString, double> datas;
    QMap<QString, DAQConfigDialog::ConfigureParameter> sources;
private slots:
    void timerTicked();
public:
    explicit DAQDataManager(const QStringList &params);
    QJsonObject toJson() const;
    QStringList toQStringList() const;
public slots:
    void showConfigDialog();
};

#endif // DAQDATAMANAGER_H
