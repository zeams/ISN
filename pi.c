#include"pi.h"
#if JOYSTICK
	void initPin(void)
	{
		wiringPiSetup();
		pinMode(PIN_H1,INPUT);
		pinMode(PIN_B1,INPUT);
		pinMode(PIN_S1,INPUT);
		pinMode(PIN_H2,INPUT);
		pinMode(PIN_B2,INPUT);
		pinMode(PIN_S2,INPUT);
	}
#endif
