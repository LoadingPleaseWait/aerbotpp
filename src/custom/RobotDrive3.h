/*
 * 
 */

#ifndef ROBOTDRIVE3_H_
#define ROBOTDRIVE3_H_

#include <RobotDrive.h>


class RobotDrive3: public RobotDrive {
public:
	RobotDrive3(int leftMotorChannel, int rightMotorChannel);
	virtual ~RobotDrive3();
	void ArcadeDrive(double moveValue,double rotateValue);
	void MecanumDrive(double yMovement, double xMovement, double rotation);
};

#endif /* ROBOTDRIVE3_H_ */
