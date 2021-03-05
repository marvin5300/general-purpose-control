class Keithley_2410 : public ScpiDevice
{
    Q_OBJECT

public:
    explicit Keithley_2410(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = 0);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}
public slots:
    //void onReceivedMessage(QString message);
private:
    void init();
    const QString _deviceName = "MODEL 2410";
    static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;
    QMap<QString, DeviceParameterConstraint> deviceParamMap(){return _deviceParamMap;}
    QMap<QString, MeasurementValue> valuesMap;
    QString translateMeas(QString paramName);
};
