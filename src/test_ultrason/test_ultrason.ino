//######################################################################//
//	MOTI SOFTWARE v2.0													//
//	COPYRIGHT WE ARE LEKA! - SOURCE CODE DISTRIBUTED UNDER MIT LICENCE	//
//######################################################################//


//###########//
// LIBRARIES //
//###########//

#include "Arduino.h"

#include "Moti.h"

#include "RGBLED.h"

#include <Wire.h>

#include <CommunicationUtils.h>
#include <DebugUtils.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>
#include <FreeSixIMU.h>

MOTI Moti = MOTI();


//#######//
// SETUP //
//#######//


void ultrasonDetection () {}

void ultrasonMap () {}

void ultrasonSettings () {}


void setup() {
	Moti.initVerbose();
}



//######//
// LOOP //
//######//

void loop() {


}

