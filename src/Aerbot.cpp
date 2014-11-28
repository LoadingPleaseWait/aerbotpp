#include "Aerbot.h"
#include "AutonomousExecuter.h"
#include "TeleopExecuter.h"

Aerbot::Aerbot() {

}

Aerbot::~Aerbot() {
	delete environment;
	delete executer;
}

void Aerbot::RobotInit(){
	// initialize instance variables
	environment = new Environment(this);
}

void Aerbot::AutonomousInit(){
	executer = new AutonomousExecuter(environment);
}

void Aerbot::AutonomousPeriodic(){
	executer->execute();
}

void Aerbot::TeleopInit(){
	executer = new TeleopExecuter(environment);
}

void Aerbot::TeleopPeriodic(){
	executer->execute();
}

