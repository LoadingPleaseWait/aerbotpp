#include "MovementListener.h"

#include "../Environment.h"
#include "../systems/WheelSystem.h"

MovementListener::MovementListener() {

}

MovementListener::~MovementListener() {

}

void MovementListener::init(Environment* env){
	environment = env;
}

bool MovementListener::shouldExecute(){
	return environment->isOperatorControl();
}

void MovementListener::execute(){
	environment->getWheelSystem()->move(environment->getInput());
}

