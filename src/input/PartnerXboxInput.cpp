/*
 * PartnerXboxInput.cpp
 *
 *  Created on: Apr 9, 2014
 */

#include "PartnerXboxInput.h"

PartnerXboxInput::PartnerXboxInput() :driver(1), shooter(2) {
	//instance variables are initialized
}

PartnerXboxInput::~PartnerXboxInput() {

}

double PartnerXboxInput::getLeftX(){
	return driver.GetRawAxis(LEFT_STICK_X);
}

double PartnerXboxInput::getLeftY(){
	return driver.GetRawAxis(LEFT_STICK_Y);
}

double PartnerXboxInput::getRightX(){
	return driver.GetRawAxis(RIGHT_STICK_X);
}

double PartnerXboxInput::getRightY(){
	return driver.GetRawAxis(RIGHT_STICK_Y);
}

bool PartnerXboxInput::shift(){
	return driver.GetRawButton(BUTTON_B) || driver.GetRawButton(RIGHT_BUMPER);
}

bool PartnerXboxInput::catchBall(){
	return driver.GetRawButton(BUTTON_A);
}

bool PartnerXboxInput::shoot(){
	return shooter.GetRawButton(LEFT_BUMPER);
}

bool PartnerXboxInput::manualShoot(){
	return shooter.GetRawButton(BUTTON_Y);
}

bool PartnerXboxInput::intakeToggle(){
	return shooter.GetRawButton(RIGHT_BUMPER);
}

bool PartnerXboxInput::directionToggle(){
	 return driver.GetRawButton(BUTTON_Y) || driver.GetRawButton(RIGHT_BUMPER);
}

bool PartnerXboxInput::intake(){
	return shooter.GetRawButton(BUTTON_A);
}

bool PartnerXboxInput::outtake(){
	return shooter.GetRawButton(BUTTON_X);
}

