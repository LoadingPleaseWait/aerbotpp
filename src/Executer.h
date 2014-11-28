#ifndef EXECUTER_H_
#define EXECUTER_H_

#include "Initializable.h"

class Executer: public Initializable {
public:
	virtual void execute() =0;
};

#endif /* EXECUTER_H_ */
