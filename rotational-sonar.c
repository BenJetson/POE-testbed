#pragma config(Sensor, in1,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in2,    light,          sensorReflection)
#pragma config(Sensor, in3,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, dgtl1,  sonar,          sensorSONAR_inch)
#pragma config(Sensor, dgtl3,  encoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  bump,           sensorTouch)
#pragma config(Sensor, dgtl6,  limit,          sensorTouch)
#pragma config(Sensor, dgtl11, led,            sensorLEDtoVCC)
#pragma config(Motor,  port1,           flashlight,    tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           rMotor,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           servo,         tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           lMotor,        tmotorVex269_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){



	while (true) {
		if (SensorValue[sonar] > 8) {
			motor[flashlight] = 0;
			SensorValue[led] = 0;

			if (SensorValue[bump] == 1 && SensorValue[limit] != 1) {
				motor[rMotor] = -127;
				motor[lMotor] = 127;
			} else if (SensorValue[bump] != 1 && SensorValue[limit] == 1) {
				motor[rMotor] = 127;
				motor[lMotor] = -127;
			} else if (SensorValue[bump] == 1 && SensorValue[limit] == 1) {
				motor[rMotor] = -127;
				motor[lMotor] = -127;
			} else {
				motor[rMotor] = 127;
				motor[lMotor] = 127;
			}
		} else {
			motor[flashlight] = 127;
			SensorValue[led] = 1;
		}
	}
}