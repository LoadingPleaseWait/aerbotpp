#ifndef COMPRESSORLISTENER_H_
#define COMPRESSORLISTENER_H_

#include "../Environment.h"
#include "Listener.h"

class Compressor;

class CompressorListener: public Listener {
private:
	Compressor* compressor;
public:
	CompressorListener();
	virtual ~CompressorListener();
	virtual void init(Environment* environment);
	virtual bool shouldExecute();
	virtual void execute();
};

#endif /* COMPRESSORLISTENER_H_ */
