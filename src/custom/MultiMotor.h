#ifndef MULTIMOTOR_H_
#define MULTIMOTOR_H_

#include <SpeedController.h>
#include <SensorBase.h>

class MultiMotor: public SpeedController, SensorBase {
private:
	SpeedController** motors;
	int motorCount;

public:
	MultiMotor(SpeedController** speedControllers, int length);
	virtual ~MultiMotor();
	virtual void PIDWrite(float output);
	virtual void Disable();
	virtual float Get();
	virtual void Set(float speed);
	virtual void Set(float speed, uint8_t syncGroup);
	virtual void Free();
};

#endif /* MULTIMOTOR_H_ */
