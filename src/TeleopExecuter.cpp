#include "TeleopExecuter.h"

#include "systems/IntakeSystem.h"
#include "systems/WheelSystem.h"
#include "systems/ShooterSystem.h"

TeleopExecuter::TeleopExecuter() {

}

TeleopExecuter::TeleopExecuter(Environment* env) {
	init(env);
}

TeleopExecuter::~TeleopExecuter() {
	for(unsigned int i = 0; i < systems.size(); i++)
		delete systems.at(i);
}

void TeleopExecuter::init(Environment* env){
	systems.push_back(env->getWheelSystem());
	systems.push_back(env->getIntakeSystem());
	systems.push_back(env->getShooterSystem());
}

void TeleopExecuter::execute(){
	for(unsigned int i = 0; i < systems.size(); i++){
		RobotSystem* system = systems.at(i);
		system->run();
	}
}

