#include "RobotDrive3.h"

RobotDrive3::RobotDrive3(int leftMotorChannel, int rightMotorChannel) : RobotDrive(leftMotorChannel, rightMotorChannel) {

}

RobotDrive3::~RobotDrive3() {

}

void RobotDrive3::ArcadeDrive(double moveValue,double rotateValue){
	double leftMotorSpeed,rightMotorSpeed;

	//prevent motor values from being over 1 or under -1
	moveValue = Limit(moveValue);
	rotateValue = Limit(rotateValue);

	//cubed rotation
	rotateValue *= rotateValue * rotateValue;

	//set left and right motor speed variables
	if(moveValue > 0){
		if(rotateValue > 0){
			leftMotorSpeed = moveValue - rotateValue;
			rightMotorSpeed = max(rotateValue,moveValue);
		}else{
			rightMotorSpeed = moveValue + rotateValue;
			leftMotorSpeed = max(-rotateValue, moveValue);
		}
	}else{
		if(rotateValue > 0){
			leftMotorSpeed = min(moveValue, -rotateValue);
			rightMotorSpeed = moveValue + rotateValue;
		}else{
			rightMotorSpeed = min(moveValue, rotateValue);
			leftMotorSpeed = moveValue - rotateValue;
		}
	}

	SetLeftRightMotorOutputs(leftMotorSpeed,rightMotorSpeed);
}

double max(double number1, double number2){
	return number1 > number2 ? number1 : number2;
}

double min(double number1, double number2){
	return number1 < number2 ? number1 : number2;
}

