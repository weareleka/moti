#define serial Serial

#include <Arduino.h>
#include "ChibiOS_AVR.h"
#include "Serial.h"

#include "Led.h"

Led heart = Led(11, 12, 13);

static WORKING_AREA(waHeartThread, 1000);

static msg_t HeartThread(void *arg) {

	(void)arg;

	volatile uint8_t basePwm = 10; // divided by ten to have a wait delay higher than 1ms
	volatile uint8_t bpm = 30;     // must multiply by ten in heart.shine();
	volatile uint8_t P = 80;
	volatile uint8_t Q = 0;
	volatile uint8_t R = 255;
	// volatile uint16_t waitDelay = 0;
	// volatile uint8_t i = 0;

	while (TRUE) {

		heart.shine(basePwm, 0, 0);
		chThdSleepMilliseconds(40/2);
		heart.shine(P/2, 0, 0);
		chThdSleepMilliseconds(40/2);
		heart.shine(P, 0, 0);
		chThdSleepMilliseconds(40/2);
		heart.shine(P/2, 0, 0);
		chThdSleepMilliseconds(40/2);

		heart.shine(basePwm, 0, 0);
		chThdSleepMilliseconds(60);

		heart.shine(basePwm, 0, 0);
		chThdSleepMilliseconds(30/2);
		heart.shine(Q/2, 0, 0);
		chThdSleepMilliseconds(30/2);
		heart.shine(Q, 0, 0);
		chThdSleepMilliseconds(30/2);
		heart.shine(R/2, 0, 0);
		chThdSleepMilliseconds(30/2);
		heart.shine(R, 0, 0);
		chThdSleepMilliseconds(30/2);
		heart.shine(Q/2, 0, 0);
		chThdSleepMilliseconds(30/2);
		heart.shine(Q, 0, 0);
		chThdSleepMilliseconds(20);

		heart.shine(basePwm, 0, 0);

		chThdSleepMilliseconds(30000/ bpm);
	}
	return 0;
}

void chSetup() {
	chThdCreateStatic(waHeartThread, sizeof(waHeartThread),
		NORMALPRIO, HeartThread, NULL);
}


void setup() {
	serial.begin(115200);
	chBegin(chSetup);
	while(1) {
	}
}

void loop() {
	// nothing to do here
}