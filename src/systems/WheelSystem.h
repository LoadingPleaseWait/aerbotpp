#ifndef WHEELSYSTEM_H_
#define WHEELSYSTEM_H_

#include "RobotSystem.h"

class InputMethod;
class RobotDrive3;
class Relay;

class WheelSystem : public RobotSystem{

public:
	WheelSystem();
	virtual ~WheelSystem();
	void init(Environment* env);
	void run();
	void move(InputMethod* input);
	int  getGear();
	void gearsOff();
	void gearsReverse();
	void destroy();
	void arcadeDrive(double move_value, double rotate_value);

	static const double kShiftDelay = 0.5;
	static const double kShiftingSpeed = 1.8;
	static const double kRamping = 0.5;

protected:
	int setGear(int gear);
	double getCurrentLeftY();
	void setCurrentLeftY(double currentLeftY);

private:
	RobotDrive3 *wheels;
	InputMethod* inputMethod;

	Relay* gearbox;
	int gear; // off
	bool gear_press, dir_toggle;
	int dir;

	double current_left_y;
	double current_ramp_y;


};

#endif /* WHEELSYSTEM_H_ */
