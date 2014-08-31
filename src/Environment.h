#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

class RobotBase;
class InputMethod;
class IntakeSystem;
class ShooterSystem;
class WheelSystem;

class Environment {
private:
	RobotBase* robot;
	InputMethod* input;
	IntakeSystem* intake;
	ShooterSystem* shooter;
	WheelSystem* wheels;
public:
	Environment(RobotBase* bot);
	Environment();
	virtual ~Environment();
	virtual bool isAutonomous();
	virtual bool isOperatorControl();
	virtual InputMethod* getInput();
	virtual IntakeSystem* getIntakeSystem();
	virtual ShooterSystem* getShooterSystem();
	virtual WheelSystem* getWheelSystem();
};

#endif /* ENVIRONMENT_H_ */
