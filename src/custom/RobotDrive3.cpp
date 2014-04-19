#include "RobotDrive3.h"

#include <SpeedController.h>


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

void RobotDrive3::MecanumDrive(double yMovement, double xMovement, double rotation){
	double frontLeftMotorSpeed, rearLeftMotorSpeed, frontRightMotorSpeed, rearRightMotorSpeed;

	rotation = rotation * rotation * rotation;//cubed rotation

	//positive xMovement results in movement to the left and vise versa
	frontLeftMotorSpeed = rearRightMotorSpeed = -xMovement;
	frontRightMotorSpeed = rearLeftMotorSpeed = xMovement;

	//forward and back movement
	frontLeftMotorSpeed += yMovement;
	frontRightMotorSpeed += yMovement;
	rearLeftMotorSpeed += yMovement;
	rearRightMotorSpeed += yMovement;

	// positive rotation results in turn to the left
	frontLeftMotorSpeed -= rotation;
	rearLeftMotorSpeed -= rotation;
	frontRightMotorSpeed += rotation;
	rearRightMotorSpeed += rotation;

	//make sure motor speeds are not above 1 or below -1
	frontLeftMotorSpeed = Limit(frontLeftMotorSpeed);
	frontRightMotorSpeed = Limit(frontRightMotorSpeed);
	rearLeftMotorSpeed = Limit(rearLeftMotorSpeed);
	rearRightMotorSpeed = Limit(rearRightMotorSpeed);

	m_frontLeftMotor->Set(frontLeftMotorSpeed);
	m_frontRightMotor->Set(frontRightMotorSpeed);
	m_rearLeftMotor->Set(rearLeftMotorSpeed);
	m_rearRightMotor->Set(rearRightMotorSpeed);
}

double max(double number1, double number2){
	return number1 > number2 ? number1 : number2;
}

double min(double number1, double number2){
	return number1 < number2 ? number1 : number2;
}

