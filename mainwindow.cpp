#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Get Avaible Devices
    mSerialDeviceInformations = new XFindSerialDevice ;
    mSerialDeviceOperator = new XWriteToSerialDevice;
    //Default Parameters
    mCurrentBaudRate = QSerialPort::Baud9600;
    mCurrentDataBits = QSerialPort::Data8;
    mCurenntParity = QSerialPort::NoParity;
    mCurrentStopBits = QSerialPort::OneStop;
    mCurrentFlowControl = QSerialPort::NoFlowControl;
    //Default Actives
    ui->baudRateComboBox->setCurrentIndex(3);
    ui->dataBitsComboBox->setCurrentIndex(3);
    ui->parityComboBox->setCurrentIndex(0);
    ui->stopBitsComboBox->setCurrentIndex(0);
    ui->flowControlComboBox->setCurrentIndex(0);
    //Make Connection to 1st Device as Default
    displayAvaibleDevicesInComboBox();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dataScrool_valueChanged(int value)
{
    ui->lcdNumber->display(value);
    if(!mSerialDeviceOperator->writeData(value))
        return;
    QString tStr("Data sent success: " + QString::number(value));
    ui->statusLabel->setText(tStr);
}

void MainWindow::displayAvaibleDevicesInComboBox()
{
    QStringList tSerialPortSystemLocations = mSerialDeviceInformations->getSerialPortSystemLocation();
    for(QString tSerialPortName : tSerialPortSystemLocations)
    {
        ui->comboBox->addItem(tSerialPortName);
    }
}

void MainWindow::makeConnecttion()
{
    if(mSerialDeviceOperator->isConnected())
    {
        mSerialDeviceOperator->closeCurrentConnection();
        ui->statusLabel->setText("Current Connection Closed");
    }
    int tConnectionStatus = mSerialDeviceOperator->startNewConnection(mCurrentPortName, mCurrentBaudRate, mCurrentDataBits,mCurenntParity, mCurrentStopBits, mCurrentFlowControl);
    if(tConnectionStatus)
        ui->statusLabel->setText("Connected: "+mCurrentPortName);
    else
        ui->statusLabel->setText("Failed to connect: "+mCurrentPortName);
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    mCurrentPortName = arg1;
    makeConnecttion();
}

void MainWindow::on_baudRateComboBox_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        mCurrentBaudRate = QSerialPort::Baud1200;
        break;
    case 1:
        mCurrentBaudRate = QSerialPort::Baud2400;
        break;
    case 2:
        mCurrentBaudRate = QSerialPort::Baud4800;
        break;
    case 3:
        mCurrentBaudRate = QSerialPort::Baud9600;
        break;
    case 4:
        mCurrentBaudRate = QSerialPort::Baud19200;
        break;
    case 5:
        mCurrentBaudRate = QSerialPort::Baud38400;
        break;
    case 6:
        mCurrentBaudRate = QSerialPort::Baud57600;
        break;
    case 7:
        mCurrentBaudRate = QSerialPort::Baud115200;
        break;
    default:
        break;
    }
    makeConnecttion();

}

void MainWindow::on_dataBitsComboBox_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        mCurrentDataBits = QSerialPort::Data5;
        break;
    case 1:
        mCurrentDataBits = QSerialPort::Data6;
        break;
    case 2:
        mCurrentDataBits = QSerialPort::Data7;
        break;
    case 3:
        mCurrentDataBits = QSerialPort::Data8;
        break;
    default:
        break;
    }
    makeConnecttion();
}

void MainWindow::on_parityComboBox_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        mCurenntParity = QSerialPort::NoParity;
        break;
    case 1:
        mCurenntParity = QSerialPort::EvenParity;
        break;
    case 2:
        mCurenntParity = QSerialPort::OddParity;
        break;
    case 3:
        mCurenntParity = QSerialPort::SpaceParity;
        break;
    case 4:
        mCurenntParity = QSerialPort::MarkParity;
        break;
    default:
        break;
    }
    makeConnecttion();

}

void MainWindow::on_stopBitsComboBox_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        mCurrentStopBits = QSerialPort::OneStop;
        break;
    case 1:
        mCurrentStopBits = QSerialPort::OneAndHalfStop;
        break;
    case 2:
        mCurrentStopBits = QSerialPort::TwoStop;
        break;
    default:
        break;
    }
    makeConnecttion();
}

void MainWindow::on_flowControlComboBox_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        mCurrentFlowControl = QSerialPort::NoFlowControl;
        break;
    case 1:
        mCurrentFlowControl = QSerialPort::HardwareControl;
        break;
    case 2:
        mCurrentFlowControl = QSerialPort::SoftwareControl;
        break;
    default:
        break;
    }
    makeConnecttion();
}
