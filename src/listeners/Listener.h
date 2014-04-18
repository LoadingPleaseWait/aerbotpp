#ifndef LISTENER_H_
#define LISTENER_H_

class Environment;

class Listener {
public:
	virtual ~Listener();
	virtual void init(Environment*) =0;
	virtual bool shouldExecute(void) =0;
	virtual void execute(void) =0;
};

#endif
