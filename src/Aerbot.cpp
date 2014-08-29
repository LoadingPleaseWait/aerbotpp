/*
 * Aerbot.cpp
 *
 *  Created on: Apr 8, 2014
 */

#include "Aerbot.h"

Aerbot::Aerbot() {

}

Aerbot::~Aerbot() {
	delete environment;
	delete executer;
}

void Aerbot::RobotInit(){
	// initialize instance variables
	environment = new Environment(this);
	executer = new Executer(environment);
}

void Aerbot::AutonomousInit(){

}

void Aerbot::AutonomousPeriodic(){
	executer->update();
}

void Aerbot::TeleopInit(){

}

void Aerbot::TeleopPeriodic(){
	executer->update();
}

