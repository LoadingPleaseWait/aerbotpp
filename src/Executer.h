#ifndef EXECUTER_H_
#define EXECUTER_H_

#include <vector>

class Listener;

class Executer {
private:
	std::vector<Listener*> listeners;
public:
	Executer(Environment* environment);
	virtual ~Executer();
	void update();
};

#endif /* EXECUTER_H_ */
