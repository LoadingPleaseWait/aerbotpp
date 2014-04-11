/*
 * 
 */

#include "ShooterListener.h"

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

}

