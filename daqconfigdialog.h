#pragma once

#ifndef DAQCONFIGDIALOG_H
#define DAQCONFIGDIALOG_H

#include <QDialog>
#include "DAQ/bdaqctrl.h"

namespace Ui {
class DAQConfigDialog;
}

class DAQConfigDialog : public QDialog
{
    Q_OBJECT
public:
    struct ConfigureParameter
    {
        Automation::BDaq::InstantAiCtrl *instantAiCtrl;
        int channel;
        Automation::BDaq::ValueRange valueRange;
    };
private:
    Ui::DAQConfigDialog *ui;
    void initConfigList(const QStringList &params);
    void addConfigListItem(qint32 line, const QString &param);
private slots:
    void OKPushButtonPressed();
    void cancelPushButtonPressed();
public:
    explicit DAQConfigDialog(const QStringList &params, QWidget *parent = nullptr);
    ~DAQConfigDialog();
    void updateConfig(QMap<QString, ConfigureParameter> &sources);
};

#endif // DAQCONFIGDIALOG_H
