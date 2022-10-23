#include "inletpipe.h"
#include <QString>
#include <QRandomGenerator>
#include <QDateTime>

InletPipe InletPipe::fromJson(const QJsonObject &json)
{
    InletPipe inletPipe;
    inletPipe.id = json.value("id").toInt();
    inletPipe.static_pressure_1 = json.value("staticPressure1").toDouble();
    inletPipe.static_pressure_2 = json.value("staticPressure2").toDouble();
    inletPipe.static_pressure_3 = json.value("staticPressure3").toDouble();
    inletPipe.static_pressure_4 = json.value("staticPressure4").toDouble();
    inletPipe.static_pressure_5 = json.value("staticPressure5").toDouble();
    inletPipe.static_pressure_6 = json.value("staticPressure6").toDouble();
    inletPipe.dynamic_pressure = json.value("dynamicPressure").toDouble();
    inletPipe.temperature_1 = json.value("temperature1").toDouble();
    inletPipe.temperature_2 = json.value("temperature2").toDouble();
    inletPipe.temperature_3 = json.value("temperature3").toDouble();
    inletPipe.air_flow_meter = json.value("airFlowMeter").toDouble();
    inletPipe.time_stamp = json.value("timeStamp").toString();
    return inletPipe;
}

InletPipe InletPipe::fromRandom()
{
    InletPipe inletPipe;
    inletPipe.id = QRandomGenerator::global()->bounded(100);
    inletPipe.static_pressure_1 = QRandomGenerator::global()->bounded(1.0);;
    inletPipe.static_pressure_2 = QRandomGenerator::global()->bounded(1.0);
    inletPipe.static_pressure_3 = QRandomGenerator::global()->bounded(1.0);
    inletPipe.static_pressure_4 = QRandomGenerator::global()->bounded(1.0);
    inletPipe.static_pressure_5 = QRandomGenerator::global()->bounded(1.0);
    inletPipe.static_pressure_6 = QRandomGenerator::global()->bounded(1.0);
    inletPipe.dynamic_pressure = QRandomGenerator::global()->bounded(1.0);
    inletPipe.temperature_1 = QRandomGenerator::global()->bounded(1.0);
    inletPipe.temperature_2 = QRandomGenerator::global()->bounded(1.0);
    inletPipe.temperature_3 = QRandomGenerator::global()->bounded(1.0);
    inletPipe.air_flow_meter = QRandomGenerator::global()->bounded(1.0);
    inletPipe.time_stamp = QDateTime::currentDateTime().toString();
    return inletPipe;
}

QJsonObject InletPipe::toJson() const
{
    QJsonObject json;
    json.insert("id", id);
    json.insert("staticPressure1", static_pressure_1);
    json.insert("staticPressure2", static_pressure_2);
    json.insert("staticPressure3", static_pressure_3);
    json.insert("staticPressure4", static_pressure_4);
    json.insert("staticPressure5", static_pressure_5);
    json.insert("staticPressure6", static_pressure_6);
    json.insert("dynamicPressure", dynamic_pressure);
    json.insert("temperature1", temperature_1);
    json.insert("temperature2", temperature_2);
    json.insert("temperature3", temperature_3);
    json.insert("airFlowMeter", air_flow_meter);
    json.insert("timeStamp", time_stamp);
    return json;
}

QStringList InletPipe::toQStringList() const
{
    QStringList list;
    list << "id: " + QString::number(id);
    list << "staticPressure1: " + QString::number(static_pressure_1);
    list << "staticPressure2: " + QString::number(static_pressure_2);
    list << "staticPressure3: " + QString::number(static_pressure_3);
    list << "staticPressure4: " + QString::number(static_pressure_4);
    list << "staticPressure5: " + QString::number(static_pressure_5);
    list << "staticPressure6: " + QString::number(static_pressure_6);
    list << "dynamicPressure: " + QString::number(dynamic_pressure);
    list << "temperature1: " + QString::number(temperature_1);
    list << "temperature2: " + QString::number(temperature_2);
    list << "temperature3: " + QString::number(temperature_3);
    list << "airFlowMeter: " + QString::number(air_flow_meter);
    list << "timeStamp: " + time_stamp;
    return list;
}
