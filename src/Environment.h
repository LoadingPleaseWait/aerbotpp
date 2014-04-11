#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

class InputMethod;
class IntakeSystem;
class RobotBase;
class ShooterSystem;

class Environment {
private:
	RobotBase* robot;
	InputMethod* input;
	IntakeSystem* intake;
	ShooterSystem* shooter;
public:
	Environment(RobotBase* bot);
	Environment();
	virtual ~Environment();
	virtual bool isAutonomous();
	virtual bool isOperatorControl();
	virtual InputMethod* getInput();
	virtual IntakeSystem* getIntakeSystem();
	virtual ShooterSystem* getShooterSystem();
};

#endif /* ENVIRONMENT_H_ */
