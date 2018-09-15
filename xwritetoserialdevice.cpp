#include "xwritetoserialdevice.h"

XWriteToSerialDevice::XWriteToSerialDevice()
{
}

bool XWriteToSerialDevice::writeData(int pValue)
{

    qDebug() <<"isConnected: " <<isConnected();
    QByteArray tWriteData = QByteArray::number(pValue);

    const qint64 bytesWritten = mSerialDevice.write(tWriteData);
    if (bytesWritten == -1)
    {
        qDebug() << "Failed to write all the data to: "<<mSerialPortName;
        return false;
    }
    else if (bytesWritten != tWriteData.size())
    {
        qDebug() << "Failed to write all the data to: "<<mSerialPortName;
        return false;
    }
    else if (!mSerialDevice.waitForBytesWritten(5000))
    {
        qDebug() << "Operation Timed Out !";
        return false;
    }
    qDebug() << "Data successfully sent to port: "<<mSerialPortName;
    return true;
}

bool XWriteToSerialDevice::isConnected() const
{
    return mSerialDevice.isOpen();
}

void XWriteToSerialDevice::closeCurrentConnection()
{
    mSerialDevice.close();
    qDebug() << "Closed current connection";
}

bool XWriteToSerialDevice::startNewConnection(QString pSerialPortName, QSerialPort::BaudRate pBaudRate, QSerialPort::DataBits pDataBits,
                                              QSerialPort::Parity pParity, QSerialPort::StopBits pStopBits, QSerialPort::FlowControl pFlowControl)
{
    mSerialPortName = pSerialPortName;
    mSerialDevice.setPortName(mSerialPortName);
    const int tSerialPortBaudRate = pBaudRate;
    mSerialDevice.setBaudRate(tSerialPortBaudRate);
    mSerialDevice.setDataBits(pDataBits);
    mSerialDevice.setParity(pParity);
    mSerialDevice.setStopBits(pStopBits);
    mSerialDevice.setFlowControl(pFlowControl);

    //Connect Device
    mConnectionStatus = mSerialDevice.open(QIODevice::WriteOnly);
    if(!mConnectionStatus)
    {
        qDebug() << "Connection to: "<<mSerialPortName << " failed!";
        return false;
    }
    qDebug() << "Connected to: "<<mSerialPortName;
    return true;
}
