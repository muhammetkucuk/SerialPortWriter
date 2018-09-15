#ifndef XWRITETOSERIALDEVICE_H
#define XWRITETOSERIALDEVICE_H
#include <QDir>
#include <QFile>
#include <QSerialPort>
#include <QStringList>
#include <QDebug>
class XWriteToSerialDevice
{
public:
    XWriteToSerialDevice();
    bool writeData(int pValue);
    bool isConnected() const;

    void closeCurrentConnection();
    bool startNewConnection(QString pSerialPortName, QSerialPort::BaudRate pBaudRate, QSerialPort::DataBits pDataBits,
                            QSerialPort::Parity pParity, QSerialPort::StopBits pStopBits, QSerialPort::FlowControl pFlowControl);
private:
    QSerialPort mSerialDevice;
    QString mSerialPortName;
    bool mConnectionStatus;
};

#endif // XWRITETOSERIALDEVICE_H
