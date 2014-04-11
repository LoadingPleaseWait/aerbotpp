/*
 * 
 */

#include "ShooterListener.h"

#include "../Environment.h"
#include "../systems/ShooterSystem.h"

ShooterListener::ShooterListener() {
	// TODO Auto-generated constructor stub

}

ShooterListener::~ShooterListener() {
	// TODO Auto-generated destructor stub
}

void ShooterListener::init(Environment* env){
	environment = env;
}

bool ShooterListener::shouldExecute(){
	return environment->isOperatorControl();
}

void ShooterListener::execute(){
	environment->getShooterSystem()->shoot(environment->getInput());
}

