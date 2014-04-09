/*
 * IntakeListener.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: MurpheyA
 */

#include "IntakeListener.h"

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

}

