#include "DoubleSolenoid.h"

DoubleSolenoid::DoubleSolenoid(Relay* firstRelay, Relay* secondRelay){
	relay1 = firstRelay;
	relay2 = secondRelay;
}

DoubleSolenoid::~DoubleSolenoid(){
	Free();
}

void DoubleSolenoid::Toggle(){
	if(defaultState){
		SetRelayValues(Relay::kForward, Relay::kOff);
	}else{
		SetRelayValues(Relay::kOff, Relay::kForward);
	}
	defaultState = !defaultState;
}

void DoubleSolenoid::SetRelayValues(Relay::Value value1, Relay::Value value2){
	relay1->Set(value1);
	relay2->Set(value2);
}

void DoubleSolenoid::Free(){
	delete relay1;
	delete relay2;
}

bool DoubleSolenoid::IsDefaultState(){
	return defaultState;
}

void DoubleSolenoid::SetDefaultState(bool state){
	defaultState = state;
}
