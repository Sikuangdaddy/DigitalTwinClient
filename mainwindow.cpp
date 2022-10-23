#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , proxy(new NetworkProxy)
    , device("inlet-pipe")
    , data(new InletPipe)
{
    connect(proxy, &NetworkProxy::get_finished, this, &MainWindow::get_data_back);

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
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
    //hover功能
    ui->testwidget1->setDataType(ToolTipWidget::DYNAMIC_PRESSURE);
    ui->testwidget1->setData(json->value("dynamicPressure1").toDouble());
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

