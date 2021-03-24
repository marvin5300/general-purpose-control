class ScpiDevice : public MeasurementDevice
{
    ... 
    void onReceivedMessage(QString message);
    void queueMeasure(quint64 number) override;
    ...
}