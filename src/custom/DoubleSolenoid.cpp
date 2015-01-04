#include "DoubleSolenoid.h"

DoubleSolenoid::DoubleSolenoid(Relay* firstRelay, Relay* secondRelay){
	relay1 = firstRelay;
	relay2 = secondRelay;
}

DoubleSolenoid::~DoubleSolenoid(){
	Free();
}

void DoubleSolenoid::toggle(){
	if(defaultState){
		SetRelayValues(Relay.Value.kForward, Relay.Value.kOff);
	}else{
		SetRelayValues(Relay.Value.kOff, Relay.Value.kForward);
	}
	defaultState = !defaultState;
}

void DoubleSolenoid::SetRelayValues(Relay.Value value1, Relay.Value value2){
	relay1->Set(value1);
	relay2->Set(value2);
}

void MultiMotor::Free(){
	delete relay1;
	delete relay2;
}

bool MultiMotor::IsDefaultState(){
	return defaultState;
}

void MultiMotor::SetDefaultState(bool defaultState){
	this.defaultState = defaultState;
}
