/*
 * Aerbot.cpp
 *
 *  Created on: Apr 8, 2014
 *      Author: MurpheyA
 */

#include "Aerbot.h"

Aerbot::Aerbot() {

}

Aerbot::~Aerbot() {
	delete environment;
	delete execurer;
}

void Aerbot::RobotInit(){
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

