#ifndef INITIALIZABLE_H_
#define INITIALIZABLE_H_

#include "Environment.h"

class Initializable{
public:
	virtual void init(Environment* environment) =0;
};

#endif

