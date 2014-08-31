#include "IntakeListener.h"

#include "../Environment.h"
#include "../systems/IntakeSystem.h"

IntakeListener::IntakeListener() {

}

IntakeListener::~IntakeListener() {

}

void IntakeListener::init(Environment* env){
	environment = env;
}

bool IntakeListener::shouldExecute(){
	return environment->isOperatorControl();
}

void IntakeListener::execute(){
	environment->getIntakeSystem()->intake(environment->getInput());
}

