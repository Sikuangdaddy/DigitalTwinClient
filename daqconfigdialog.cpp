#include "daqconfigdialog.h"
#include "daqconfiglistitem.h"
#include "ui_daqconfigdialog.h"
#include "DAQ/bdaqctrl.h"
#include <QLabel>
#include <QComboBox>
#include <QListWidgetItem>

DAQConfigDialog::DAQConfigDialog(const QStringList &params, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DAQConfigDialog)
{
    ui->setupUi(this);
    ui->configTableWidget->clear();
    QStringList tableHeader;
    tableHeader << tr("数据") << tr("设备") << tr("通道") << tr("取值");
    ui->configTableWidget->setColumnCount(tableHeader.count());
    ui->configTableWidget->setHorizontalHeaderLabels(tableHeader);
    ui->configTableWidget->verticalHeader()->setVisible(false);
    ui->configTableWidget->resizeRowsToContents();
    ui->configTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->configTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->configTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->configTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    initConfigList(params);
    connect(ui->OKPushButton, &QPushButton::pressed, this, &DAQConfigDialog::OKPushButtonPressed);
    connect(ui->cancelPushButton, &QPushButton::pressed, this, &DAQConfigDialog::cancelPushButtonPressed);
}

DAQConfigDialog::~DAQConfigDialog()
{
    delete ui;
}

void DAQConfigDialog::initConfigList(const QStringList &params)
{
    ui->configTableWidget->setRowCount(params.count());
    for (qint32 i = 0; i < params.count(); i++)
    {
        addConfigListItem(i, params[i]);
    }
    qint32 table_width = 18;
    for (qint32 i = 0; i < ui->configTableWidget->columnCount(); i++)
    {
        table_width += ui->configTableWidget->columnWidth(i);
    }
    ui->configTableWidget->resize(table_width, ui->configTableWidget->height());
    this->resize(table_width + 20, this->height());
}

void DAQConfigDialog::addConfigListItem(qint32 line, const QString &name)
{
    DAQConfigListItem *item = new DAQConfigListItem(name);
    ui->configTableWidget->setItem(line, 0, new QTableWidgetItem(item->getLabel()->text()));
    ui->configTableWidget->setCellWidget(line, 1, item->getDevices());
    ui->configTableWidget->setCellWidget(line, 2, item->getChannels());
    ui->configTableWidget->setCellWidget(line, 3, item->getRanges());
    ui->configTableWidget->resizeRowsToContents();
    ui->configTableWidget->resizeColumnsToContents();
}

void DAQConfigDialog::OKPushButtonPressed()
{
    this->accept();
}

void DAQConfigDialog::cancelPushButtonPressed()
{
    this->reject();
}

void DAQConfigDialog::updateConfig(QMap<QString, ConfigureParameter> &sources)
{
    for (qint32 i = 0; i < ui->configTableWidget->rowCount(); i++)
    {
        QString name = ui->configTableWidget->item(i, 0)->text();
        std::wstring description = dynamic_cast<QComboBox*>(ui->configTableWidget->cellWidget(i, 1))->currentText().toStdWString();
        Automation::BDaq::DeviceInformation selected(description.c_str());
        Automation::BDaq::InstantAiCtrl *instantAiCtrl = Automation::BDaq::InstantAiCtrl::Create();
        instantAiCtrl->setSelectedDevice(selected);
        qint32 channel = dynamic_cast<QComboBox*>(ui->configTableWidget->cellWidget(i, 2))->currentText().toInt();
        Automation::BDaq::Array<Automation::BDaq::ValueRange> *valueRanges = instantAiCtrl->getFeatures()->getValueRanges();
        Automation::BDaq::ValueRange valueRange = valueRanges->getItem(dynamic_cast<QComboBox*>(ui->configTableWidget->cellWidget(i, 2))->currentIndex());
        sources[name].instantAiCtrl = instantAiCtrl;
        sources[name].channel = channel;
        sources[name].valueRange = valueRange;
    }
}
