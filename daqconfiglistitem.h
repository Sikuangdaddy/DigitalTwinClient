#pragma once

#ifndef DAQCONFIGLISTITEM_H
#define DAQCONFIGLISTITEM_H

#include <QObject>
#include <QLabel>
#include <QComboBox>

class DAQConfigListItem: public QObject
{
    Q_OBJECT
private:
    QLabel *label;
    QComboBox *devices;
    QComboBox *channels;
    QComboBox *ranges;
private slots:
    void deviceChanged();
public:
    explicit DAQConfigListItem(const QString &text);
    QLabel *getLabel() const;
    QComboBox *getDevices() const;
    QComboBox *getChannels() const;
    QComboBox *getRanges() const;
};

#endif // DAQCONFIGLISTITEM_H
