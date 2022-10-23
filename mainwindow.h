#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "networkproxy.h"
#include "inletpipe.h"
#include "tooltipwidget.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void get_data(const QString &type);
    void post_data(const QString &type);
    void get_data_back(QJsonObject *json);
    void post_data_back(QJsonObject *json);

private slots:
    void on_inlet_pipe_clicked();
    void on_showButton_clicked();

    void on_uploadButton_clicked();

private:
    Ui::MainWindow *ui;
    NetworkProxy *proxy;
    QString device;
    Data *data;
    ToolTipWidget *test;
};
#endif // MAINWINDOW_H
