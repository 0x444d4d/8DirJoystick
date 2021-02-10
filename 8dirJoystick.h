/*
  dirJoystick - Library for reading joysticks as d-pads.
  Created by David Martín Martín, February 10, 2021.
	TODO:license
*/

#ifndef _dirJoystick_h
#define _dirJoystick_h

#if ARDUINO >= 100
#include <Arduino.h>
#include "Print.h"
#else
#include "WProgram"
#endif

#include <math.h>

#define DirNoDirection  0x00
#define DirE  0x01
#define DirNE  0x02
#define DirN  0x03
#define DirNW  0x04
#define DirW  0x05
#define DirSW  0x06
#define DirS  0x07
#define DirSE  0x08
#define DirAnalogRes  1024
typedef struct DirPair {
	int xAxis;
	int yAxis;
} DirPair;

class DirJoystick {
	public:
		DirJoystick() {}
		DirJoystick(int x_axis, int y_axis, short dead_zone_pct = 5);
		~DirJoystick() {};

		unsigned char readJoystickDirection();
		DirPair readJoystick();

	private:
		void applyDeadZone(int& xAxis, int& yAxis);
		void centerValues(int& xAxis, int& yAxis);
	 	unsigned toDegrees(int& xAxis, int& yAxis);

		unsigned char _deadZone;
		unsigned char xAxisPin;
		unsigned char yAxisPin;
		unsigned char direction[9] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

};

#endif
