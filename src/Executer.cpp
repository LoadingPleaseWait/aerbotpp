#include "Executer.h"

#include "listeners/AutonomousListener.h"
#include "listeners/CompressorListener.h"
#include "listeners/IntakeListener.h"
#include "listeners/ShooterListener.h"

Executer::Executer(Environment* environment) {
	// create and initialize listeners
	Listener* compressor = new CompressorListener();
	compressor->init(environment);
	Listener* shooter = new ShooterListener();
	shooter->init(environment);
	Listener* intake = new IntakeListener();
	intake->init(environment);
	AutonomousListener* auton = new AutonomousListener();
	auton->init(environment);

	listeners.push_back(compressor);
	listeners.push_back(auton);
	listeners.push_back(shooter);
	listeners.push_back(intake);
}

Executer::~Executer(){
	for(unsigned int i = 0; i < listeners.size(); i++)
		delete listeners.at(i);
}

void Executer::update(){
	for(unsigned int i = 0; i < listeners.size(); i++){
		Listener* listenItem = listeners.at(i);
		if(listenItem->shouldExecute())
			listenItem->execute();
	}
}

