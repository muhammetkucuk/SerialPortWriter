#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <xwritetoserialdevice.h>
#include <xfindserialdevice.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_dataScrool_valueChanged(int value);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_baudRateComboBox_currentIndexChanged(int index);

    void on_dataBitsComboBox_currentIndexChanged(int index);

    void on_parityComboBox_currentIndexChanged(int index);

    void on_stopBitsComboBox_currentIndexChanged(int index);

    void on_flowControlComboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    XFindSerialDevice *mSerialDeviceInformations;
    XWriteToSerialDevice *mSerialDeviceOperator;
    QString mCurrentPortName;

    QSerialPort::DataBits mCurrentDataBits;
    QSerialPort::BaudRate mCurrentBaudRate;
    QSerialPort::Parity mCurenntParity;
    QSerialPort::StopBits mCurrentStopBits;
    QSerialPort::FlowControl mCurrentFlowControl;
    void displayAvaibleDevicesInComboBox();
    void makeConnecttion();
};

#endif // MAINWINDOW_H
