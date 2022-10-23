#include "tooltipwidget.h"
#include <QPainter>
#include <QPolygon>
#include <QDebug>

ToolTipWidget::ToolTipWidget(QWidget *parent, ToolTipWidget::dataTypeT dataType)
    : QWidget{parent}, isHover(false), dataType(dataType), data(0.)
{
    resize(12, 12);
    setToolTip(QString::number(data, 'g', 3));
    setMouseTracking(true);
}

void ToolTipWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    if (dataType == TEMPERATURE) {
        if (isHover) {
            painter.setBrush(Qt::cyan);
            painter.drawEllipse(1, 1, 10 ,10);
        }
        painter.setBrush(Qt::black);
        painter.drawEllipse(3, 3, 6 ,6);
    } else if (dataType == STATIC_PRESSURE) {
        QPolygon polygon;
        if (isHover) {
            painter.setBrush(Qt::cyan);
            polygon.setPoints(3, 6, 2, 1, 10, 10, 10);
            painter.drawPolygon(polygon);
        }
        painter.setBrush(Qt::black);
        polygon.setPoints(3, 6, 4, 3, 8, 8, 8);
        painter.drawPolygon(polygon);
    } else if (dataType == DYNAMIC_PRESSURE) {
        QPolygon polygon;
        if (isHover) {
            painter.setBrush(Qt::cyan);
            polygon.setPoints(3, 6, 9, 1, 1, 10, 1);
            painter.drawPolygon(polygon);
        }
        painter.setBrush(Qt::black);
        polygon.setPoints(3, 6, 7, 3, 3, 8, 3);
        painter.drawPolygon(polygon);
    }
}

void ToolTipWidget::enterEvent(QEnterEvent *event)
{
    Q_UNUSED(event);
    isHover = true;
    repaint();
}

void ToolTipWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    isHover = false;
    repaint();
}

ToolTipWidget::dataTypeT ToolTipWidget::getDataType() const
{
    return dataType;
}

void ToolTipWidget::setDataType(dataTypeT dataType)
{
    this->dataType = dataType;
}

double ToolTipWidget::getData() const
{
    return data;
}

void ToolTipWidget::setData(double data)
{
    this->data = data;
    setToolTip(QString::number(data, 'g', 3));
}
