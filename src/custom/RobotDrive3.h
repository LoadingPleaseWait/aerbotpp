/*
 * 
 */

#ifndef ROBOTDRIVE3_H_
#define ROBOTDRIVE3_H_

#include <RobotDrive.h>

double max(double,double);
double min(double,double);

class RobotDrive3: public RobotDrive {
public:
	RobotDrive3(int leftMotorChannel, int rightMotorChannel);
	virtual ~RobotDrive3();
	virtual void ArcadeDrive(double moveValue,double rotateValue);
	virtual void MecanumDrive(double yMovement, double xMovement, double rotation);
};

#endif /* ROBOTDRIVE3_H_ */
