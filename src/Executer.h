#ifndef EXECUTER_H_
#define EXECUTER_H_

#include <vector>

#include "listeners/Listener.h"

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
