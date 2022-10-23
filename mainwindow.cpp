#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , showWindow(new ShowWindow)
    , ui(new Ui::MainWindow)
    , proxy(new NetworkProxy)
    , device("inlet-pipe")
    , data(new InletPipe)
{
    connect(proxy, &NetworkProxy::get_finished, this, &MainWindow::get_data_back);
    connect(this, &MainWindow::updateData, showWindow, &ShowWindow::updateData);
    showWindow->show();
    ui->setupUi(this);
    initToolTipWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete showWindow;
}

void MainWindow::get_data(const QString &type)
{
    proxy->get_data(device, type);
}

void MainWindow::post_data(const QString &type)
{
    proxy->post_data(device, type, data->toJson());
}

void MainWindow::get_data_back(QJsonObject *json)
{
    *data = InletPipe::fromJson(*json);
    ui->listWidget->clear();
    ui->listWidget->addItems(data->toQStringList());
    emit updateData(json);
    //hover功能
    ui->temp1->setData(json->value("temperature1").toDouble());
    ui->temp2->setData(json->value("temperature1").toDouble());
    ui->temp3->setData(json->value("temperature1").toDouble());
    ui->temp4->setData(json->value("temperature1").toDouble());
    ui->temp5->setData(json->value("temperature1").toDouble());
    ui->temp6->setData(json->value("temperature1").toDouble());
    ui->temp7->setData(json->value("temperature1").toDouble());
    ui->temp8->setData(json->value("temperature1").toDouble());
    ui->temp9->setData(json->value("temperature1").toDouble());
    ui->temp10->setData(json->value("temperature1").toDouble());
    ui->stapre1->setData(json->value("staticPressure1").toDouble());
    ui->stapre2->setData(json->value("staticPressure1").toDouble());
    ui->stapre3->setData(json->value("staticPressure1").toDouble());
    ui->stapre4->setData(json->value("staticPressure1").toDouble());
    ui->stapre5->setData(json->value("staticPressure1").toDouble());
    ui->stapre6->setData(json->value("staticPressure1").toDouble());
    ui->stapre7->setData(json->value("staticPressure1").toDouble());
    ui->stapre8->setData(json->value("staticPressure1").toDouble());
    ui->stapre9->setData(json->value("staticPressure1").toDouble());
    ui->stapre10->setData(json->value("staticPressure1").toDouble());
    ui->stapre11->setData(json->value("staticPressure1").toDouble());
    ui->stapre12->setData(json->value("staticPressure1").toDouble());
    ui->dynapre1->setData(json->value("dynamicPressure").toDouble());
    ui->dynapre2->setData(json->value("dynamicPressure").toDouble());
}

void MainWindow::post_data_back(QJsonObject *json)
{
    Q_UNUSED(json);
    Q_UNIMPLEMENTED();
}

void MainWindow::on_inlet_pipe_clicked()
{
    device = "inlet-pipe";
    delete data;
    data = new InletPipe;
}

void MainWindow::on_showButton_clicked()
{

}

void MainWindow::on_uploadButton_clicked()
{
    if (device == "inlet-pipe") {
        *data = InletPipe::fromRandom();
        post_data("add");
    }
}

void MainWindow::initToolTipWidget()
{
    ui->temp1->setDataType(ToolTipWidget::TEMPERATURE);
    ui->temp2->setDataType(ToolTipWidget::TEMPERATURE);
    ui->temp3->setDataType(ToolTipWidget::TEMPERATURE);
    ui->temp4->setDataType(ToolTipWidget::TEMPERATURE);
    ui->temp5->setDataType(ToolTipWidget::TEMPERATURE);
    ui->temp6->setDataType(ToolTipWidget::TEMPERATURE);
    ui->temp7->setDataType(ToolTipWidget::TEMPERATURE);
    ui->temp8->setDataType(ToolTipWidget::TEMPERATURE);
    ui->temp9->setDataType(ToolTipWidget::TEMPERATURE);
    ui->temp10->setDataType(ToolTipWidget::TEMPERATURE);

    ui->stapre1->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->stapre2->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->stapre3->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->stapre4->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->stapre5->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->stapre6->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->stapre7->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->stapre8->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->stapre9->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->stapre10->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->stapre11->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->stapre12->setDataType(ToolTipWidget::STATIC_PRESSURE);
    ui->dynapre1->setDataType(ToolTipWidget::DYNAMIC_PRESSURE);
    ui->dynapre2->setDataType(ToolTipWidget::DYNAMIC_PRESSURE);

}
