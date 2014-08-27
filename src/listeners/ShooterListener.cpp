#include "ShooterListener.h"

#include "../Environment.h"
#include "../systems/ShooterSystem.h"

ShooterListener::ShooterListener() {
	
}

ShooterListener::~ShooterListener() {

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

