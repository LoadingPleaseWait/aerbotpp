#ifndef WHEELSYSTEM_H
#define WHEELSYSTEM_H

#include "RobotSystem.h"
#include "../custom/RobotDrive3.h"
#include "../input/InputMethod.h"

#include <Relay.h>


class WheelSystem : public RobotSystem{
	// TODO add instance variables and other methods
public:
	WheelSystem();
	virtual ~WheelSystem();
	void init(Environment* env);
	void move(InputMethod* input);
	int  getGear();
	void gearsOff();
	void gearsReverse();
	void destroy();
	//void drive(double output_magnitude, double curve);
	void arcadeDrive(double move_value, double rotate_value);

	static const double KShift_delay = 0.5;
	static const double kShifting_speed = 1.8;
	static const double kRamping = 0.5;

protected:
	int setGear(int gear);
	double getCurrentLeftY();
	void setCurrentLeftY(double currentLeftY);

private:
	RobotDrive3 *wheels;

	Relay* gearbox;
	int gear; // off
	bool gear_press, dir_toggle;
	int dir;

	double current_left_y;
	double current_ramp_y;


};

#endif /* WHEELSYSTEM_H */
