#ifndef DOUBLESOLENOID_H_
#define DOUBLESOLENOID_H_

#include <SensorBase.h>
#include <Relay.h>

class DoubleSolenoid: public SensorBase {
private:
	Relay* relay1, relay2;
	bool defaultState;

public:
	DoubleSolenoid(Relay* firstRelay, Relay* secondRelay);
	virtual ~DoubleSolenoid();
	virtual void Toggle();
	virtual void SetRelayValues(Relay::Value value1, Relay::Value value2);
	virtual void Free();
	virtual bool IsDefaultState();

protected:
	virtual void SetDefaultState(bool defaultState);
};

#endif /* DOUBLESOLENOID_H_ */
