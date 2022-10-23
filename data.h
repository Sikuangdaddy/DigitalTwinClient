#pragma once

#ifndef DATA_H
#define DATA_H

#include <QJsonObject>
#include <QStringList>

class Data
{
public:
    Data() = default;
    virtual QJsonObject toJson() const = 0;
    virtual QStringList toQStringList() const = 0;
};

#endif // DATA_H
