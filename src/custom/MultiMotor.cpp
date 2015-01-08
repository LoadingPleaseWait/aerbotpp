#include "MultiMotor.h"

MultiMotor::MultiMotor(SpeedController** speedControllers, int length){
	motors = speedControllers;
	motorCount = length;
}

MultiMotor::~MultiMotor(){
	Free();
}

void MultiMotor::PIDWrite(float output){

}

void MultiMotor::Disable(){
	// disable motors
	for(int i = 0; i < motorCount; i++){
		motors[i]->disable();
	}
}

float MultiMotor::Get(){
	// motors should be going same speed so just return speed of first motor
	return motors[0]->Get();
}

void MultiMotor::Set(float speed){
	for(int i = 0; i < motorsCount; i++){
		motors[i]->Set(speed)
	}
}

void MultiMotor::Set(float speed, uint8_t syncGroup){
	Set(speed);
}

void MultiMotor::Free(){
	for(int i = 0; i < motorsCount; i++){
		delete motors[i];
	}
	delete[] motors;
}
