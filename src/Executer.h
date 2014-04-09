#ifndef EXECUTER_H_
#define EXECUTER_H_

#include <vector>

#include "Environment.h"
#include "listeners/CompressorListener.h"

using std::vector;

class Executer {
private:
	vector<Listener*> listeners;
public:
	Executer(Environment* environment);
	~Executer();
	void update();
};

#endif /* EXECUTER_H_ */
