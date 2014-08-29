/*
 * 
 */

#ifndef ROBOTDRIVE3_H
#define ROBOTDRIVE3_H

#include <RobotDrive.h>


class RobotDrive3: public RobotDrive {
public:
	RobotDrive3(int leftMotorChannel, int rightMotorChannel);
	virtual ~RobotDrive3();
	virtual void ArcadeDrive(double moveValue,double rotateValue);
	virtual void MecanumDrive(double yMovement, double xMovement, double rotation);
};

#endif /* ROBOTDRIVE3_H */
