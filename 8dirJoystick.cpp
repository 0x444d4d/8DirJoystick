#include "8dirJoystick.h"

DirJoystick::DirJoystick(int x_axis, int y_axis, short dead_zone_pct) {
	pinMode(x_axis, INPUT);
	pinMode(y_axis, INPUT);
	xAxisPin = x_axis;
	yAxisPin = y_axis;
	_deadZone = ((DirAnalogRes >> 1) * (dead_zone_pct >> 1)) / 100;
}

unsigned char DirJoystick::readJoystickDirection() {
	int x_axis = analogRead(xAxisPin);	
	int y_axis = analogRead(yAxisPin);	

	centerValues(x_axis, y_axis);
	applyDeadZone(x_axis, y_axis);
	if (x_axis == 0 && y_axis == 0) {
		return DirNoDirection;
	}
	double angle = toDegrees(x_axis, y_axis);
	return direction[(unsigned short)(angle / 45)];
}


DirPair DirJoystick::readJoystick() {
	DirPair coordinates;
	int xAxis = analogRead(xAxisPin);
	int yAxis = analogRead(yAxisPin);

	centerValues(xAxis, yAxis);
	applyDeadZone(xAxis, yAxis);

	coordinates.xAxis = xAxis;
	coordinates.yAxis = yAxis;
	return coordinates;
}

void DirJoystick::applyDeadZone(int& xAxis, int& yAxis) {
	xAxis = abs(xAxis) > _deadZone ? xAxis : 0;
	yAxis = abs(yAxis) > _deadZone ? yAxis : 0;
}

void DirJoystick::centerValues(int& xAxis, int& yAxis) {
	xAxis = xAxis - (DirAnalogRes >> 1);
	yAxis = yAxis - (DirAnalogRes >> 1);
}

unsigned DirJoystick::toDegrees(int& xAxis, int& yAxis) {
	double angle = atan2(yAxis, xAxis) * 57.29578;
	angle += 25; //align the beggining of the first sector(-25º) with 0º
	if (angle < 0) {
		angle += 360;
	}
	return angle;
}
