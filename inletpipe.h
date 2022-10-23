#pragma once

#ifndef INLETPIPE_H
#define INLETPIPE_H

#include "data.h"

class InletPipe: public Data
{
private:
    int id;
    double static_pressure_1;
    double static_pressure_2;
    double static_pressure_3;
    double static_pressure_4;
    double static_pressure_5;
    double static_pressure_6;
    double dynamic_pressure;
    double temperature_1;
    double temperature_2;
    double temperature_3;
    double air_flow_meter;
    QString time_stamp;
public:
    InletPipe() = default;
    static InletPipe fromJson(const QJsonObject &json);
    static InletPipe fromRandom();
    QJsonObject toJson() const override;
    QStringList toQStringList() const override;
};

#endif // INLETPIPE_H
