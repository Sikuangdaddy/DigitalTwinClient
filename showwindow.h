#ifndef SHOWWINDOW_H
#define SHOWWINDOW_H

#include <QWidget>

namespace Ui {
class ShowWindow;
}

class ShowWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ShowWindow(QWidget *parent = nullptr);
    ~ShowWindow();

public slots:
    void updateData(QJsonObject *json);

private:
    Ui::ShowWindow *ui;
};

#endif // SHOWWINDOW_H
