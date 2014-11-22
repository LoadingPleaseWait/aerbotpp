#ifndef EXECUTER_H_
#define EXECUTER_H_

class Environment;

class Executer: public Initializable {
public:
	void execute() =0;
};

#endif /* EXECUTER_H_ */
