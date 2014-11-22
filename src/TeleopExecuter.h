#include <vector>
#include "Executer.h"

class TeleopExecuter: public Executer{
private:
	std::vector<RobotSystem*> systems;
public:
	TeleopExecuter();
	TeleopExecuter(Environment* env);
	virtual ~TeleopExecuter();
	void init(Environment* env);
	void execute();
};