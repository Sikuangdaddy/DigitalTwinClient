#include "showwindow.h"
#include "ui_showwindow.h"

ShowWindow::ShowWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowWindow)
{
    ui->setupUi(this);
    ui->arraylabl1->setAttribute(Qt::WA_TranslucentBackground);
    ui->arraylabl2->setAttribute(Qt::WA_TranslucentBackground);
    ui->arraylabl3->setAttribute(Qt::WA_TranslucentBackground);
    ui->arraylabl4->setAttribute(Qt::WA_TranslucentBackground);
    ui->arraylabl5->setAttribute(Qt::WA_TranslucentBackground);
    ui->arraylabl6->setAttribute(Qt::WA_TranslucentBackground);
    ui->arraylabl7->setAttribute(Qt::WA_TranslucentBackground);

}

ShowWindow::~ShowWindow()
{
    delete ui;
}

void ShowWindow::updateData(QJsonObject *json)
{
    233;
}
