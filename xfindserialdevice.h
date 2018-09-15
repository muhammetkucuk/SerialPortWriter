#ifndef XFINDSERIALDEVICE_H
#define XFINDSERIALDEVICE_H
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QStringList>
#include <QDebug>


class XFindSerialDevice
{
public:
    XFindSerialDevice();
    QStringList getSerialPortSystemLocation() const;
    QStringList getSerialPortName() const;
    QList<QSerialPortInfo> getSerialPortInfos() const;
private:
    QList<QSerialPortInfo> mSerialPortInfos;
    QStringList mSerialPortSystemLocation;
    QStringList mSerialPortName;
};

#endif // XFINDSERIALDEVICE_H
