#ifndef TOOLTIPWIDGET_H
#define TOOLTIPWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QEnterEvent>

class ToolTipWidget : public QWidget
{
    Q_OBJECT
public:
    typedef enum {
        NOTYPE,
        TEMPERATURE,
        STATIC_PRESSURE,
        DYNAMIC_PRESSURE
    } dataTypeT;
private:
    bool isHover;
    dataTypeT dataType;
    double data;
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void enterEvent(QEnterEvent *event) Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *event) Q_DECL_OVERRIDE;
public:
    explicit ToolTipWidget(QWidget *parent = nullptr, dataTypeT dataType = NOTYPE);
    dataTypeT getDataType() const;
    void setDataType(dataTypeT dataType);
    double getData() const;
    void setData(double data);
};

#endif // TOOLTIPWIDGET_H
