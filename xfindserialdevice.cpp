#include "xfindserialdevice.h"

XFindSerialDevice::XFindSerialDevice()
{
    mSerialPortInfos = QSerialPortInfo::availablePorts();

    qDebug() << "Total number of ports available: " << mSerialPortInfos.count();

    for (const QSerialPortInfo &serialPortInfo : mSerialPortInfos)
    {
        qDebug() << "Device port name : " << serialPortInfo.portName();
        qDebug() << "Device port system location : " << serialPortInfo.systemLocation();
        if(!serialPortInfo.isBusy())
        {
            mSerialPortSystemLocation.push_back(serialPortInfo.systemLocation());
            mSerialPortName.push_back(serialPortInfo.portName());
        }
    }
}

QStringList XFindSerialDevice::getSerialPortSystemLocation() const
{
    return mSerialPortSystemLocation;
}

QStringList XFindSerialDevice::getSerialPortName() const
{
    return mSerialPortName;
}

QList<QSerialPortInfo> XFindSerialDevice::getSerialPortInfos() const
{
    return mSerialPortInfos;
}
