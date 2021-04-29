#include "devices/sourcetronic_st2819a.h"
#include <math.h>
const QMap<QString, DeviceParameterConstraint> SourceTronic_ST2819A::_deviceParamMap = {
	{"C,x",DeviceParameterConstraint("C,x", 0.0, 0.0, READONLY)},
	{"I",DeviceParameterConstraint("I", 0.0, 0.0, READONLY)},
	{"F",DeviceParameterConstraint("F", 0.0, 0.0, READWRITE)}
};

SourceTronic_ST2819A::SourceTronic_ST2819A(QString _interfaceName, quint32 _baudRate, QWidget* parent)
	: ScpiDevice(_interfaceName, _baudRate, parent) {
	init();
}

const QMap<QString, DeviceParameterConstraint> SourceTronic_ST2819A::getDeviceParameterConstraints()const {
	return _deviceParamMap;
}

const QString SourceTronic_ST2819A::getInterfaceName()const {
	return interfaceName;
}
void SourceTronic_ST2819A::init() {
	MeasurementDevice::init(_deviceName, interfaceName, _deviceParamMap);
	// initialize scpiCommand("...");
}

void SourceTronic_ST2819A::setOutputState(bool on) {
	if (!_outputOn && on) {
		emit scpiCommand("OUT1");
	}
	if (_outputOn && !on) {
		emit scpiCommand("OUT0");
	}
}

QString SourceTronic_ST2819A::translateMeas(QString paramName) {
	QString scpiCommandString = "";
	if (paramName == "C,x") {
		//scpiCommandString = "FUNC:IMP CPQ";
	   // scpiCommandString = "*TRG";
		scpiCommandString = "*TRG";
	}
	if (paramName == "Q") {
		scpiCommandString = "CURR?";
	}
	if (paramName == "F") {
		scpiCommandString = "FREQ?";//should display values on screen, propably will not send to Terminal
	}
	return scpiCommandString;
}
QString SourceTronic_ST2819A::translateSet(QString paramName, double paramValue) {
	QString scpiCommandString = "";
	if (paramName == "C") {
		scpiCommandString = "VOLT ";
	}
	if (paramName == "I") {
		scpiCommandString = "CURR ";
	}
	if (paramName == "F") {
		scpiCommandString = "FREQ ";
	}

	return scpiCommandString;
}


double SourceTronic_ST2819A::translateInc(QString receivedString) {
	QString message = receivedString;
	//message.chop(0); // chop 2: the '\r' and the measurement unit
	//bool ok = false;
	QStringList wert1 = message.split(",");
	double val = wert1[0].toDouble();//toDouble(&ok);
	//double val1 = wert1[1].toDouble();
	//double val2 = wert1[2].toDouble();
	//if (!ok){
	//    return NAN;
	//}
	return val;
}
double SourceTronic_ST2819A::translateInc1(QString receivedString) {
	QString message = receivedString;
	//message.chop(0); // chop 2: the '\r' and the measurement unit
	//bool ok = false;
	QStringList wert1 = message.split(",");
	int x = wert1.size();

	if (wert1.size() > 1)
		//if (wert1[1]!=0)
	{
		double val1 = wert1[1].toDouble();
		return val1;
	}
	else {//double val1=0.0;
		double val1 = wert1[0].toDouble();
		return val1;
	}
	//double val = wert1[0].toDouble();//toDouble(&ok);

	//double val2 = wert1[2].toDouble();
   // qDebug()<<"TEST1"<<wert1<<val1;//<<val2;

	//if (!ok){
	//    return NAN;
	//}
	//return val1;
}
