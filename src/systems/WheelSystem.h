#ifndef WHEELSYSTEM_H_
#define WHEELSYSTEM_H_

#include "RobotSystem.h"
#include "../custom/RobotDrive3.h"
#include "../input/InputMethod"

#include <Relay.h>


class InputMethod;

class WheelSystem : public RobotSystem{

public:
	WheelSystem();
	virtual ~WheelSystem();
	void init(Environment* env);
	void move(InputMethod* input);
	int getGear();
	void gearsOff();
	void gearsReverse();
	void destroy();
	void drive(double output_magnitude, double curve);
	void arcadeDrive(double move_value, double rotate_value);

	static const double KShift_delay = 0.5;
	static double Kp = 0.8;
	static double Ki = 0.0;
	static double Kd = 0.0;
	static const double kShifting_speed = 1.8;
	static const double kRamping = 0.5;

protected:
	int setGear(int gear);
	double getCurrentLeftY();
	void setCurrentLeftY(double currentLeftY);

private:
	RobotDrive3 *wheels;

	Relay* gearbox;
	int gear = 0; // off
	bool gear_press = false, dir_toggle = false;
	int dir = 1;

	double current_left_y = 0;
	double current_ramp_y = 0;


};

#endif /* WHEELSYSTEM_H_ */
