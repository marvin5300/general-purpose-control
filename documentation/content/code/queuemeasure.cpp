void ScpiDevice::queueMeasure(quint64 number) {
    measureID = number;
    activeMeasParams.clear();
    for (int i = 0; i < ui->parameterTableWidget->rowCount(); i++) {
        auto item = ui->parameterTableWidget->item(i, 0);
        if (item->checkState()) {
            activeMeasParams.append(item->text());
        }
    }
    if (activeMeasParams.size() == 0) {
        emit measureReady(deviceName(), measureID);
    }
    if (!correctDeviceConnected) {
        return;
    }
    for (int i = 0; i < activeMeasParams.size(); i++) {
        emit scpiCommand(translateMeas(activeMeasParams.at(i)));
    }
}