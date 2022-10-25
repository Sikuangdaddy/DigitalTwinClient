#include "daqconfiglistitem.h"
#include "DAQ/bdaqctrl.h"
#include <QGridLayout>
#include <QDebug>

DAQConfigListItem::DAQConfigListItem(const QString &text)
    : label(new QLabel(text))
    , devices(new QComboBox)
    , channels(new QComboBox)
    , ranges(new QComboBox)
{
    connect(devices, &QComboBox::currentIndexChanged, this, &DAQConfigListItem::deviceChanged);
    Automation::BDaq::InstantAiCtrl *instantAiCtrl = Automation::BDaq::InstantAiCtrl::Create();
    Automation::BDaq::Array<Automation::BDaq::DeviceTreeNode> *supportedDevices = instantAiCtrl->getSupportedDevices();
    for (int i = 0; i < supportedDevices->getCount(); i++)
    {
        Automation::BDaq::DeviceTreeNode const &node = supportedDevices->getItem(i);
        devices->addItem(QString::fromWCharArray(node.Description));
    }
    devices->setCurrentIndex(0);
    instantAiCtrl->Dispose();
    supportedDevices->Dispose();
}

void DAQConfigListItem::deviceChanged()
{
    channels->clear();
    ranges->clear();
    std::wstring description = devices->currentText().toStdWString();
    Automation::BDaq::DeviceInformation selected(description.c_str());
    Automation::BDaq::InstantAiCtrl *instantAiCtrl = Automation::BDaq::InstantAiCtrl::Create();
    instantAiCtrl->setSelectedDevice(selected);
    qint32 channelCount = instantAiCtrl->getChannelCount();
    for (qint32 i = 0; i < channelCount; i++)
    {
        channels->addItem(QString::number(i));
    }
    Automation::BDaq::Array<Automation::BDaq::ValueRange> *valueRanges = instantAiCtrl->getFeatures()->getValueRanges();
    wchar_t vrgDescription[128];
    Automation::BDaq::MathInterval mathRanges;
    for (int i = 0; i < valueRanges->getCount(); i++)
    {
        AdxGetValueRangeInformation(valueRanges->getItem(i), sizeof(vrgDescription), vrgDescription, &mathRanges, NULL);
        QString str = QString::fromWCharArray(vrgDescription);
        ranges->addItem(str);
    }
    instantAiCtrl->Dispose();
    channels->setCurrentIndex(0);
    ranges->setCurrentIndex(0);
}

QLabel *DAQConfigListItem::getLabel() const
{
    return label;
}

QComboBox *DAQConfigListItem::getDevices() const
{
    return devices;
}

QComboBox *DAQConfigListItem::getChannels() const
{
    return channels;
}

QComboBox *DAQConfigListItem::getRanges() const
{
    return ranges;
}
