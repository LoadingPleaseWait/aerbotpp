#include "Executer.h"

Executer::Executer(Environment* environment) {
	Listener* compressor = new CompressorListener();
	compressor->init(*environment);
	listeners.push_back(compressor);
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

